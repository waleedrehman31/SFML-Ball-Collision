#include "Ball.h"

Ball::Ball(float radius) : dragged(false), mass(radius * 20.f), circleShape(sf::CircleShape(radius))
{
	circleShape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	circleShape.setOrigin(radius, radius);
}

Ball::~Ball() {}

void Ball::update(float deltatime)
{
	setAcceleration(-getVelocity().x * 0.9f * deltatime, -getVelocity().y * 0.9f * deltatime);
	setVelocity(getVelocity().x + (getAcceleration().x), getVelocity().y + (getAcceleration().y));

	circleShape.move(getVelocity());
	if (getPosition().x < getRadius())
	{
		setPosition(getRadius(), getPosition().y);
		setVelocity(-getVelocity().x, getVelocity().y);
	}
	else if (getPosition().x > 1000 - getRadius()) {
		setPosition(1000 - getRadius(), getPosition().y);
		setVelocity(-getVelocity().x, getVelocity().y);
	}

	if (getPosition().y < getRadius()) {
		setPosition(getPosition().x, getRadius());
		setVelocity(getVelocity().x, -getVelocity().y);
	}
	else if (getPosition().y > 600 - getRadius()) {
		setPosition(getPosition().x, 600 - getRadius());
		setVelocity(getVelocity().x, -getVelocity().y);
	}
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(circleShape);
}

void Ball::setPosition(float x, float y)
{
	this->circleShape.setPosition(sf::Vector2f(x, y));
}

float Ball::getRadius() const
{
	return circleShape.getRadius();
}

sf::Vector2f Ball::getPosition() const
{
	return circleShape.getPosition();
}

void Ball::setVelocity(float x, float y)
{
	this->velocity = sf::Vector2f(x, y);
}

void Ball::setAcceleration(float x, float y)
{
	this->acceleration = sf::Vector2f(x, y);
}

void Ball::setDragged(bool dragged)
{
	this->dragged = dragged;
}

float Ball::getMass() const
{
	return mass;
}

float Ball::getDragged() const
{
	return dragged;
}

sf::Vector2f Ball::getVelocity() const 
{
	return velocity;
}

sf::Vector2f Ball::getAcceleration() const 
{
	return acceleration;
}