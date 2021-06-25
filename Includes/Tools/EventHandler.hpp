/*
 * EventHandler.hpp
 *
 *  Created on: 4 апр. 2021 г.
 *      Author: mayor
 */
#pragma once

#include <list>
#include <queue>
#include <shared_mutex>
#include <cassert>
#include <mutex>

#include <iostream>

template<class ...TParams>
class AbstractEventHandler {
    using MyType = AbstractEventHandler<TParams...>;
    public:
        virtual void call(TParams... params) = 0;

        bool operator==(const MyType& other) const {
            return isEquals(other);
        }

        bool operator!=(const MyType& other) const {
            return !(*this == other);
        }
//        virtual ~AbstractEventHandler() {}
        virtual ~AbstractEventHandler() {
//        	std::cerr << "Deleted absEventHandler" << std::endl;
        }
    protected:
        virtual bool isEquals( const MyType& other ) const = 0;

        AbstractEventHandler() {}

};

template<class ...TParams>
class TEvent {
    using TEventHandler = AbstractEventHandler<TParams...>;
    using TEventHandlerIt = typename std::list<TEventHandler*>::const_iterator;
    private:
        std::list<TEventHandler*> m_handlers;

        mutable TEventHandlerIt m_currentIt;
        mutable bool m_isCurrentItRemoved;

        mutable std::shared_mutex m_handlerListMutex;

        inline TEventHandlerIt findEventHandler(const TEventHandler& eventHandler) const {
            return std::find_if(m_handlers.cbegin(), m_handlers.cend(), [&eventHandler] (const TEventHandler* handler) {
            	return (*handler == eventHandler);
            });
        }

        inline void deleteHandler(TEventHandlerIt it) {
            TEventHandler* removedEventHandler = *it;
            m_handlers.erase(it);
            delete removedEventHandler;
        }
    public:
        TEvent() :
            m_handlers(),
            m_currentIt(),
            m_isCurrentItRemoved(false),
            m_handlerListMutex()
        {}

        void operator()(TParams... params) {
            m_handlerListMutex.lock_shared();

            m_isCurrentItRemoved = false;
            m_currentIt = m_handlers.begin();

            while(m_currentIt != m_handlers.end()) {
                m_handlerListMutex.unlock_shared();
                (*m_currentIt)->call(params...);
                m_handlerListMutex.lock_shared();


                if( m_isCurrentItRemoved )
                {
                    m_isCurrentItRemoved = false;

                    TEventHandlerIt removedIt = m_currentIt;
                    ++m_currentIt;

                    deleteHandler(removedIt);
                }
                else
                {
                    ++m_currentIt;
                }
            }

            m_handlerListMutex.unlock_shared();
        }

        bool operator+=(TEventHandler& eventHandler) {
            std::unique_lock<std::shared_mutex> _handlerListMutexLock(m_handlerListMutex);

            if(findEventHandler(eventHandler) == m_handlers.end()) {
                m_handlers.push_back(&eventHandler);
                return true;
            }
            return false;
        }

        bool operator-=(const TEventHandler& eventHandler) {
            std::unique_lock<std::shared_mutex> _handlerListMutexLock(m_handlerListMutex);

            auto it = findEventHandler(eventHandler);
            if(it != m_handlers.end())
            {
                if(it == m_currentIt)
                    m_isCurrentItRemoved = true;
                else
                    deleteHandler(it);

                return true;
            }
            return false;
        }

        ~TEvent() {
            for(TEventHandler* oneHandler : m_handlers)
                delete oneHandler;
            m_handlers.clear();
        }
};

template<class TObject, class ...TParams>
class MethodEventHandler : public AbstractEventHandler<TParams...> {
    using TMethod = void( TObject::* )( TParams... );
    using MyType = MethodEventHandler<TObject, TParams...>;
    private:
        TObject& m_object;
        TMethod m_method;
    public:
        MethodEventHandler( TObject& object, TMethod method ) :
            AbstractEventHandler<TParams...>(),
            m_object( object ),
            m_method( method )
        {
            assert( m_method != nullptr );
        }
        virtual void call( TParams... params ) override final {
            ( m_object.*m_method )( params... );
        }
    protected:
        virtual bool isEquals( const AbstractEventHandler<TParams...>& other ) const override {
			const MyType* _other = dynamic_cast<const MyType*>( &other );
			return ( _other != nullptr && &m_object == &_other->m_object && m_method == _other->m_method );
		}
};

template<class TObject, class ...TParams>
AbstractEventHandler<TParams...>& createMethodEventHandler( TObject& object, void( TObject::*method )( TParams... ) )
{
    return *new MethodEventHandler<TObject, TParams...>( object, method );
};

#define METHOD_HANDLER( Object, Method ) createMethodEventHandler( Object, &Method )
#define MY_METHOD_HANDLER( Method ) METHOD_HANDLER( *this, Method )
