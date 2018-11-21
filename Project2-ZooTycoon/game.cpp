/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Source file for game.cpp; it contains all the game-flow functions
 * for the zoo tycoon game.
*******************************************************************************/
#include "game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

/*******************************************************************************
 * Game()
 * Default constructor that initializes each animal to to Null. Each type of
 * animal has its own array, which is dynamically allocated. The player's
 * starting bank is also initialized.
*******************************************************************************/
Game::Game() {
	// Initializes starting arrays to 10, per assignment requirements.
	tigers = new Animal *[10];
	penguins = new Animal *[10];
    turtles = new Animal *[10];
	tigerSize = penguinSize = turtleSize = 10;
	tigerNum = penguinNum = turtleNum = 0;

	// Initializes all elements
	for (int i = 0; i < 10; i++) {
		tigers[i] = NULL;
		penguins[i] = NULL;
		turtles[i] = NULL;
	}

	bank = 100000;
	attendanceBonus = 0;
	attendanceBoom = false;
}

/*******************************************************************************
 * ~Game()
 * Description: Default destructor.
*******************************************************************************/
Game::~Game()
{}

/*******************************************************************************
 * addAnimal()
 * Description: Creates an animal and stores it into its respective type array.
 * The function will check for the animal type and use a specific type function
 * to add the animal.
*******************************************************************************/
void Game::addAnimal(Animal *a) {
	if (a->getType() == "Tiger") {
		addTiger(a);
	} else if (a->getType() == "Penguin") {
		addPenguin(a);
	} else if (a->getType() == "Turtle") {
		addTurtle(a);
	}
}

/*******************************************************************************
 * addTiger()
 * Description: Adds a tiger to the tigers array at the next available element.
 * First checks if the array needs to be resized.
*******************************************************************************/
void Game::addTiger(Animal *a) {
	// check if last element is occupied; recreate the larger array.
	if (tigers[tigerSize-1] != NULL) {
		resizeArray(tigers, tigerSize);
	}

	// add the new animal to the next available element, which is the current
	// value of tigerNum (total tigers).
	tigers[getTigerNum()] = a;
	tigerNum++;
}

/*******************************************************************************
 * addPenguin()
 * Description: Adds a penguin to the penguins array at the next available
 * element. Fist checks if the array needs to be resized.
*******************************************************************************/
void Game::addPenguin(Animal *a) {
	if (penguins[penguinSize-1] != NULL) {
		resizeArray(penguins, penguinSize);
	}
	penguins[getPenguinNum()] = a;
	penguinNum++;
}

/*******************************************************************************
 * addTurtle()
 * Description: Adds a turtle to the turtles array at the next available
 * element. First checks if the array needs to be resized.
*******************************************************************************/
void Game::addTurtle(Animal *a) {
	if (turtles[turtleSize-1] != NULL) {
		resizeArray(turtles, turtleSize);
	}
	turtles[getTurtleNum()] = a;
	turtleNum++;
}

/*******************************************************************************
 * resizeArray()
 * Description: Resizes an animal array to twice as large.  The old array is
 * moved to the new array, and the old array is deleted to prevent memory leaks.
*******************************************************************************/
void Game::resizeArray(Animal **&array, int &size) {

	Animal **temp = new Animal *[size * 2];

	for (int i = 0; i < (size * 2); i++) {
		temp[i] = NULL;
	}

	for (int i = 0; i < size; i++) {
		temp[i] = array[i];
	}

	delete [] array;
	array = temp;
	size *= 2;
}

/*******************************************************************************
 * printInventory()
 * Description: Prints out the number of owned animals and the bank.
*******************************************************************************/
void Game::printInventory() {
	cout << "-------------" << endl;
	cout << "--Inventory--" << endl;
	cout << "Bank: " << getBank() << endl;
	cout << "Tigers: " << getTigerNum() << endl;
	cout << "Penguins: " << getPenguinNum() << endl;
	cout << "Turtles: " << getTurtleNum() << endl;
	cout << "-------------" << endl;
}


/*******************************************************************************
 * deleteAnimals()
 * Description: Deletes all animal arrays to free memory.
*******************************************************************************/
void Game::deleteAnimals() {
	for (int i = 0; i < (getTigerNum() - 1); i++) {
		delete tigers[i];
	}
	delete [] tigers;

	for (int i = 0; i < (getPenguinNum() - 1); i++) {
		delete penguins[i];
	}
	delete [] penguins;

	for (int i = 0; i < (getTurtleNum() - 1); i++) {
		delete turtles[i];
	}
	delete [] turtles;
}


/*******************************************************************************
 * getTigerNum()
 * Description: Returns the total number of tigers.
*******************************************************************************/
int Game::getTigerNum() {
	return tigerNum;
}


/*******************************************************************************
 * getPenguinNum()
 * Description: Returns the total number of penguins.
*******************************************************************************/
int Game::getPenguinNum() {
	return penguinNum;
}


/*******************************************************************************
 * getTurtleNum()
 * Description: Returns the total number of turtles.
*******************************************************************************/
int Game::getTurtleNum() {
	return turtleNum;
}

/*******************************************************************************
 * getBank()
 * Description: Returns the money amount in the player's bank.
*******************************************************************************/
int Game::getBank() {
	return bank;
}

/*******************************************************************************
 * increaseBank()
 * Description: Adds money to the player's bank.
*******************************************************************************/
void Game::increaseBank(int x) {
	bank += x;
}

/*******************************************************************************
 * decreaseBank()
 * Description: Subtracts money from the player's bank.
*******************************************************************************/
void Game::decreaseBank(int x) {
	bank -= x;
}

/*******************************************************************************
 * payFoodCost()
 * Description: Calculates the total feed cost of all animals.
*******************************************************************************/
int Game::payFoodCost() {
	int i = 0, j = 0, k = 0;
	int tempFoodCost = 0;

	while (tigers[i] != NULL) {
		tempFoodCost += tigers[i]->getFoodCost();
		i++;
	}

	while (penguins[j] != NULL) {
		tempFoodCost += penguins[j]->getFoodCost();
		j++;
	}

	while (turtles[k] != NULL) {
		tempFoodCost += turtles[k]->getFoodCost();
		k++;
	}

	return tempFoodCost;
}

/*******************************************************************************
 * calculatePayoff()
 * Description: Calculates the total payoff of all animals.
*******************************************************************************/
int Game::calculatePayoff() {
	int i = 0, j = 0, k = 0;
	int tempPayoff = 0;

	while (tigers[i] != NULL)	{
		tempPayoff += tigers[i]->getPayoff();
		i++;
	}

	while (penguins[j] != NULL)	{
		tempPayoff += penguins[j]->getPayoff();
		j++;
	}

	while (turtles[k] != NULL)	{
		tempPayoff += turtles[k]->getPayoff();
		k++;
	}

	return tempPayoff;
}

/*******************************************************************************
 * sickTiger()
 * Description: Deletes the last element of the tigers array.
*******************************************************************************/
void Game::sickTiger() {
	// checks if any tigers exist in the first element.
	if (tigers[0] != NULL) {
		delete tigers[getTigerNum() - 1];		// delete last tiger element.
		tigers[getTigerNum() - 1] = NULL;		// set element to NULL.
		tigerNum--;							    // decrease total tigers.
	}
}


/*******************************************************************************
 * sickPenguin()
 * Description: Deletes the last element of the penguins array.
*******************************************************************************/
void Game::sickPenguin() {
	if (penguins[0] != NULL) {
		delete penguins[getPenguinNum() - 1];
		penguins[getPenguinNum() - 1] = NULL;
		penguinNum--;
	}
}


/*******************************************************************************
 * sickTurtle()
 * Description: Deletes the last element of the turtles array.
*******************************************************************************/
void Game::sickTurtle() {
	if (turtles[0] != NULL)	{
		delete turtles[getTurtleNum() - 1];
		turtles[getTurtleNum() - 1] = NULL;
		turtleNum--;
	}
}


/*******************************************************************************
 * randomEvent()
 * Description: Chooses a random condition for the day.
*******************************************************************************/
void Game::randomEvent() {
	cout << "Random Event: ";

	switch (rand() % 4 + 1)	{
		case 1:
			cout << "An animal has become sick." << endl;
			sickAnimal();
			break;

		case 2:
			cout << "There has been a boom in attendance." << endl;
			boomAttendance();
			break;

		case 3:
			cout << "A baby animal has been born." << endl;
			babyAnimal();
			break;

		case 4:
			cout << "None! It's another normal day." << endl;
			break;
	}
}

/*******************************************************************************
 * sickAnimal()
 * Description: Chooses a random animal and removes it from the game.  First,
 * checks if the user has any of each type of animal. Then, a random type is
 * chosen and the last animal is removed from the array.
*******************************************************************************/
void Game::sickAnimal() {
	int i = 0;
	bool hasAnimals = false;
	bool hasTigers = false;
	bool hasPenguins = false;
	bool hasTurtles = false;
	bool isSick = false;

	// check if the player owns any animals and any type of animal
	while (hasAnimals == false) {
		if (tigers[0] != NULL)
		{
			hasTigers = true;
			hasAnimals = true;
		}
		if (penguins[0] != NULL) {
			hasPenguins = true;
			hasAnimals = true;
		}
		if (turtles[0] != NULL) {
			hasTurtles = true;
			hasAnimals = true;
		}
	}

	// if the player owns any animals, check a random type of animal.
	// if one is found, that animal becomes sick.
	if (hasAnimals = true)	{
		while (isSick == false) {
			switch (rand() % 3 + 1)	{
				case 1:
					if (hasTigers == false) {
						break;
					} else {
						cout << "A tiger has died." << endl;
						sickTiger();
						isSick = true;
						break;
					}

				case 2:
					if (hasPenguins == false) {
						break;
					} else {
						cout << "A penguin has died." << endl;
						sickPenguin();
						isSick = true;
						break;
					}

				case 3:
					if (hasTurtles == false) {
						break;
					} else {
						cout << "A turtle has died." << endl;
						sickTurtle();
						isSick = true;
						break;
					}
			}
		}
	} else {
		cout << "You don't have any animals, so none can become sick." << endl;
	}
}

/*******************************************************************************
 * boomAttendance()
 * Description: A condition of the random event function, where an attendance
 * boom generates a bonus 250-500 dollars for each tiger owned by the player.
*******************************************************************************/
void Game::boomAttendance() {
	attendanceBonus = 0;

	if (getTigerNum() == 0) {
		cout << "You do not own any tigers, so you do not get a bonus." << endl;
	} else {
		int roll = (rand() % 250 + 1) + 250;		// random integer between 250 and 500.
		attendanceBonus = getTigerNum() * roll;		// multiply by total tigers.

		cout << "Each of your tigers generate a bonus of $" << roll << endl;
		cout << "The total bonus is " << attendanceBonus << "!" << endl;

		increaseBank(attendanceBonus);
	}
}


/*******************************************************************************
 * babyAnimal()
 * Description: Randomly chooses a type of animal then checks to see if any
 * adults exist. If so, then babies are born. Animal type affects how many
 * babies are born.
*******************************************************************************/
void Game::babyAnimal() {
	int i = 0, j = 0, k = 0;
	bool hasAdults = false;
	bool bornStatus = false;

	// first check if any adults exist for each animal type
	while (tigers[i] != NULL) {
		if(tigers[i]->getAge() >= 3) {
			hasAdults = true;
		}
		i++;
	}

	while (penguins[j] != NULL)	{
		if (penguins[j]->getAge() >= 3) {
			hasAdults = true;
		}
		j++;
	}

	while (turtles[k] != NULL) {
		if (turtles[k]->getAge() >= 3) {
			hasAdults = true;
		}
		k++;
	}

	i = 0;

	// if adults exist, cycle a random animal type until
	// an adult is found.  Then, create the new animal(s).
	if (hasAdults) {
		while(!bornStatus) {
			switch (rand() % 3 + 1) {
				case 1:
					while (tigers[i] != NULL) {
						if (tigers[i]->getAge() >= 3) {		// If there is an adult.
							cout << "A baby tiger is born." << endl;
							addAnimal(new Tiger(0));		// Add 1 tiger, age 0
							bornStatus = true;
							break;
						}
						i++;
					}
					break;

				case 2:
					while (penguins[i] != NULL) {
						if (penguins[i]->getAge() >= 3) {
							cout << "5 baby penguins are born." << endl;
							for (int i = 0; i < 5; i++) {
								addAnimal(new Penguin(0));		// Add 5 penguins, age 0
							}
							bornStatus = true;
							break;
						}
						i++;
					}
					break;

				case 3:
					while (turtles[i] != NULL) {
						if (turtles[i]->getAge() >= 3) {
							cout << "10 baby turtles are born." << endl;
							for (int i = 0; i < 10; i++) {
								addAnimal(new Turtle(0));		// Add 10 turtles, age 0.
							}
							bornStatus = true;
							break;
						}
						i++;
					}
					break;
			}
		}
	} else {
		cout << "No babies were born because there are no adult animals." << endl;
	}
}


/*******************************************************************************
 * ageAnimals()
 * Description: Ages all the animals in the exhibit. First checks if the player
 * owns any of each animal type, then ages the animals of that type.
*******************************************************************************/
void Game::ageAnimals() {
	int i = 0, j = 0, k = 0;

	while (tigers[i] != NULL) {
        tigers[i]->increaseAge();
		i++;
	}

	while (penguins[j] != NULL) {
		penguins[j]->increaseAge();
		j++;
	}

	while (turtles[k] != NULL) {
		turtles[k]->increaseAge();
		k++;
	}
}


/*******************************************************************************
 * introduction()
 * Description: Introduction menu that shows game rules and information. This is
 * used after the user confirms to play the game.  Initial purchasing menu is in
 * this function and requires the user to purchase at least 1 or 2 of each type
 * of animal.
*******************************************************************************/
void Game::introduction() {
	int pTigers = pPenguins = pTurtles = 0;

	cout << "----------Zoo Tycoon----------" << endl;
	cout << "Welcome to the Zoo Tycoon simulator!" << endl;
	cout << "You get to run your very own zoo!" << endl;
	cout << "But before you begin, you need to purchase animals." << endl;
	cout << "You have $100,000 in your bank." << endl << endl;

	cout << "How many tigers will you purchase? Each costs $10,000." << endl;
	cout << "Enter: 1 or 2" << endl;
	getInt(pTigers, 1, 2);

	if (pTigers == 1) {
		addAnimal(new Tiger());
		decreaseBank(10000);
		cout << "You purchased 1 tiger." << endl;
	} else if (pTigers == 2) {
		addAnimal(new Tiger());
		addAnimal(new Tiger());
		decreaseBank(20000);
		cout << "You purchased 2 tigers." << endl;
	}

	cout << "Bank: $" << getBank() << endl;
	cout << "How many penguins will you purchase? Each costs $1,000." << endl;
	cout << "Enter: 1 or 2" << endl;
	getInt(pPenguins, 1, 2);

	if (pPenguins == 1)	{
		addAnimal(new Penguin());
		decreaseBank(1000);
		cout << "You purchased 1 penguin." << endl;
	} else if (pPenguins == 2) {
		addAnimal(new Penguin());
		addAnimal(new Penguin());
		decreaseBank(2000);
		cout << "You purchased 2 penguins." << endl;
	}

	cout << "Bank: $" << getBank() << endl;
	cout << "How many turtles will you purchase? Each costs $100." << endl;
	cout << "Enter: 1 or 2" << endl;
	getInt(pTurtles, 1, 2);

	if (pTurtles == 1) {
		addAnimal(new Turtle());
		decreaseBank(100);
		cout << "You purchased 1 turtle." << endl;
	} else if (pTurtles == 2) {
		addAnimal(new Turtle());
		addAnimal(new Turtle());
		decreaseBank(200);
		cout << "You purchased 2 turtles." << endl;
	}
}

/*******************************************************************************
 * purchaseAdultAnimal()
 * Description: Prompts user to purchase an adult animal at the end of each
 * game day. Bank is checked to confirm if purchase can be made. Animal is added
 * to its type array and the cost is deducted from the player bank.
*******************************************************************************/
void Game::purchaseAdultAnimal() {
	bool makePurchase = false;
	int choice = 0;

	cout << "Bank: $" << getBank() << endl;
	cout << "Would you like to purchase an adult animal?" << endl;
	cout << "Enter: Y(Yes) or N(No)" << endl;
	getBool(makePurchase);

	while (makePurchase) {
        cout << "Which type of adult animal will you purchase?" << endl;
        cout << "1. Tiger" << endl;
        cout << "2. Penguin" << endl;
        cout << "3. Turtle" << endl;
        getInt(choice, 1, 3);

		switch (choice) {
			case 1: // tiger
				if (getBank() > 10000) {
					addAnimal(new Tiger(3));
					decreaseBank(10000);
					cout << "You purchased an adult tiger." << endl;
					makePurchase = false;
				} else {
					cout << "You cannot afford an adult tiger." << endl;
				}
				break;

			case 2: // penguin
				if (getBank() > 1000) {
					addAnimal(new Penguin(3));
					decreaseBank(1000);
					cout << "You purchased an adult penguin." << endl;
					makePurchase = false;
				} else {
					cout << "You cannot afford an adult penguin." << endl;
				}
				break;

			case 3: // turtle
				if (getBank() > 100) {
					addAnimal(new Turtle(3));
					decreaseBank(100);
					cout << "You purchased an adult turtle." << endl;
					makePurchase = false;
				} else {
					cout << "You cannot afford an adult turtle." << endl;
				}
				break;
		}
	}
}


/*******************************************************************************
 * play()
 * Description: Primary member function for the game flow. Before each game day,
 * the player bank is checked for a positive balance. Animals age at the beginning
 * of each day, and the player first must pay the foodCost of all animals. A
 * random event is encountered and the player earns profit for animals owned. At
 * the end of the day, the player can purchase an animal or exit the game.
*******************************************************************************/
void Game::play() {
	introduction();

	bool gameFlow = true;

	while(gameFlow) {
		totalFoodCost = 0;
		totalPayoff = 0;

		if (getBank() <= 0) {
			cout << "You have no money. The zoo has to close..." << endl;
			gameFlow = false;
		}

		cout << "*******************************" << endl;
		cout << "Day " << day << endl;

		ageAnimals();

		printInventory();

		totalFoodCost = payFoodCost();
		decreaseBank(totalFoodCost);
		cout << "It costs $" << totalFoodCost << " to feed your animals." << endl;

		randomEvent();

		totalPayoff = calculatePayoff();
		increaseBank(totalPayoff);
		cout << "Your animals earn you $" << totalPayoff << " profit." << endl;

		purchaseAdultAnimal();

		cout << "Continue the game?" << endl;
		cout << "Enter: Y(Yes) or N(No)" << endl;
		getBool(gameFlow);

		day++;
	}

	deleteAnimals();
}
