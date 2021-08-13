#include "World.h"

World::World()
{
	draggedBall = nullptr;
	initBalls(10);
}
World::~World()
{
	delete draggedBall;
}

void World::initBalls(size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		float x = (float)(rand() % 1000);
		float y = (float)(rand() % 600);
		float radius = (float)(15 + (rand() % (40 - 16)));

		Ball ball = Ball(radius);
		ball.setPosition(x, y);
		balls.push_back(ball);
	}
}

void World::update(float deltatime) 
{
	for (Ball& ball : balls)
	{
		ball.update(deltatime);
	}
}

void World::ballCollision() {
	for (Ball& ball : balls) {
		for (Ball& ball2 : balls) {

			if (&ball != &ball2) {
				if (collision.ballOverLap(ball, ball2)) {

					float distance = collision.distanceSquared(ball.getPosition(), ball2.getPosition());
					float distanceSquared = sqrtf(distance);
					float overlap = (distanceSquared - ball.getRadius() - ball2.getRadius()) / 2.f;

					float moveX = (overlap * (ball.getPosition().x - ball2.getPosition().x) / distanceSquared);
					float moveY = (overlap * (ball.getPosition().y - ball2.getPosition().y) / distanceSquared);

					ball.setPosition(ball.getPosition().x - moveX, ball.getPosition().y - moveY);
					ball2.setPosition(ball2.getPosition().x + moveX, ball2.getPosition().y + moveY);

					sf::Vector2f normal((ball2.getPosition().x - ball.getPosition().x) / distanceSquared, (ball2.getPosition().y - ball.getPosition().y) / distanceSquared);
					sf::Vector2f tangent(-normal.y, normal.x);

					float dotProductTangent1 = ball.getVelocity().x * tangent.x + ball.getVelocity().y * tangent.y;
					float dotProductTangent2 = ball2.getVelocity().x * tangent.x + ball2.getVelocity().y * tangent.y;

					float dotProductNormal1 = ball.getVelocity().x * normal.x + ball.getVelocity().y * normal.y;
					float dotProductNormal2 = ball2.getVelocity().x * normal.x + ball2.getVelocity().y * normal.y;

					float m1 = (dotProductNormal1 * (ball.getMass() - ball2.getMass()) + 2.0f * ball.getMass() * dotProductNormal2) / (ball.getMass() + ball2.getMass());
					float m2 = (dotProductNormal2 * (ball2.getMass() - ball.getMass()) + 2.0f * ball.getMass() * dotProductNormal1) / (ball.getMass() + ball2.getMass());

					ball.setVelocity(tangent.x * dotProductTangent1 + normal.x * m1, tangent.y * dotProductTangent1 + normal.y * m1);
					ball2.setVelocity(tangent.x * dotProductTangent2 + normal.x * m2, tangent.y * dotProductTangent2 + normal.y * m2);
				}
			}
		}
	}
}

bool World::dragBall(sf::Vector2f point)
{
	for (Ball& ball : balls)
	{
		if (collision.ballPointOverLap(sf::Vector2f(point.x, point.y), ball))
		{
			draggedBall = &ball;
			return true;
		}
	}
	return false;
}

void World::setDraggedVelocity(float x, float y) 
{
	if (draggedBall)
	{
		draggedBall->setVelocity((draggedBall->getPosition().x - x) / 100, (draggedBall->getPosition().y - y) / 100);
		draggedBall = nullptr;
	}
}

Ball* World::getDraggedBall() const
{
	return draggedBall;
}

std::vector<Ball> World::getBalls() const
{
	return balls;
}
 