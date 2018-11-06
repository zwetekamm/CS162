/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/1/18
 * Description: Header file for the class Ant.
*******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//variables for ant movement direction
enum cardinal {NORTH, EAST, SOUTH, WEST};

class Ant
{
	private:
		cardinal direction;
		char **board;
		int rows,
			columns,
			startR,
			startC,
			xPos,
			yPos;

	public:
    	Ant();
		void setBoard(int, int, int, int);
		void printBoard();
		void makeMove();
		void moveAnt(); 
		void setDirection(cardinal);
		cardinal getDirection();
		int getX();
		void setX(int);
		int getY();
		void setY(int);
		string getNext(int, int);
		void setCurrent(string);
		void setAnt();
		void deleteBoard();
};

#endif