#include "WorldRender.h"

WorldRender::WorldRender(World& world) : world(world) {}

WorldRender::~WorldRender() {}

void WorldRender::render(sf::RenderWindow& window) const
{
	renderBalls(window);
}

void WorldRender::renderBalls(sf::RenderWindow& window) const
{
	for (Ball ball : world.getBalls())
	{
		ball.draw(window);	
	}
}