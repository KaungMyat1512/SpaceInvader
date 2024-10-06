#include<iostream>
#include"SFML/Graphics.hpp"
#include"Game.h"
#include"Test.h"

using std::cout; 
using std::endl; 
int main(void)
{
   
	 
	srand(static_cast<unsigned>(time(0)));
	Game game;
	sf::RenderWindow window(sf::VideoMode(600, 800), "Space Sweepers");
	window.setFramerateLimit(120); 
	cout << ":::::::::::::::::::::::::::::" << endl; 
	cout << ":        SPACE SWEEPER      :" << endl; 
	cout << ":::::::::::::::::::::::::::::\n" << endl;
	cout << ":::::::::::" << endl; 
	cout << "To Win:\nGet 30 points.\n" << endl; 
	cout << ":::::::::::" << endl;
	cout << "5 hit points:\nEnemies and Lasers.\n" << endl; 
	cout << ":::::::::::" << endl;
	cout << "-1 point:\nFor escaped ship. " << endl; 
	


	game.run(window);  
	system("cls"); 
	Test a; 
	cout << "TESTING Functions. \n" << endl; 
	a.testing_collision(); 
	a.testing_lasers_polymorphism(); 
	a.testing_setPboundary(); 
	a.testHealthBar(); 
	a.testMenu(); 

	return 0; 
}