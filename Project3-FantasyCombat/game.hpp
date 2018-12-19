/***********************************************************
* Author: Zachary Wetekamm
* Date: 08/05/18
* Description: Header file for the base class Game.
***********************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "menu.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"

class Game
{
	private:
		Character *char1;
		Character *char2;

	public:
		Game();
		~Game();
		void play();
		void menu();
		void fight();
		void attackEffect(int);
		void defendEffect(int);
		void printTotalDamage(int, int);
};

#endif
