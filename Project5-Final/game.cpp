/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Source file for the class Game.
***********************************************************/
#include "game.hpp"

using std::cout;
using std::endl;

/***********************************************************
* Game()
* Description: Default constructor; initializes all the game
* Spaces, and sets pointers to surrounding rooms.
***********************************************************/
Game::Game()
{
	// initialize all game Spaces
	player = new Player();
	home = new Home();
	basement = new Basement();
	van = new Van();
	crosswalk = new Crosswalk();
	park = new Park();
	concert = new Concert();
	currentSpace = NULL;

	// set the current space
	currentSpace = home;

	// set pointers to adjacent Spaces
	home->setDown(basement);
	home->setRight(van);

	basement->setUp(home);
	basement->setRight(van);

	van->setLeft(home);
	van->setDown(basement);
	van->setRight(crosswalk);

	crosswalk->setUp(concert);
	crosswalk->setDown(park);
	crosswalk->setLeft(van);

	park->setUp(crosswalk);

	concert->setDown(crosswalk);
}


/***********************************************************
* ~Game()
* Description: Destructor that frees created memory from
* Spaces. 
***********************************************************/
Game::~Game()
{
	delete currentSpace;
	delete home;
	delete basement;
	delete van;
	delete crosswalk;
	delete park;
	delete concert;
	delete player;
}


/***********************************************************
* play()
* Description: Initiates the gameflow; player has 90 minutes
* to get to the Concert.  Inventory and Location is displayed
* for each turn--or choice.  When, or if, the player reaches
* the Concert, the result is determined based on time
* remaining and items collected throughout the game.
***********************************************************/
void Game::play()
{
	cout << "BEEP. BEEP. BEEP. 5:00 PM" << endl;
	cout << "'Dude...I overslept again..." << endl;
	cout << "'I need to be on stage by 6:30. The world needs my music.'";
	cout << endl << endl;

	cout << "Jimmy Jams is a very chill rockstar. It takes him 10" << endl;
	cout << " minutes to move to a new location. Also, the more " << endl;
	cout << "time he has to spare, the better he will perform." << endl;
	cout << "Jimmy needs your help to get to the Concert." << endl;

	// while time is not 90 mins or Jimmy reaches final destination
	while (player->getTime() < 9 && currentSpace != concert)
	{
		cout << "====================" << endl;
		cout << "Time: " << player->getTime() << "0 mins" << endl;
		cout << "Inventory: ";
		player->printInventory();
		cout << endl;

		printMap(currentSpace);

		// display the information of the current room
		currentSpace->description();

		// set the new current room depending on
		// player choice in the called function
		currentSpace = currentSpace->playerChoice(player);

		player->increaseTime(1);
	}

	// final stage of game; either Jimmy made it to
	// the concert or exceeded time limit
	if (currentSpace == concert)
	{
		// display info and choice for space Concert
		printMap(currentSpace);
		currentSpace->description();
		currentSpace->playerChoice(player);
		
		// show the game results
		showResult(player);
		finalResult(win);
	}
	else
	{
		cout << "Oh no. Jimmy didn't play at the concert." << endl;
		cout << "The world did not hear his music, and somehow " << endl;
		cout << "wars began and the world was annihilated." << endl;
		cout << "Game Over..." << endl;
	}
}

/***********************************************************
* printMap()
* Description: Prints the game map with the player location.
***********************************************************/
void Game::printMap(Space *s)
{
	switch (s->getLocation())
	{
		case HOME:
		{
			cout << "                   Concert " << endl;
			cout << "  MAP            | '''''' |" << endl;
			cout << "                 |        |" << endl;
			cout << "                 | ______ |" << endl;
			cout << "                     ^     " << endl;
			cout << "                     |     " << endl;
			cout << "                     v     " << endl;
			cout << "                 ======    " << endl;
			cout << "               > ======    " << endl;
			cout << "               |     ^     " << endl;
			cout << " ______        v__   |     " << endl;
			cout << "| Home |     _/  |   |     " << endl;
			cout << "|  J   |<--> O---O   v     " << endl;
			cout << "|   ___|           |     | " << endl;
			cout << "|__| _ |           |     | " << endl;
			cout << "                   |_____| " << endl;
			break;
		}
		case BASEMENT:
		{
			cout << "                   Concert " << endl;
			cout << "  MAP            | '''''' |" << endl;
			cout << "                 |        |" << endl;
			cout << "                 | ______ |" << endl;
			cout << "                     ^     " << endl;
			cout << "                     |     " << endl;
			cout << "                     v     " << endl;
			cout << "                 ======    " << endl;
			cout << "               > ======    " << endl;
			cout << "               |     ^     " << endl;
			cout << " ______        v__   |     " << endl;
			cout << "| Home |     _/  |   |     " << endl;
			cout << "|      |<--> O---O   v     " << endl;
			cout << "|   ___|           |     | " << endl;
			cout << "|__| J |           |     | " << endl;
			cout << "                   |_____| " << endl;
		}
		case VAN:
		{
			cout << "                   Concert " << endl;
			cout << "  MAP            | '''''' |" << endl;
			cout << "                 |        |" << endl;
			cout << "                 | ______ |" << endl;
			cout << "                     ^     " << endl;
			cout << "                     |     " << endl;
			cout << "                     v     " << endl;
			cout << "                 ======    " << endl;
			cout << "               > ======    " << endl;
			cout << "               |     ^     " << endl;
			cout << " ______        v__   |     " << endl;
			cout << "| Home |     _/ J|   |     " << endl;
			cout << "|      |<--> O---O   v     " << endl;
			cout << "|   ___|           |     | " << endl;
			cout << "|__| _ |           |     | " << endl;
			cout << "                   |_____| " << endl;
			break;
		}
		case CROSSWALK:
		{
			cout << "                   Concert " << endl;
			cout << "  MAP            | '''''' |" << endl;
			cout << "                 |        |" << endl;
			cout << "                 | ______ |" << endl;
			cout << "                     ^     " << endl;
			cout << "                     |     " << endl;
			cout << "                     v     " << endl;
			cout << "                 ======    " << endl;
			cout << "               > ==J===    " << endl;
			cout << "               |     ^     " << endl;
			cout << " ______        v__   |     " << endl;
			cout << "| Home |     _/  |   |     " << endl;
			cout << "|      |<--> O---O   v     " << endl;
			cout << "|   ___|           |     | " << endl;
			cout << "|__| _ |           |     | " << endl;
			cout << "                   |_____| " << endl;
			break;
		}
		case PARK:
		{
			cout << "                   Concert " << endl;
			cout << "  MAP            | '''''' |" << endl;
			cout << "                 |        |" << endl;
			cout << "                 | ______ |" << endl;
			cout << "                     ^     " << endl;
			cout << "                     |     " << endl;
			cout << "                     v     " << endl;
			cout << "                 ======    " << endl;
			cout << "               > ======    " << endl;
			cout << "               |     ^     " << endl;
			cout << " ______        v__   |     " << endl;
			cout << "| Home |     _/  |   |     " << endl;
			cout << "|      |<--> O---O   v     " << endl;
			cout << "|   ___|           |     | " << endl;
			cout << "|__| _ |           |  J  | " << endl;
			cout << "                   |_____| " << endl;
			break;
		}
		case CONCERT:
		{
			cout << "                   Concert " << endl;
			cout << "  MAP            | '''''' |" << endl;
			cout << "                 |   J    |" << endl;
			cout << "                 | ______ |" << endl;
			cout << "                     ^     " << endl;
			cout << "                     |     " << endl;
			cout << "                     v     " << endl;
			cout << "                 ======    " << endl;
			cout << "               > ======    " << endl;
			cout << "               |     ^     " << endl;
			cout << " ______        v__   |     " << endl;
			cout << "| Home |     _/  |   |     " << endl;
			cout << "|      |<--> O---O   v     " << endl;
			cout << "|   ___|           |     | " << endl;
			cout << "|__| _ |           |     | " << endl;
			cout << "                   |_____| " << endl;
			break;
		}
	}
}

/***********************************************************
* showResult()
* Description: Prints the game map with the player location.
***********************************************************/
void Game::showResult(Player* p)
{
	// without the guitar, no chance of success
	if (!p->searchInventory("Guitar"))
	{
		cout << "'Oh, no! How will I jam?' cries Jimmy." << endl;
		cout << "The stage director notices Jimmy doesn't " << endl;
		cout << "have a guitar. 'How could you? The world " << endl;
		cout << "needed your music.' he says sadly..." << endl;
		win = false;
		return;	
	}

	// Duck is an arbitrary instant success variable
	if (p->searchInventory("Duck"))
	{
		cout << "Jimmy jams hard on stage. But the crowd " << endl;
		cout << "needs more momentum. At that moment, the " << endl;
		cout << "friendly duck makes a stage entrance and " << endl;
		cout << "the crowd goes wild. The concert is an " << endl;
		cout << "instant success." << endl;
		win = true;
		return;
	}

	// determine time remaining before limit
	int chance = 0;
	chance = p->getTime();

	// happy music helps Jimmy's performance
	if (p->searchInventory("happyCD"))
	{
		chance -= 2;
	}
	
	// roll for the final result after items and
	// time have been calculated.
	win = resultRoll(chance);
}

/***********************************************************
* resultRoll(int)
* Description: Determines the win or loss condition based
* on the passed argument.
***********************************************************/
bool Game::resultRoll(int n)
{
	// roll for the success chance. There are 3 tiers, based
	// on the chance variable previously established.
	int roll = rand() % n;
	
	// if too much time passed
	if (roll > 5)
	{
		return false;
	}
	// 50% chance
	else if(roll > 3)
	{
		roll = rand() % 2;
		if (roll == 0)
		{
			return false;
		}
		return true;
	}
	// if success
	else
	{
		return true;
	} 
}

/***********************************************************
* finalResult()
* Description: Print the final outcome to the screen.
***********************************************************/
void Game::finalResult(bool w)
{
	// case win
	if (w)
	{
		cout << endl;
		cout << "Congratulations! Jimmy has played the best " << endl;
		cout << "concert the world has ever seen. It's all " << endl;
		cout << "thanks to you, virtual player." << endl;
	}
	else if (!w)
	{
		cout << endl;
		cout << "Oh no...Jimmy tried his best, but the crowd " << endl;
		cout << "did not rockout to the concert...Everyone " << endl;
		cout << "becomes angry for the rest of their lives." << endl;
		cout << "Game over!" << endl;
	}
}