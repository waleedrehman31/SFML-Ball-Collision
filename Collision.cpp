#include "Collision.h"

bool Collision::ballOverLap(Ball ball1, Ball ball2)
{
	float distance = distanceSquared(ball1.getPosition(), ball2.getPosition());
	float radiusSum = ball1.getRadius() + ball2.getRadius();
	return distance <= radiusSum * radiusSum;
}

bool Collision::ballPointOverLap(sf::Vector2f point, Ball ball)
{
	float distance = distanceSquared(ball.getPosition(), point);
	return distance <= ball.getRadius() * ball.getRadius();
}

float Collision::distanceSquared(sf::Vector2f a, sf::Vector2f b)
{
	float distX = a.x - b.x;
	float distY = a.y - b.y;
	return distX * distX + distY * distY;
}