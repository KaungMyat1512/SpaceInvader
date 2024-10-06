#include"Laser.h"



Laser::Laser(float og_x, float og_y, float speed, sf::Color color)
{
	this->shape.setPosition(og_x, og_y); 
	this->shape.setSize(sf::Vector2f(10.f, 20.f)); //size need to get increase for visually clear
	this->shape.setFillColor(color); 
	this->movementSpeed = speed; //update the speed; 
}

bool Laser::is_in_screen() const
{
	bool yes = true;
	if (this->shape.getPosition().x + this->shape.getSize().x < 0 ||
		this->shape.getPosition().x > 1000 ||
		this->shape.getPosition().y + this->shape.getSize().y < 0 ||
		this->shape.getPosition().y > 900)
	{
		yes = false;

	}
	return yes;
	//presume we have to change the 
}




