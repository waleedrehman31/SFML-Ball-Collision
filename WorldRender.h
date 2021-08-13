#pragma once
#ifndef WORLDRENDER_H
#define WORLDRENDER_H
#include <SFML/Graphics.hpp>
#include "World.h"

class WorldRender
{
public:
	WorldRender(World& world);
	~WorldRender();
	void render(sf::RenderWindow& window) const;
	void renderBalls(sf::RenderWindow& window) const;
private:
	World& world;
};

#endif // !WORLDRENDER_H

