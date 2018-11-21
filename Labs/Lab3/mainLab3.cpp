/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/15/18
 * Description: Main function for the game War. Uses classes Die, LoadedDie, and
 * Game to simulate a dice game War.
*******************************************************************************/

#include "die.hpp"
#include "loadedDie.hpp"
#include "game.hpp"
#include <iostream>
#include <string>

int main()
{
	Game war;
	war.menu();
	war.play();
	war.results();
	
	return 0;
}
