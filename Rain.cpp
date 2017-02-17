// Rain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML\OpenGL.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default);
	window.setVerticalSyncEnabled(true);

	window.setActive(true);




	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {

				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::Resized:
					// adjust the viewport when the window is resized
					glViewport(0, 0, event.size.width, event.size.height);
					break;
			}
			window.clear(sf::Color::Black);
			
			window.display();
		}

		
		window.display();
	}


    return 0;
}

