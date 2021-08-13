/*#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>

int main() {
	//Create window
	sf::RenderWindow window(sf::VideoMode(800, 600), "First Application");
	 // Writing Text and selection font
	sf::Font font;
	if (!font.loadFromFile("Roboto-Medium.ttf"))
	{
		return EXIT_FAILURE;
	}
	sf::Text text;
	text.setFont(font);
	text.setString("Hello First Text");
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold || sf::Text::Underlined);
	// Creating Shapes
	// Creating Circle
	sf::CircleShape circle(50.f);
	circle.setFillColor(sf::Color::Red);
	// creating Reactangle
	sf::RectangleShape reactangle(sf::Vector2f(120.f, 50.f));
	reactangle.setFillColor(sf::Color::Green);
	reactangle.setPosition(20.f, 150.f);
	// Loading Sound Effect
	sf::Music  music;
	if (!music.openFromFile("sound.ogg"))
	{
		return EXIT_FAILURE;
	}
	// Run Program as window as open
	while (window.isOpen())
	{
		//Check all the window's event that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		//Moving Shapes
		//Moving Circle
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			circle.move(1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			circle.move(-1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			circle.move(0.f, -1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			circle.move(0.f, 1.f);
		}
		//Sound play on mouse button clicked
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			music.play();
		}
		//close window when press Escape key
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
			return EXIT_SUCCESS;
		}
		// clear the all window with black
		window.clear(sf::Color::Black);
		//Draw here
		window.draw(text);
		window.draw(circle);
		window.draw(reactangle);
		//end of current frame
		window.display();
	}
	return EXIT_SUCCESS;
}
*/