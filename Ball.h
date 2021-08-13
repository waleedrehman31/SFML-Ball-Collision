#pragma once
#ifndef  BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(float radius);
	~Ball();

	void update(float deltatime);
	void draw(sf::RenderWindow& window);

	void setPosition(float x, float y);
	void setVelocity(float x, float y);
	void setAcceleration(float x, float y);
	void setDragged(bool dragged);

	sf::Vector2f getVelocity() const;
	sf::Vector2f getAcceleration() const;
	float getMass() const;
	float getDragged() const;
	float getRadius() const;
	sf::Vector2f getPosition() const;

private:
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::CircleShape  circleShape;
	bool dragged;
	float mass;
};

#endif