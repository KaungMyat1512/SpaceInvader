#include "Player.h"

Player::Player(float pos_x, float pos_y)
{
	this->shape.setPosition(pos_x, pos_y);//this should be in the middle of the screen; 
	this->shape.setFillColor(sf::Color::Blue);
	this->shape.setSize(sf::Vector2f(22.f, 25.f));//set up the position; 
	this->health = 5;//5 hit points; 
	this->speed = 100.f;
	this->position.x = pos_x + 12.f; //the left end corner + the middle of the ship: 
	//thus middle place is justifiedl 
	this->position.y = pos_y;
	
}

Player::~Player()
{
	
}

void Player::move_player(float x, float y)
{
	this->shape.move(x,y); //  
	this->position.x = x;
	this->position.y = y;

}

void Player::render(sf::RenderWindow&target)
{
	target.draw(this->shape);
}

const sf::Vector2f& Player::getPosition()
{
	return this->shape.getPosition();
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->shape.setPosition(pos);
}

sf::FloatRect Player::player_boundary()
{
	
	return shape.getGlobalBounds();//this will return the boundary
	
}



