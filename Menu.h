#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Menu
{
public:



	/*************************************************************
	* Function: Menu()									        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: The constructor of the Menu class			*
	*															*
	* Input parameters:	two floating point of the window	    *
	* Returns:													*
	*************************************************************/
	Menu(float width, float height);




	/*************************************************************
	* Function: draw()									        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: Takes in all the sprite and draw it to the 	*
	*		screen												*
	*															*
	* Input parameters:	RenderWindow						    *
	* Returns:													*
	*************************************************************/
	void draw(sf::RenderWindow& window);


	/*************************************************************
	* Function: click()									        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: creates the button boundaries and whether 	*
	*   if user mouse cursor within the boundaries and			*
	*	whether if player click on within the boundaries		*
	*															*
	* Input parameters:	RenderWindow, window x size,			*
	*	window y size, and a integer value						*
	* Returns:													*
	*************************************************************/
	//user able to interact with the main menu
	void Click(sf::RenderWindow& window, float width, float height, int& i);


private:
	sf::Sprite test[5];
	sf::Texture texture[5];

};
