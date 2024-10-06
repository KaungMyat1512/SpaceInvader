#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics/Font.hpp"
#include"SFML/Graphics/Text.hpp"

#include"Laser.h"
#include"Enemy.h"
#include"Player.h"
#include"EnemyLaser.h"
#include"PlayerLaser.h"
#include"Stat.h"
#include"Menu.h"

using std::cout;
using std::endl;
using std::cin; 
//
class Game
{

public: 
	
	Game();
	/******************************************************************************************************
	* Function:				Game()
	* Description:			constructor; 
	* Input parameters:		none
	* Returns:				none
	*******************************************************************************************************/
	~Game();
	/******************************************************************************************************
	* Function:				~Game()
	* Description:			destructor: deallocating memory
	* Input parameters:		none
	* Returns:				none
	*******************************************************************************************************/

	//void display_menu(sf::RenderWindow& window); 
	void run(sf::RenderWindow& window);
	/******************************************************************************************************
	* Function:				run()
	* Description:			this function will do rendering process and run the game;
	* Input parameters:		window we want to draw and render
	* Returns:				none
	*******************************************************************************************************/

	void update(); //update all the characters positions and attributes
	/******************************************************************************************************
	* Function:				update()
	* Description:			this function will update player's location, laser's location and etc
	* Input parameters:		none
	* Returns:				none
	*******************************************************************************************************/
	void render(sf::RenderWindow& window);  //
	/******************************************************************************************************
	* Function:				render()
	* Description:			this function will render the game
	* Input parameters:		window we want to draw
	* Returns:				none
	*******************************************************************************************************/
	void initialize_player(float x,float y); 
	/******************************************************************************************************
	* Function:				initialize_player()
	* Description:			this function will set the position of the player;
	* Input parameters:		float type x and y coordinates
	* Returns:				none
	*******************************************************************************************************/
	Player getPlayer(); 
	/******************************************************************************************************
	* Function:				getPlayer()
	* Description:			this function will return the player object
	* Input parameters:		none
	* Returns:				player object
	*******************************************************************************************************/
	void initialize_hearth_bar(); 
	/******************************************************************************************************
	* Function:				initialize_hearth_bar()
	* Description:			this function will create the health bar animation on the screen
	* Input parameters:		none
	* Returns:				none
	*******************************************************************************************************/

	void updateBullets();
	/******************************************************************************************************
	* Function:				updateBullets()
	* Description:			this function will update the bullet's position, delete if run out of window
	* Input parameters:		none
	* Returns:				none
	*******************************************************************************************************/
	void updateEnemies();
	/******************************************************************************************************
	* Function:				updateEnemies()
	* Description:			this function will update the position of enemies;
	* Input parameters:		none
	* Returns:				none
	*******************************************************************************************************/
	bool collides(sf::FloatRect bullet, sf::FloatRect ship); //this will test whether the bullet touches with the enemy
	/******************************************************************************************************
	* Function:				collides()
	* Description:			this function will this will test whether the bullet touches with the enemy
	* Input parameters:		none
	* Returns:				bool
	*******************************************************************************************************/
	void updateHealth(); 
	/******************************************************************************************************
	* Function:				updateHealth()
	* Description:			this function will update health animation on the screen. delete if player get hit
	* Input parameters:		none
	* Returns:				none
	*******************************************************************************************************/

	void setP_boundary();
	/******************************************************************************************************
	* Function:				setP_boundary()
	* Description:			this function will restrict the player's position within the window; 
	* Input parameters:		none
	* Returns:				none
	*******************************************************************************************************/

	void updateEnemyBullets();
	/******************************************************************************************************
	* Function:				updateEnemyBullets()
	* Description:			this function will move update enemy's bullet and erase from the vector if the 
	*						bullet is out of window: 
	* Input parameters:		none
	* Returns:				none
	*******************************************************************************************************/
	void display_message(const std::string& message, float x, float y, int fontSize, sf::RenderWindow& widow);
	/******************************************************************************************************
	* Function:				display_message()
	* Description:			this function will display message to the window: based on the input parameter
	* Input parameters:		string message which we want to display, position on the window, size of the 
	*						letters
	* Returns:				none
	*******************************************************************************************************/
	
	void displayScore(sf::RenderWindow& window); 
	/******************************************************************************************************
	* Function:				displayScore()
	* Description:			this function will display the player's current score on the screen
	* Input parameters:		none
	* Returns:				none
	*******************************************************************************************************/


	std::vector<Stat*>& getHealthBar();
	/******************************************************************************************************
	* Function:				getHealthBar()
	* Description:			this function will return the health bar of the player
	* Input parameters:		none
	* Returns:				vector that store the Stat class type healthBars
	*******************************************************************************************************/
private: 

	

	float spawnTimer;
	float timerMax;
	Player* player; 
	
	std::vector<Enemy*> enemies;
	/*std::vector<EnemyLaser*> e_lasers; 
	std::vector<PlayerLaser*> p_lasers; */
	std::vector<Laser*> lasers; 
	int health; //counter variable for all the ships passing the grid; //this is temp; we will -1 from player's health
	int scores;
	float cooldown; 
	float ready;
	std::vector<Stat*> healthBar; 
	
	sf::Font font;
	sf::Text scoreText;
	std::stringstream scoreStream; 

};
