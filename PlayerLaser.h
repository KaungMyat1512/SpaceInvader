#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"Laser.h"


/*
name:			PlayerLaser
Description:	This class represents the laser shooting from the player; 
*/
class PlayerLaser : public Laser
{
public:
	PlayerLaser(float og_x, float og_y, float dir_x, float dir_y, float speed, sf::Color newColor) : Laser(og_x, og_y, speed, newColor)
	{
		this->direction.x = dir_x;
		this->direction.y = dir_y;
	}
	/******************************************************************************************************
	* Function:				PlayerLaser()
	* Description:			constructor for playerLaser class: this will set up the player's laser
	* Input parameters:		float type laser's position, direction where the laser is going, speed, and color: 
	* Returns:				Nothing
	*******************************************************************************************************/
	void move();
	/******************************************************************************************************
	* Function:				move()
	* Description:			move function: this function will move the laser within the window
	* Input parameters:		Nothing
	* Returns:				Nothing
	*******************************************************************************************************/

	void render(sf::RenderWindow& window);
	/******************************************************************************************************
	* Function:				render()
	* Description:			this function will draw the laser shape within window. 
	* Input parameters:		render window
	* Returns:				Nothing
	*******************************************************************************************************/
	sf::FloatRect laser_boundary(); 
	/******************************************************************************************************
	* Function:				laser_boundary()
	* Description:			this function will return the laser's boundary in the window
	* Input parameters:		Nothing
	* Returns:				FloatRect type Laser's position within window. 
	*******************************************************************************************************/
	int getType(); 
	/******************************************************************************************************
	* Function:				getType()
	* Description:			this function will return the laser's type
	* Input parameters:		Nothing
	* Returns:				int value: representing the player laser: 1. 
	*******************************************************************************************************/
private:
	sf::Vector2f direction;

};

