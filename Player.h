#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"

class Player
{
public:


	/*************************************************************
	* Function: Player()								        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: This is a default constructor of the player	*
	*				Class										*
	*															*
	* Input parameters: x and y floating point				    *
	* Returns:													*
	*************************************************************/
	Player(float pos_x, float pos_y);


	/*************************************************************
	* Function: ~Player()								        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: This is a default destructor of the player	*
	*				Class										*
	*															*
	* Input parameters:										    *
	* Returns:													*
	*************************************************************/
	~Player();


	/*************************************************************
	* Function: move_player()							        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: Takes in two float value to move the player 	*
	*		from current position then add or sub the position	*
	*															*
	* Input parameters: x and y floating point				    *
	* Returns:													*
	*************************************************************/
	void move_player(float x, float y); //accept the coordi


	/*************************************************************
	* Function: render()								        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: renders the player on the screen or draw 	*
	*															*
	*															*
	* Input parameters: Renderwindow						    *
	* Returns:	draws the player								*
	*************************************************************/
	void render(sf::RenderWindow& target);

	/*************************************************************
	* Function: getPosition()							        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: get position of the player					*
	*															*
	* Input parameters:										    *
	* Returns:	x and y floating point							*
	*************************************************************/
	const sf::Vector2f& getPosition();

	/*************************************************************
	* Function: setPosition()							        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: set position of the player					*
	*															*
	* Input parameters:	two floating point position			    *
	* Returns:													*
	*************************************************************/
	void setPosition(const sf::Vector2f pos);

	/*************************************************************
	* Function: player_boundary()						        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: 	gets the player or shape boundaries			*
	*															*
	* Input parameters:										    *
	* Returns:	the two floating point (x, y) of the player		*
	*************************************************************/
	sf::FloatRect player_boundary();

private:
	sf::RectangleShape shape;
	sf::Vector2f position;
	int health;
	float speed;
};



