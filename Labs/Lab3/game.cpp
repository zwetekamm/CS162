/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/15/18
 * Description: Source file for the Game class, which contains a game menu for
 * user input and displays the results of the game.
*******************************************************************************/

#include "game.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::rand;
using std::toupper;

/*********************************************************************
 * Game()
 * Defalut constructor to initialize die1 and die2
*********************************************************************/
Game::Game()
{
	die1 = NULL;
	die2 = NULL;
}

/*********************************************************************
 * menu()
 * Displays the game menu, which gets all input from the user that is
 * required for gameplay.  Also validates input.
*********************************************************************/
void Game::menu()
{
	// function to begin or exit program
	introduction();
	
	// get total rounds for game
	do
	{
		cout << "How many rounds will be played? ";
		getInt(rounds);

		// validate within arbitrary range
		if (rounds < 1)
			cout << "Must be greater than 1." << endl;
		else if (rounds > 50)
			cout << "Must be less than or equal to 50" << endl;
	}
	while (rounds < 1 || rounds > 50);

	
	// get sides for player 1
	do
	{	
		cout << "Player 1: how many sides for the die? ";
		getInt(sides1);

		// validate within arbitrary range
		if (sides1 < 1)
			cout << "Must be greater than 1." << endl;
		else if (sides1 > 10)
			cout << "Must be less than or equal to 10" << endl;
	}
	while (sides1 < 1 || sides1 > 10);


	// Get choice for die type for player 1
	cout << "Player 1: use loaded die? (Y/N) ";
    getBool(typeP1);

    if (typeP1 == true)
	{
		die1 = new LoadedDie(sides1);
	}
	else
	{
		die1 = new Die(sides1);
	}


	// get sides for player 2
	do
	{
		cout << "Player 2: how many sides for the die? ";
		getInt(sides2);

		// validate within arbitrary range
		if (sides2 < 1)
			cout << "Must be greater than 1." << endl;
		else if (sides2 > 50)
			cout << "Must be less than or equal to 50" << endl;
	}
	while (sides2 < 1 || sides2 > 10);


	// get choice for die type for player 2
	cout << "Player 2: use loaded die? (Y/N) ";
    getBool(typeP2);

    if (typeP2 == true)
	{
		die2 = new LoadedDie(sides2);
	}
	else
	{
		die2 = new Die(sides2);
	}
}

/*********************************************************************
 * introduction()
 * Displays the introduction menu. Validates input of 1 or 2, and 
 * continues or exits the program based on input.
*********************************************************************/
void Game::introduction()
{
	cout << "Hello. Let's play a dice game of War." << endl;
	cout << "Choose a Loaded or Unloaded Die for each player." << endl;
	cout << "Unloaded die roll a random number up to the number of sides you choose." << endl;
	cout << "Loaded die has a 25% chance to roll max value or a zero. Choose wisely!" << endl;
	cout << "1. Play game" << endl;
	cout << "2. Exit game" << endl;

	int choice;

	do
	{
		cin >> choice;
 
		if (std::cin.fail())
		{
			cout << "Invalid choice. Enter 1 or 2. " << endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}

		if (choice == 2)
		{
			exit(0);
		}

		else if (choice == 1)
		{
			break;
		}
	}
	while (choice != 1 || choice != 2);
}

/*********************************************************************
 * getInt()
 * Validates integer input from user
*********************************************************************/
void Game::getInt(int& input)
{
	int x;
	bool invalid;

	do
	{
		invalid = false;
		cin >> x;

		if(std::cin.fail())
		{
			invalid = true;
			cout << "Input is invalid. Must be an integer." << endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
	}
	while(invalid);

	input = x;
}

/*********************************************************************
 * getBool()
 * Validates input for user to choice of Yes or No
*********************************************************************/
void Game::getBool(bool& input)
{
	char c;
	bool invalid;

	do
	{
		invalid = false;
		cin >> c;

		// convert c to uppercase
		c = toupper(c);

		if(std::cin.fail())
		{
			invalid = true;
			cout << "Input is invalid. Try again." << endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}

		else if(c != 'Y' && c != 'N')
		{
			invalid = true;
			cout << "Input is invalid. Must enter Y or N." << endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
	}
	while(invalid);

	if(c == 'Y')
		input = true;
	else if(c == 'N')
		input = false;
}


/*********************************************************************
 * play()
 * Begins gameplay using roll function for both Die and LoadedDie 
 * classes. Results are stored as a 2D array.
*********************************************************************/
void Game::play()
{
	for (int i=0; i < rounds; i++)
	{
		turnsArr[i][0] = die1 -> roll();
		turnsArr[i][1] = die2 -> roll();
	}
}

/*********************************************************************
 * results()
 * Displays the game results for each round, including dice types
 * requested by the user, and final scores for each round and end
 * of the game.
*********************************************************************/
void Game::results()
{
	cout << "Rounds played: " << rounds << endl;
	cout << "Player 1 uses " << die1 -> getType() << " die with " << die1 -> getSides() << " sides." << endl;
	cout << "Player 2 uses " << die2 -> getType() << " die with " << die2 -> getSides() << " sides." << endl;

	cout << "P1" << "\t" <<  "P2" << endl;

	player1Wins = 0;
	player2Wins = 0;

	//display result for each round
	for(int i=0; i < rounds; i++)
	{
		cout << turnsArr[i][0] << "\t" << turnsArr[i][1];

		if(turnsArr[i][0] > turnsArr[i][1])
		{
			//increment point total and show round winner
			player1Wins++;
			cout << "\t" << "Player 1 wins." << endl;
		}
		else if(turnsArr[i][0] < turnsArr[i][1])
		{
			//increment point total and show round winner
			player2Wins++;
			cout << "\t" << "Player 2 wins." << endl;
		}
		else
			cout << "\t" << "Draw." << endl;
	}

	cout << "Player 1 wins " << player1Wins << " times." << endl;
	cout << "Player 2 wins " << player2Wins << " times." << endl;

	if(player1Wins > player2Wins)
	{
		cout << "Player 1 wins the game." << endl;
	}
	else if(player2Wins > player1Wins)
	{
		cout << "Player 2 wins the game." << endl;
	}
	else
	{
		cout << "Result is a draw." << endl;
	}
}

