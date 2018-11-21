/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Header file for game.cpp.
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "menu.hpp"

class Game {
	private:
		Animal **tigers;
		Animal **penguins;
		Animal **turtles;
		int tigerSize;
		int penguinSize;
		int turtleSize;
		int tigerNum;
		int penguinNum;
		int turtleNum;
		int bank;
		int day = 1;
		int totalFoodCost;
		int totalPayoff;
		int attendanceBonus;
		bool attendanceBoom;

	public:
		Game();
		~Game();
		void addAnimal(Animal*);
		void addTiger(Animal*);
		void addPenguin(Animal*);
		void addTurtle(Animal*);
		void resizeArray(Animal**&, int&);
		void printInventory();
		void deleteAnimals();
		int getTigerNum();
		int getPenguinNum();
		int getTurtleNum();
		int getBank();
		void increaseBank(int);
		void decreaseBank(int);
		int payFoodCost();
		int calculatePayoff();
		void sickTiger();
		void sickPenguin();
		void sickTurtle();
		void randomEvent();
		void sickAnimal();
		void boomAttendance();
		void babyAnimal();
		void ageAnimals();
		void introduction();
		void purchaseAdultAnimal();
		void play();
};

#endif
