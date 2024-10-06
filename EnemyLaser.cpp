#include "EnemyLaser.h"

void EnemyLaser::move()
{
	this->shape.move(this->direction * this->movementSpeed); 
}

void EnemyLaser::render(sf::RenderWindow& window)
{
	window.draw(this->shape); 
}

sf::FloatRect EnemyLaser::laser_boundary()
{
	return shape.getGlobalBounds();
}

int EnemyLaser::getType()
{
	return 2;//2 refer to the enemyLaser; 
}
