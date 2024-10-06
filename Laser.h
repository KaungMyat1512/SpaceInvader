#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"

/*
name:			Laser
Description:	This class represents the base class Laser where both player and enemy will inherit
*/
class Laser
{
public: 

	Laser(float og_x, float og_y, float speed, sf::Color color); 
	/******************************************************************************************************
	* Function:				Laser()
	* Description:			constructor for Laser class: create the laser shape
	* Input parameters:		the origin of the laser, color of the laser and speed of the laser
	* Returns:				Nothing
	*******************************************************************************************************/

	virtual void move()=0; 
	/******************************************************************************************************
	* Function:				move()
	* Description:			virtual move function: which the derived class will override
	* Input parameters:		Nothing
	* Returns:				Nothing
	*******************************************************************************************************/
	virtual void render(sf::RenderWindow& window)=0; 
	/******************************************************************************************************
	* Function:				render()
	* Description:			virtual render function: which the derived class will override
	* Input parameters:		Nothing
	* Returns:				Nothing
	*******************************************************************************************************/

	bool is_in_screen() const;
	/******************************************************************************************************
	* Function:				is_in_screen()
	* Description:			this function will test whether the laser is in the window's boundary
	* Input parameters:		Nothing
	* Returns:				bool 
	*******************************************************************************************************/

	virtual sf::FloatRect laser_boundary()=0;
	/******************************************************************************************************
	* Function:				laser_boundary()
	* Description:			virtual laser_boundary function: which the derived class will override
	* Input parameters:		Nothing
	* Returns:				FloatRect type representing the laser's position in the window
	*******************************************************************************************************/
	virtual int getType() = 0; 
	/******************************************************************************************************
	* Function:				getType()
	* Description:			virtual getType function: which the derived class will override
	* Input parameters:		Nothing
	* Returns:				int value representing the type of laser: Enemy's or Player's
	*******************************************************************************************************/
protected:  
	sf::RectangleShape shape;//for storing the shape: 
	
	float movementSpeed;//this is the frame rate that the laser is moving 
};