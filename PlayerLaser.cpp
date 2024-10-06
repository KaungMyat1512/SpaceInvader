#include "PlayerLaser.h"

void PlayerLaser::move()
{
	this->shape.move(this->direction * this->movementSpeed);
}

void PlayerLaser::render(sf::RenderWindow& window)
{
	window.draw(this->shape);
}

sf::FloatRect PlayerLaser::laser_boundary()
{
	return shape.getGlobalBounds(); 
}

int PlayerLaser::getType()
{
	return 1;
}
