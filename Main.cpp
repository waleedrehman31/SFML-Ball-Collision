#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "World.h"
#include "Ball.h"
#include <vector>
#include <time.h>
#include "WorldRender.h"
int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Ball Physics Simulator");

	srand((unsigned)(time(NULL)));

	World world;
	WorldRender worldRenderer(world);

	sf::Vertex line[] = { sf::Vertex(sf::Vector2f(-1, -1)), sf::Vertex(sf::Vector2f(-1, -1)) };

	bool dragging = false;

	float deltatime = 0.f;
	sf::Clock clock;

	while (window.isOpen()) {
		sf::Event event;

		deltatime = clock.restart().asSeconds();

		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {

					sf::Vector2i point = sf::Mouse::getPosition(window);

					if (world.dragBall(sf::Vector2f((float)point.x, (float)point.y))) {
						dragging = true;
					}
				}
				break;

			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left) {

					world.setDraggedVelocity(line[1].position.x, line[1].position.y);

					dragging = false;
				}
				break;
			}
		}

		if (dragging) {
			sf::Vector2i point = sf::Mouse::getPosition(window);

			line[0] = sf::Vertex(sf::Vector2f(world.getDraggedBall()->getPosition()), sf::Color::Blue);
			line[1] = sf::Vertex(sf::Vector2f((float)point.x, (float)point.y), sf::Color::Blue);
		}

		world.update(deltatime);

		window.clear(sf::Color::White);
		worldRenderer.render(window);

		if (dragging) {
			window.draw(line, 2, sf::Lines);
		}
		window.display();

	}

	return 0;
}