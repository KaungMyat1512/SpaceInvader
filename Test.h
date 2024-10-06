#pragma once

#include"Game.h"

class Test
{
public:

	/*************************************************************
	* Function: Test()									        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: The constructor	of the Test class			*
	*															*
	* Input parameters:											*
	* Returns: 													*
	*************************************************************/
	Test();

	/*************************************************************
	* Function: ~Test()									        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: The destructor	of the Test class			*
	*															*
	* Input parameters:											*
	* Returns: 													*
	*************************************************************/
	~Test();

	/*************************************************************
	* Function: test_collision()						        *
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: Testing if two object whether its collided	*
	*															*
	* Input parameters:											*
	* Returns: 													*
	*************************************************************/
	void testing_collision(); //this function will test collides function;  


	/*************************************************************
	* Function: testing_lasers_polymorphism()					*
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: Detects if player and enemy laser is created *
	*			in the window									*
	*															*
	* Input parameters:											*
	* Returns: 													*
	*************************************************************/
	void testing_lasers_polymorphism();


	/*************************************************************
	* Function: testing_setPboundary()							*
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: Testing player position whether if it can	*
	*	move outside of the boundaries							*
	*															*
	* Input parameters:											*
	* Returns: 													*
	*************************************************************/
	void testing_setPboundary(); //setPbounary limits the player's movement within window


	/*************************************************************
	* Function: testingHealthBar()								*
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: Testing players health						*
	*															*
	* Input parameters:											*
	* Returns: 													*
	*************************************************************/
	void testHealthBar();


	/*************************************************************
	* Function: testMenu()										*
	* Date Created: 12/07/23                                    *
	* Date Last Modified:                                       *
	* Description: Test Menu of the game window					*
	*	whether if mouse click is detect within the boundary	*
	*															*
	* Input parameters:											*
	* Returns: 													*
	*************************************************************/
	void testMenu();

private:
	sf::RectangleShape obj1;
	sf::RectangleShape obj2;

	std::vector<Laser*> lasers;
	std::vector<Stat*> healthBar;
};

