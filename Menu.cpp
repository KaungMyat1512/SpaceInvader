#include "Menu.h"



Menu::Menu(float width, float height)
{


	texture[0].loadFromFile("Title.png");				//The title 
	test[0].setTexture(texture[0]);
	test[0].setPosition(width / 600, height / 20);

	texture[1].loadFromFile("Start.png");				//The start
	test[1].setTexture(texture[1]);
	test[1].setPosition(width / 8, height / (3 + 1) * 1.5);

	texture[2].loadFromFile("Exit.png");				//Exit
	test[2].setTexture(texture[2]);
	test[2].setPosition(width / 8, height / (3 + 1) * 2.5);

	texture[3].loadFromFile("StartHold.png");			//Start png change when player user mouse is over it
	test[3].setTexture(texture[3]);
	test[3].setPosition(width / 8, height / (3 + 1) * 1.5);

	texture[4].loadFromFile("ExitHold.png");			//Exit png change when player user moust is over it
	test[4].setTexture(texture[4]);
	test[4].setPosition(width / 8, height / (3 + 1) * 2.5);

}

//Menu::~Menu()
//{
//	std::cout << "ya" << std::endl;
//}





void Menu::draw(sf::RenderWindow& window)		//Runs through the first 3 png(title, normal start, normal exit)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(test[i]);
	}

}



void Menu::Click(sf::RenderWindow& window, float width, float height, int& i) //This function is detecting when the user mouses want to start the game or exit the game
{
	sf::Vector2i postion = sf::Mouse::getPosition(window);		//This gets the position of the mouse

	int complete = 0;


	sf::RectangleShape startBoundaies(sf::Vector2f(325, 135)); //creates a RectangleShape for the start button as a invisible boundaries
	startBoundaies.setPosition(width / 3.2, height / 2.4);

	sf::RectangleShape endBoundaies(sf::Vector2f(325, 135)); //creates a RectangleShape for the Exit button as a invisible boundaries
	endBoundaies.setPosition(width / 3.2, height / 1.5);


	if (((postion.x >= startBoundaies.getPosition().x) && (postion.x <= startBoundaies.getPosition().x + startBoundaies.getSize().x)) && ((postion.y >= startBoundaies.getPosition().y) && (postion.y <= startBoundaies.getPosition().y + startBoundaies.getSize().y)))
	{
		//it gets our mouse position of (x,y) and finding whether if our mouse position is within our defined rectangle shape boundaries 

		window.draw(test[3]); //change the start png  to start hold png
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		{
			i = 1;
		}
	}

	else if (((postion.x >= endBoundaies.getPosition().x) && (postion.x <= endBoundaies.getPosition().x + endBoundaies.getSize().x)) && ((postion.y >= endBoundaies.getPosition().y) && (postion.y <= endBoundaies.getPosition().y + endBoundaies.getSize().y)))
	{

		//it gets our mouse position of (x,y) and finding whether if our mouse position is within our defined rectangle shape boundaries 

		window.draw(test[4]); // change the exit png to exit hold png
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		{
			window.close();
		}
	}
}
