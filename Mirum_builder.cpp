#include <cstdlib>
#include <iomanip>

#include <set>
#include <iostream>
#include <chrono>

#include "Includes/General/Settings/User.hpp"

#include "Includes/Tools/EventHandler.hpp"
#include "Includes/General/Init.hpp"
#include "Includes/General/EventManager.hpp"
#include "Includes/General/GlobalVariables.hpp"
#include "Includes/General/RenderFrame.hpp"
#include "Includes/General/EventManager.hpp"
#include "Includes/UI/All.hpp"
#include "Includes/UI/Functions/Drawing.hpp"
#include "Includes/UI/Functions/Scale.hpp"

#ifdef DEBUG
#include "Includes/Tools/Tests.hpp"
#endif

#include "Includes/UI/Objects/Menu.hpp"


void renderLoop() {
	static UI::FPS _fps;

    while(window.isOpen()) {

        EventManager::processEvents();

        _fps.start();

        renderFrame(window);

		window.draw(_fps);

        window.display();
    }
}


int main() {
#ifdef DEBUG
	Tests::All();

	std::cerr << std::fixed;
	std::cerr << std::setprecision(5);
#endif

	init();
	window.setFramerateLimit(60);
	renderLoop();

	return EXIT_SUCCESS;
}
