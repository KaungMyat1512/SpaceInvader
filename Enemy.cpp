#include"Enemy.h"

Enemy::~Enemy()
{

}

void Enemy::move_enemy()
{
	this->shape.move(0.1f, this->velocity); //this will move the ship 
}

void Enemy::render(sf::RenderWindow& window)
{
	window.draw(this->shape); 
}

bool Enemy::touches_bottom()//will return yes if touches the bottom
{
	return this->shape.getPosition().y + this->shape.getSize().y >= 900;
}

sf::FloatRect Enemy::enemy_boundary()
{
	return shape.getGlobalBounds();//this will return the boundary
}
