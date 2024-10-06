#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"

class Enemy
{
public:

	/*************************************************************
	* Function: Enemy()								            *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: This is a default constructor of the Enemy	*
	*				Class										*
	*															*
	* Input parameters: x and y floating point				    *
	* Returns:													*
	*************************************************************/
	Enemy(float og_x, float og_y)
	{
		this->shape.setPosition(og_x, og_y);
		this->shape.setFillColor(sf::Color::White);
		this->shape.setSize(sf::Vector2f(100.f, 25.f));
		this->velocity = static_cast<float>(rand() % 5 + 1);

	}


	/*************************************************************
	* Function: ~Enemy()								        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: This is a destructor of the Enemy			*
	*				Class										*
	*															*
	* Input parameters:										    *
	* Returns:													*
	*************************************************************/
	~Enemy();

	/*************************************************************
	* Function: move_enemy()							        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: This moves the enemy or shape that define as	*
	*	enemy moving at different velocity down the screen.		*
	*															*
	* Input parameters:										    *
	* Returns:													*
	*************************************************************/
	void move_enemy();

	/*************************************************************
	* Function: render()								        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: This draws the enemy to the window			*
	*															*
	* Input parameters:	RenderWinow								*
	* Returns: creates window.draw() enemy						*
	*************************************************************/
	void render(sf::RenderWindow& window);


	/*************************************************************
	* Function: touches_bottom()						        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: detects whether if the enemy position has	*
	*		reach the bottom of the screen						*
	*															*
	* Input parameters:											*
	* Returns: 													*
	*************************************************************/
	bool touches_bottom();

	/*************************************************************
	* Function: enemy_boundary()							    *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: This gets the enemys shape boundaries		*
	*															*
	* Input parameters:											*
	* Returns:	The float value of the rectangle				*
	*************************************************************/
	sf::FloatRect enemy_boundary();

private:

	sf::RectangleShape shape;
	float velocity;

};
