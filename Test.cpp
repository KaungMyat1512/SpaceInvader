#include "Test.h"

Test::Test()
{
	//defualt shapes: and size; 
	this->obj1.setFillColor(sf::Color::Red); 
	
	this->obj1.setPosition(0.1f, 0.1f); 
	this->obj1.setSize(sf::Vector2f(10.f,10.f)); 

	this->obj2.setFillColor(sf::Color::Blue); 
	this->obj2.setPosition(0.1f, 0.1f); 
	this->obj2.setSize(sf::Vector2f(10.f, 10.f)); 

	
}

Test::~Test()
{
}

void Test::testing_collision()
{
	Game specimen; 
	//first off,->create two object will collision state: 
	//default constructor will create two objects with the same position. 
	bool success = false; 
	cout << ":::::::::::::::::" << endl; 
	cout << "TESTING COLLISION" << endl; 
	cout << ":::::::::::::::::\n" << endl; 

	cout << "Showing objects position coordinates: \n"; 
	cout << "Object 1 position:( " << this->obj1.getPosition().x << " " << this->obj1.getPosition().y <<")"<< endl;
	cout << "Object 2 position:( " << this->obj2.getPosition().x << " " << this->obj2.getPosition().y << ")" << endl;
	cout << "Two objects are at the same position coordinates." << endl; 
	
	cout << "TESTING THE COLLIDES FUNCTION" << endl; 
	system("pause");
	//if our function is correct, this should return true
	if (specimen.collides(this->obj1.getGlobalBounds(), this->obj2.getGlobalBounds()))
	{
		cout << "coolides returns true, stating that the two objects collide" << endl;
		cout << "::::::::::::::::::::::::::" << endl;
		cout << "The function is successful" << endl;
		cout << "::::::::::::::::::::::::::\n" << endl;
		
		
	}
	else
	{
		cout << "::::::::::::::::::" << endl;
		cout << "The function fail." << endl;
		cout << "::::::::::::::::::" << endl;
		cout << "Objects are in the same position, but collides function does not detect the intersection.\n" << endl; 

	}
	system("pause"); 
	//changing the object's coordinates; 
	this->obj1.setPosition(30.f, 30.f); 
	
	cout << "Showing the object's initial positions before testing" << endl; 
	cout << "Object 1 position:( " << this->obj1.getPosition().x << " " << this->obj1.getPosition().y << ")" << endl;
	cout << "Object 2 position:( " << this->obj2.getPosition().x << " " << this->obj2.getPosition().y << ")" << endl;
	cout << "Objects are in the different coordinates" << endl; 
	system("pause"); 
	if (!specimen.collides(this->obj1.getGlobalBounds(), this->obj2.getGlobalBounds()))
	{
		cout << "coolides returns false, stating that the two objects do not collides" << endl;
		cout << "::::::::::::::::::::::::::" << endl;
		cout << "The function is successful" << endl;
		cout << "::::::::::::::::::::::::::\n" << endl;

	}
	else
	{
		cout << "::::::::::::::::::" << endl;
		cout << "The function fail." << endl;
		cout << "::::::::::::::::::" << endl;
		cout << "Objects are in the different position, but collides function somehow detect the intersection.\n" << endl;
	}

	cout << "All Testing conditions complete.\n" << endl;	
	system("pause"); 
	system("cls"); 
}

void Test::testing_lasers_polymorphism()
{
	cout << ":::::::::::::::::::::::::::" << endl; 
	cout << "TESTING LASERS POLYMORPHISM" << endl; 
	cout << ":::::::::::::::::::::::::::\n" << endl;
	//will create two objects: player's laser and enemy's laser;

	//the first laser is player's laser: 
	this->lasers.push_back(new PlayerLaser(0.f,0.f, 0.f, 0.1f, 50.f, sf::Color::Red));//adding the player laser: at the end of the vector
	cout << "Player Laser is added to the laser vector" << endl; 
	//thus this should be at the 0 position. 
	this->lasers.push_back(new EnemyLaser(1.f, 1.f, 0.f, 0.1f, 50.f, sf::Color::Blue));//adding enemy's lasers 
	cout << "Enemy laser is added to the laser vector" << endl; 
	
	system("pause"); 

	//testing the get_Type functions; 
	if (this->lasers[0] != NULL)//the laser's is not empty
	{
		cout << "Adding objects into vector is successful" << endl; 
		if (this->lasers[0]->getType() == 1)
		{

			cout << "Player's laser is shown at position 0. " << endl;
			cout << "Thus, getType() function is correctly showing the laser type." << endl;
			cout << "::::::::::::::::::::::::::" << endl;
			cout << "The function is successful" << endl;
			cout << "::::::::::::::::::::::::::\n" << endl; 
			
		}
		else if(this->lasers[0]->getType()!=1)
		{
			cout << "Plyer's laser is not detected" << endl;
			cout << "::::::::::::::::::" << endl;
			cout << "The function fail." << endl;
			cout << "::::::::::::::::::\n" << endl;
		}
		if (this->lasers[1]->getType() == 2)
		{
			cout << "Enemy's laser is shown at position 1." << endl; 
			cout << "Thus, getType() function is correctly showing the laser type." << endl; 
			cout << "::::::::::::::::::::::::::" << endl;
			cout << "The function is successful" << endl;
			cout << "::::::::::::::::::::::::::\n" << endl;
		}
		else if(this->lasers[1]->getType()!=2)
		{
			cout << "Enemy Laser is not detected" << endl; 
			cout << "::::::::::::::::::" << endl;
			cout << "The function fail." << endl;
			cout << "::::::::::::::::::\n" << endl;
		}
	}
	else
	{
		cout << "Adding objects into laser vector does not work." << endl;
		cout << "::::::::::::::::::" << endl;
		cout << "Polymorphism fails." << endl;
		cout << "::::::::::::::::::\n" << endl;
	}
	cout << "All Testing conditions complete.\n" << endl;
	system("pause");
	system("cls");
}

void Test::testing_setPboundary()
{
	cout << ":::::::::::::::::::::" << endl; 
	cout << "TESTING set_Pboundary" << endl;
	cout << ":::::::::::::::::::::\n" << endl; 

	Game specimen; 
	specimen.initialize_player(700.f,100.f); 
	//first off: the original window is 600, 800 range: 
	cout << "Original window frame: width:600, height 800." << endl; 
	cout << "Player size is (width,height): (22.f,25.f).\n" << endl; 
	cout << "Right Boundary detection: " << endl; 
	//this->obj1.setPosition(700.f,100.f); 
	cout << "Player's current position: " << specimen.getPlayer().getPosition().x << " : " << specimen.getPlayer().getPosition().y << "." << endl;
	cout << "Apply set_Pboundary() function." << endl;
	specimen.setP_boundary(); 
	cout << "Player's position after the setP_boundary: " << specimen.getPlayer().getPosition().x << " : " << specimen.getPlayer().getPosition().y << "." << endl;
	if (specimen.getPlayer().getPosition().x == 575.f)
	{
		cout << "Player's position is contained within the window: " << endl; 
		cout << "::::::::::::::::::::::::::" << endl;
		cout << "The function is successful" << endl;
		cout << "::::::::::::::::::::::::::\n" << endl;
	}
	else
	{
		cout << "Player's out of boundary." << endl; 
		cout << "::::::::::::::::::" << endl;
		cout << "The function fail." << endl;
		cout << "::::::::::::::::::\n" << endl;
	}

	system("pause"); 
	specimen.initialize_player(-100.f, 100.f);
	cout << "Left Boundary detection: " << endl;
	//this->obj1.setPosition(700.f,100.f); 
	cout << "Player's current position: " << specimen.getPlayer().getPosition().x << " : " << specimen.getPlayer().getPosition().y << "." << endl;
	cout << "Apply set_Pboundary() function." << endl;
	specimen.setP_boundary();
	cout << "Player's position after the setP_boundary: " << specimen.getPlayer().getPosition().x << " : " << specimen.getPlayer().getPosition().y << "." << endl;
	if (specimen.getPlayer().getPosition().x == 0.f)
	{

		cout << "Player's position is contained within the window: " << endl;
		cout << "::::::::::::::::::::::::::" << endl;
		cout << "The function is successful" << endl;
		cout << "::::::::::::::::::::::::::\n" << endl;
	}
	else
	{
		cout << "Player's out of boundary." << endl;
		cout << "::::::::::::::::::" << endl;
		cout << "The function fail." << endl;
		cout << "::::::::::::::::::\n" << endl;
	}

	system("pause");
	specimen.initialize_player(0.f, -100.f);
	cout << "Top Boundary detection: " << endl;
	//this->obj1.setPosition(700.f,100.f); 
	cout << "Player's current position: " << specimen.getPlayer().getPosition().x << " : " << specimen.getPlayer().getPosition().y << "." << endl;
	cout << "Apply set_Pboundary() function." << endl;
	specimen.setP_boundary();
	cout << "Player's position after the setP_boundary: " << specimen.getPlayer().getPosition().x << " : " << specimen.getPlayer().getPosition().y << "." << endl;
	if (specimen.getPlayer().getPosition().y== 0.f)
	{
		cout << "Player's position is contained within the window: " << endl;
		cout << "::::::::::::::::::::::::::" << endl;
		cout << "The function is successful" << endl;
		cout << "::::::::::::::::::::::::::\n" << endl;
		
	}
	else
	{
		cout << "Player's out of boundary." << endl;
		cout << "::::::::::::::::::" << endl;
		cout << "The function fail." << endl;
		cout << "::::::::::::::::::\n" << endl;
	}

	system("pause");
	specimen.initialize_player(100.f, 1000.f);
	cout << "Bottom Boundary detection: " << endl;
	//this->obj1.setPosition(700.f,100.f); 
	cout << "Player's current position: " << specimen.getPlayer().getPosition().x << " : " << specimen.getPlayer().getPosition().y << "." << endl;
	cout << "Apply set_Pboundary() function." << endl;
	specimen.setP_boundary();
	cout << "Player's position after the setP_boundary: " << specimen.getPlayer().getPosition().x << " : " << specimen.getPlayer().getPosition().y << "." << endl;
	if (specimen.getPlayer().getPosition().y == 775.f)
	{
		cout << "Player's position is contained within the window: " << endl;
		cout << "::::::::::::::::::::::::::" << endl;
		cout << "The function is successful" << endl;
		cout << "::::::::::::::::::::::::::\n" << endl;
	}
	else
	{
		cout << "Player's out of boundary." << endl;
		cout << "::::::::::::::::::" << endl;
		cout << "The function fail." << endl;
		cout << "::::::::::::::::::\n" << endl;
	}
	
	cout << "All Testing conditions complete.\n" << endl; 	
	system("pause");
	system("cls");
}

void Test::testHealthBar()
{
	cout << "::::::::::::::::::" << endl; 
	cout << "TESTING HEALTHBAR." << endl; 
	cout << "::::::::::::::::::\n" << endl; 

	Game test;

	cout << "Before initializing a health bar.." << endl;
	cout << "The current size of HealthBar:  " << test.getHealthBar().size() << endl << endl;;

	cout << "Now let's initialize a health bar!" << endl;
	test.initialize_hearth_bar();
	cout << "The current size of HealthBar:  " << test.getHealthBar().size() << endl;

	if (test.getHealthBar().size() == 5)
	{
		cout << "Since the health bar size is 5, A Health bar was created successfuly. Test success!" << endl;
	}

	else
	{
		cout << "Since the health bar size is not 5. A health bar wasn't created successfully. Test Failed!" << endl;
	}

	cout << "All testing conditions completed." << endl; 
	system("pause"); 
	system("cls"); 
}

void Test::testMenu()
{
	cout << "Testing for Menu press function" << endl;
	sf::RenderWindow test(sf::VideoMode(600, 800.f), "Test");
	sf::Event event;
	Menu menu(test.getSize().x, test.getSize().y);
	int i = 0;

	cout << "If Left click on start button without message: failed" << endl;
	cout << "If Left click on start button with message: system Passed" << endl;

	while (test.isOpen())
	{
		if (test.pollEvent(event))
		{
			while (event.type == sf::Event::Closed)
			{
				test.close();
			}
		}
		if (i == 1)
		{

			cout << "_____________________________________________________" << endl;
			cout << "|The Mouse position is within the button  boundaries|" << endl;
			cout << "`````````````````````````````````````````````````````" << endl;

			cout << "_____________________________________________________" << endl;
			cout << "|And you Click on the button!						   |" << endl;
			cout << "`````````````````````````````````````````````````````" << endl;
			cout << "Testing successful" << endl; 

			cout << "Please press exit on the window to exit the Program." << endl;


			system("pause");
			system("cls");


			i = 0; 
		}

		 
		menu.draw(test);
		menu.Click(test, test.getSize().x, test.getSize().y, i);
		test.display();

	}



}
