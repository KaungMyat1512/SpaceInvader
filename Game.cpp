#include"Game.h"
//Game Logic: update scores: it player's laser hit the enemy's ship
//50 points will end the game and player win
//if the enemy ship or laser hit player: 1 heart will be drop: 5 drops are allowed. if player lose all health: enemy win; 
Game::Game()
{

	this->timerMax = 20.f;
	this->spawnTimer = this->timerMax;
	this->scores = 0;
	this->health = 5;
	this->ready = 10.f; //for the shooting range: 
	this->cooldown = this->ready; 
	this->player = nullptr; 
	
	if (!font.loadFromFile("arial.ttf")) {
		// Handle font loading error
		return;
	}

	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(1.5f, 20.f);
	 
}

Game::~Game()
{
	
	delete this->player; 
	//deleteing the bullets; 
	for (auto* i : this->lasers)
	{
		delete i;
	}

	for (auto* i : this->enemies)
	{
		delete i;
	}
	for (auto* i : this->healthBar)
	{
		delete i; 
	}
}



void Game::run(sf::RenderWindow& window)
{
	initialize_player(500.f,500.f); 
	initialize_hearth_bar(); 
	bool first = true; 
		sf::Vector2f position;
		sf::Event ev; 
		//this->player = new Player();
		int play = 0; 
		Menu menu(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y));  
		while (window.isOpen())
		{
			if (play == 1)
			{
				this->cooldown += 0.5f;

				while (window.pollEvent(ev))
				{

					//display_message("PRESS ANY KEY TO START GAME", 0.2f, 350.f, 30, window); 
					if (ev.type == sf::Event::Closed)
					{
						window.close();
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						this->player->move_player(-99.f, 0.f);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						this->player->move_player(99.f, 0.f);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						this->player->move_player(0.f, -99.f);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						this->player->move_player(0.f, 99.f);
					}
					setP_boundary();



					//this place; 
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{

						if (this->cooldown >= this->ready)
						{
							this->lasers.push_back(new PlayerLaser(this->player->getPosition().x + 11.f, this->player->getPosition().y, 0.f, -0.1f, 150.f, sf::Color::Green));//set up the player's position as the place of shooting
							this->cooldown = 0.f;
						}
					}
				}
				if (this->health > 0)//player should be alive before getting 10 scores; 
				{
					if (this->scores < 30)//if you got 30 hits you win
					{
						this->update();

						this->render(window);
					}
				}
			}
			else
			{
				window.clear(sf::Color::Black); 
				menu.draw(window); 
				menu.Click(window, 600.f, 800.f, play); 
				window.display(); 
			}
		}

	
}


void Game::update()
{

	

	this->updateBullets();

	this->updateEnemies();
	this->updateHealth(); 

	this->updateEnemyBullets();///update the bullet;  

}

void Game::render(sf::RenderWindow& window)
{
	window.clear();

	/*this->player->render(window);*/ 

	for (auto* i : this->lasers) 
	{
		i->render(window); 
	}

	for (auto* enemy : this->enemies)
	{
		enemy->render(window);
	}
	for (auto* e_bullets : this->lasers)
	{
		e_bullets->render(window); //displaying the bullet; >> 
	}
	this->player->render(window); 
	displayScore(window); 
	for (auto* health : this->healthBar)
	{
		health->render(window); 
	}
	if (this->health == 0)
	{
		//displayMessage(1); 
		display_message("GAME OVER", 99.0f, 350.f, 60, window); 
		std::cout << "Fail" << std::endl;

	}
	if (this->scores == 30)
	{
		//displayMessage(2);
		display_message("VICTORY", 150.f, 350.f, 60, window); 
		std::cout << "Win" << std::endl;
	}
	window.display();
}

void Game::initialize_player(float x, float y)
{
	this->player = new Player(x, y);
}

Player Game::getPlayer()
{
	return *this->player;
}

void Game::initialize_hearth_bar()
{
	float pos_x = 1.5f; 
	for (int i = 0; i < this->health; i++)
	{
		//pos_x= 1.5f;  //1.5 f distance; 
		this->healthBar.push_back(new Stat(pos_x)); 
		pos_x += 25.5f;
	}
	
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* laser : this->lasers)
	{
		laser->move(); //move the bullet; //

		if (laser->is_in_screen() == false)//position acceptable
		{
			//delete the laser; 
			delete laser; //release the memory 
			this->lasers.erase(this->lasers.begin() + counter); 
			counter--; //after deleting one bullet will drop 
		}
		counter++;
	}

}

void Game::updateEnemies()
{
	int random = 0;
	this->spawnTimer += 0.5f;
	float position = 0.0;
	if (this->spawnTimer >= this->timerMax)
	{
		position = static_cast<float>(rand() % 500 + 1);
		this->enemies.push_back(new Enemy(position, 0.f)); //25.f; (position, 25.f is the laser):
		this->lasers.push_back(new EnemyLaser(position, 25.f, 0.f, 0.1f, 50.f,sf::Color::Red));
		this->spawnTimer = 0.f;

	}


	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_removed = false;
		this->enemies[i]->move_enemy();
		//update bullet->here: 
		for (size_t k = 0; k < this->lasers.size() && !enemy_removed; k++)//loop through the bullet's vector
		{
			if (this->lasers[k]->getType() == 1)//player's laser 
			{
				if (collides(this->lasers[k]->laser_boundary(), this->enemies[i]->enemy_boundary()))//the bullet,
				{
					std::cout << "Hit" << endl; 
					this->scores += 1; //update scores///
					std::cout << "scores: " << this->scores << std::endl;
					std::cout << "::::::::::::" << endl; 
					//remove bullet and enemy; 
					this->lasers.erase(this->lasers.begin() + k);
					this->enemies.erase(this->enemies.begin() + i); //enemy: is i cuz: 
					enemy_removed = true;


				}
			}
		}
		if (!enemy_removed)//already delete the enemy cuz of bullet, thus, no need to remove; 
		{
			if (this->enemies[i]->touches_bottom())//delete the ship 
			{
				this->enemies.erase(this->enemies.begin() + i); //will delete the ship at position i in vector; 
				enemy_removed = true;
				this->scores -= 1; 
				std::cout << "scores:  " << this->scores << endl; 
				std::cout << "Ship escaped: " << std::endl; 
				std::cout << ":::::::" << endl; 
			}
			else if (collides(this->enemies[i]->enemy_boundary(), this->player->player_boundary()))
			{

				this->healthBar.erase(this->healthBar.end() - 1); 
				this->health -= 1; 
				std::cout << "Health: " << this->health << endl; 
				std::cout << "Ship collides: " << std::endl;
				enemy_removed = true; 
				this->enemies.erase(this->enemies.begin() + i); 
			}
		}


	}
}

bool Game::collides(sf::FloatRect bullet,  sf::FloatRect ship)
{
	bool collides = false;
	if (bullet.intersects(ship))//if they collides; 
	{
		collides = true; //it collides; 
	}
	return collides;
}

void Game::updateHealth()
{
	for (size_t k = 0; k < this->lasers.size(); k++)
	{
		if (this->lasers[k]->getType() == 2)//enemy's laser
		{
			//test the collision: 
			if (collides(this->lasers[k]->laser_boundary(), this->player->player_boundary()) )
			{
				this->lasers.erase(this->lasers.begin() + k); //delete the laser; 
				this->health -= 1; 
				//reduce the health bar; 
				this->healthBar.erase(this->healthBar.end()-1); 
				std::cout << "Health: " << this->health << endl;
				std::cout << "Get Hit" << endl; 
			}
		}
	}
}




void Game::updateEnemyBullets()
{
	
	unsigned counter = 0;
	for (auto* laser : this->lasers)
	{
		if (laser->getType() == 2)
		{
			laser->move(); //move the bullet; //

			if (laser->is_in_screen() == false)//if the bullet is out of screen, this part will delete the bullet; 
			{
				//delete the bullet; 
				delete laser; //release the memory 
				this->lasers.erase(this->lasers.begin() + counter);
				counter--; //after deleting one bullet will drop 
			}
		}
			counter++;
		
	}
}

void Game::display_message(const std::string& message, float x, float y, int fontSize, sf::RenderWindow& window)
{
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		// Handle font loading error
		return;
	}

	sf::Text text;
	text.setFont(font);
	text.setString(message);
	text.setCharacterSize(fontSize);
	text.setFillColor(sf::Color::White);
	text.setPosition(x, y);
	window.clear(); 
	window.draw(text); 
}



std::vector<Stat*>& Game::getHealthBar()
{
	return healthBar;  
}

void Game::setP_boundary()
{
	sf::Vector2f pos;
	if (this->player->getPosition().x < 0.f)
	{
		pos.x = 0.f;
		pos.y = this->player->getPosition().y;
		this->player->setPosition(pos);
	}
	//right boundary
	else if (this->player->getPosition().x + 25.f >= 600.f)//1000 is the window's width
	{
		pos.x = 575.f; //
		pos.y = this->player->getPosition().y;
		this->player->setPosition(pos);
	}
	//top world
	if (this->player->getPosition().y < 0.f)
	{
		pos.x = this->player->getPosition().x;
		pos.y = 0.f;
		this->player->setPosition(pos);
	}
	else if (this->player->getPosition().y + 25.f >= 800.f)//900 is the window's height
	{
		pos.x = this->player->getPosition().x;
		pos.y = 775.f;
		this->player->setPosition(pos);
	}

}
void Game::displayScore(sf::RenderWindow& window)
{
	scoreStream.str("");  // Clear the stringstream
	scoreStream << "Score: " << this->scores;  // Convert score to string

	scoreText.setString(scoreStream.str());  // Set the string to sf::Text
	window.draw(scoreText); 
}