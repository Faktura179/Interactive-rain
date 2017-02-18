// Rain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "SFML\Graphics.hpp"
#include "SFML\OpenGL.hpp"
#include <ctime>


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default);
	window.setVerticalSyncEnabled(true);

	window.setActive(true);

	std::vector<sf::RectangleShape> rectangles;
	std::srand(std::time(0));
	for (int i = 0; i < 100; i++) {
		rectangles.push_back(sf::RectangleShape(sf::Vector2f((rand()%15)/10.f+1,(rand()%200)/10.f+3)));
		rectangles[i].setPosition(sf::Vector2f(rand()%800,rand()%600));
	}

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

				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Right) {
						rectangles.push_back(sf::RectangleShape(sf::Vector2f((rand() % 15) / 10.f + 1, (rand() % 600) / 10.f + 8)));
					}
					else if (event.key.code == sf::Keyboard::Left) {
						rectangles.pop_back();
					}
					break;
			}
			window.clear(sf::Color::Black);

			/*for (int i = 0; i < rectangles.size(); i++) {
				if(rectangles[i].getPosition())
				rectangles[i].move();
			}*/

			for (int i = 0; i < rectangles.size(); i++) {
				window.draw(rectangles[i]);
			}
			
			window.display();
		}

		
		window.display();
	}


    return 0;
}

