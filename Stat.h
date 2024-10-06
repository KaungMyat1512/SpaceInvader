#pragma once
#include<iostream>
#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"



/*
name:			Stat
Description:	This class represents the single health representing the player's health during game
*/
class Stat
{
public: 
	Stat(float i);  
	/******************************************************************************************************
	* Function:				Stat()
	* Description:			constructor for Stat class: create the shape
	* Input parameters:		float 
	* Returns:				Nothing
	*******************************************************************************************************/
	void render(sf::RenderWindow& window); 
	/******************************************************************************************************
	* Function:				render()
	* Description:			this function will draw the shape on window
	* Input parameters:		window we want to draw
	* Returns:				Nothing
	*******************************************************************************************************/
private: 
	sf::CircleShape shape; 
	
};