// Rain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "SFML\Graphics.hpp"
#include "SFML\OpenGL.hpp"
#include <ctime>

const int ScreenX = 800;
const int ScreenY = 600;

int main()
{
	sf::RenderWindow window(sf::VideoMode(ScreenX, ScreenY), "SFML works!", sf::Style::Default);
	window.setVerticalSyncEnabled(true);

	window.setActive(true);

	std::vector<sf::RectangleShape> rectangles;
	std::srand(std::time(0));
	for (int i = 0; i < 100; i++) {
		rectangles.push_back(sf::RectangleShape(sf::Vector2f((rand()%15)/10.f+1,(rand()%500)/10.f+3)));
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
						rectangles.push_back(sf::RectangleShape(sf::Vector2f((rand() % 15) / 10.f + 1, (rand() % 500) / 10.f + 8)));
						rectangles[rectangles.size()-1].setPosition(sf::Vector2f(rand() % 800, rand() % 600));
					}
					else if (event.key.code == sf::Keyboard::Left) {
						if(rectangles.size()>0)
							rectangles.pop_back();
					}
					break;
			}
		}
		window.clear(sf::Color::Black);

		for (int i = 0; i < rectangles.size(); i++) {
			if (rectangles[i].getPosition().y <= ScreenY)
				rectangles[i].setPosition(rectangles[i].getPosition().x, rectangles[i].getPosition().y + 2);
			else {
				rectangles[i].setPosition(rectangles[i].getPosition().x, -40);
			}
		}

		for (int i = 0; i < rectangles.size(); i++) {
			window.draw(rectangles[i]);
		}

		window.display();
	}


    return 0;
}

