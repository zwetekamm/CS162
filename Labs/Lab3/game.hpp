/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/15/18
 * Description: Header file for the Game class
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "die.hpp"
#include "loadedDie.hpp"
#include <iostream>
#include <string>

class Game
{
	private:
		Die *die1;
		Die *die2;
		bool choice;
		int rounds;
		int sides1;
		int sides2;
		bool typeP1;
		bool typeP2;
		char type1;
		char type2;
		int turnsArr[50][2];
		int player1Wins;
		int player2Wins;
				
	public:
		Game();
		void menu();
		void introduction();
		void getInt(int&);
		void getBool(bool&);
		void play();
		void results();
};

#endif
