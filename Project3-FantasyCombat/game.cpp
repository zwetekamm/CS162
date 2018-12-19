/***********************************************************
* Author: Zachary Wetekamm
* Date: 08/05/18
* Description: Source file for the class Game, which
* contains all the game-flow for the combat fantasy battle.
***********************************************************/
#include "game.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/***********************************************************
* Game()
* Description: Default constructor; initialize character
* pointers to NULL.
***********************************************************/
Game::Game()
{
	char1 = NULL;
	char2 = NULL;
}

/***********************************************************
* ~Game()
* Description: Default destructor.
***********************************************************/
Game::~Game()
{
	delete char1;
	char1 = NULL;

	delete char2;
	char2 = NULL;
}


/***********************************************************
* play()
* Description: Combines the menu and fight functions. Also
* deletes created objects to avoid memory leaks.
***********************************************************/
void Game::play()
{
	menu();
	fight();

	delete char1;
	char1 = NULL;
	delete char2;
	char2 = NULL;
}


/***********************************************************
* menu()
* Description: Main menu, which allows the user to create
* character objects to fight 1 versus 1 combat.
***********************************************************/
void Game::menu()
{
	int choice;
	std::srand(std::time(NULL));

	cout << "Project 3: Fantasy Combat Game" << endl;
	cout << "1. Play Game." << endl;
	cout << "2. Exit Program." << endl;
	getInt(choice, 1, 2);

	if (choice == 2)
	{
		cout << "Exiting..." << endl;
		exit(0);
	}

	// main menu loop
	for (int i = 0; i < 2; i++)
	{
		int choice;
		cout << "Choose character " << i + 1 << ":" << endl;
		cout << "1. Vampire" << endl;
		cout << "2. Barbarian" << endl;
		cout << "3. Blue Men" << endl;
		cout << "4. Medusa" << endl;
		cout << "5. Harry Potter" << endl;
		getInt(choice, 1, 5);

		switch (choice)
		{
			case 1:	// Vampire
			{
				if (char1 == NULL)
				{
					char1 = new Vampire();
					break;
				}
				else
				{
					char2 = new Vampire();
					break;
				}
			}
			case 2:	// Barbarian
			{
				if (char1 == NULL)
				{
					char1 = new Barbarian();
					break;
				}
				else
				{
					char2 = new Barbarian();
					break;
				}
			}
			case 3: // Blue Men
			{
				if (char1 == NULL)
				{
					char1 = new BlueMen();
					break;
				}
				else
				{
					char2 = new BlueMen();
					break;
				}
			}
			case 4:	// Medusa
			{
				if (char1 == NULL)
				{
					char1 = new Medusa();
					break;
				}
				else
				{
					char2 = new Medusa();
					break;
				}
			}
			case 5:	// Harry Potter
			{
				if (char1 == NULL)
				{
					char1 = new HarryPotter();
					break;
				}
				else
				{
					char2 = new HarryPotter();
				}

			}
		}
	}
}


/***********************************************************
* fight()
* Description: Initiates combat between the two created
* characters. Each character has an attack and defend phase.
* Combat ends when one character dies.
***********************************************************/
void Game::fight()
{
	int round = 1;

	while (true)
	{
		int char1Attack;
		int char1Defense;
		int char2Attack;
		int char2Defense;
		int totalDamage;
		
		cout << "----- Round " << round << " -----" << endl;

		// Character 1 attacks
		cout << "Character 1: " << char1->getType() << " attacks." << endl;
		char1Attack = char1->attack();

		// Character 2 defends
		cout << "Character 2: " << char2->getType() << " defends." << endl;
		char2Defense = char2->defend();

		// display defense stats
		cout << "Character 2 has " << char2->getArmor() << " armor "
			 << "and " << char2->getStrength() << " strength points." << endl;

		// 100 is returned if medusa turns opponent to stone
		attackEffect(char1Attack);

		// 99 is returned if a vampire charms opponent
		defendEffect(char2Defense);

		// total damage is difference between attack, defense, and armor
		totalDamage = (char1Attack - char2Defense - char2->getArmor());
		// if negative, then equal 0
		if (totalDamage < 0)
		{
			totalDamage = 0;
		}

		// display total damage to defender; check if turned stone.
		printTotalDamage(char1Attack, totalDamage);
		
		// calculate remaining strength points for character 2
		char2->calcDamage(totalDamage);
		cout << "Character 2 has " << char2->getStrength() << " strength remaining." << endl;

		// if Character 2 suffered fatal damage, break the loop
		if (char2->isDead())
		{
			cout << "Character 2: " << char2->getType() << " is defeated." << endl;
			cout << "Character 1: " << char1->getType() << " wins!" << endl;
			break;
		}


		// end phase
		cout << "-----" << endl;

		// Character 2 attacks
		cout << "Character 2: " << char2->getType() << " attacks." << endl;
		char2Attack = char2->attack();
				
		// Character 1 defends
		cout << "Character 1: " << char1->getType() << " defends." << endl;
		char1Defense = char1->defend();

		// display attack and defense stats
		cout << "Character 1 has " << char1->getArmor() << " armor "
		 	 << "and " << char1->getStrength() << " strength points." << endl;

		// 100 is returned if medusa turns opponent to stone
		attackEffect(char2Attack);

		// 99 is returned if a vampire charms opponent
		defendEffect(char1Defense);

		// total damage is difference between attack, defense, and armor
		totalDamage = (char2Attack - char1Defense - char1->getArmor());
		// if negative, then equal 0
		if (totalDamage < 0)
		{
			totalDamage = 0;
		}

		// display total damage to defender; check if turned stone.
		printTotalDamage(char2Attack, totalDamage);

		// calculate remaining strength points for character 2
		char1->calcDamage(totalDamage);
		cout << "Character 1 has " << char1->getStrength() << " strength remaining." << endl;

		// if Character 1 suffered fatal damage, break the loop
		if (char1->isDead())
		{
			cout << "Character 1: " << char1->getType() << " is defeated." << endl;
			cout << "Character 2: " << char2->getType() << " wins!" << endl;
			break;
		}

		cout << endl;
		round++;
	}
}

/***********************************************************
* attackEffect(int)
* Description: Checks if Medusa's stone gaze is active for
* the current turn. Print's the combat information for
* attack.
***********************************************************/
void Game::attackEffect(int n)
{		
	if (n == 100)
	{
		cout << "Attacker roll: Stone gaze instantly defeats." << endl;
	}
	else
	{
		cout << "Attacker roll: " << n << endl;
	}
}

/***********************************************************
* defendEffect(int)
* Description: Checks if Vampire's charm is active for the
* current turn. Prints the combat information for defend.
***********************************************************/
void Game::defendEffect(int n)
{
	if (n == 99)
	{
		cout << "Defender roll: Vampire charms opponent." << endl;
	}
	else
	{
		cout << "Defender roll: " << n << endl;
	}
}

/***********************************************************
* printTotalDamage(int)
* Description: Prints the total damage taken by a defending
* character. Medusa's stone gaze is checked as precaution.
***********************************************************/
void Game::printTotalDamage(int n, int total)
{
	// 100 is value for Medusa's stone gaze
	if (n == 100)
	{
		cout << "Total Damage: Fatal damage" << endl;
	}
	else
	{
		cout << "Total Damage: " << total << endl;
	}
}
