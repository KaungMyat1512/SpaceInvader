#include "Stat.h"

Stat::Stat(float i)
{
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setRadius(1.0f);
	this->shape.setScale(sf::Vector2f(10.f, 10.f)); 
	this->shape.setPosition(i, 2.f); 
}

void Stat::render(sf::RenderWindow& window)
{
	window.draw(this->shape); //we have drawn the bar
}
