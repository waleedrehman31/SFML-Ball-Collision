#pragma once
#ifndef COLLISION_H
#define COLLISION_H
#include <SFML/Graphics.hpp>
#include "Ball.h"

class Collision {
public:
	Collision() {}
	~Collision() {}

	bool ballOverLap(Ball ball, Ball ball2);
	bool ballPointOverLap(sf::Vector2f point, Ball ball);
	float distanceSquared(sf::Vector2f a, sf::Vector2f b);
};

#endif // !COLLISION_H
