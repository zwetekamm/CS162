/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Header file for the class Game.
***********************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "home.hpp"
#include "basement.hpp"
#include "van.hpp"
#include "crosswalk.hpp"
#include "park.hpp"
#include "concert.hpp"

#include <iostream>
#include <string>

class Game
{
	private:
		Player *player;
		Space *currentSpace;
		Space *home;
		Space *basement;
		Space *van;
		Space *crosswalk;
		Space *park;
		Space *concert;
		bool win;

	public:
		Game();
		~Game();
		void play();
		void printMap(Space*);
		void showResult(Player*);
		bool resultRoll(int);
		void finalResult(bool);
};

#endif