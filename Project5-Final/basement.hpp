/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Header file for the class Basement.
***********************************************************/
#ifndef BASEMENT_HPP
#define BASEMENT_HPP

#include "space.hpp"

class Basement : public Space
{
	private:
		Space *up;
		Space *right;
		Space *down;
		Space *left;
		Location BASEMENT;

	public:
		Basement();
		virtual ~Basement();
		virtual void description();
		Space *playerChoice(Player*);
		virtual void addGuitar(Player*);
		virtual void eatPizza(Player*);
		virtual void setUp(Space*);
		virtual void setRight(Space*);
		virtual void setDown(Space*);
		virtual void setLeft(Space*);
		virtual Space *getUp();
		virtual Space *getRight();
		virtual Space *getDown();
		virtual Space *getLeft();
		virtual Location getLocation();
};

#endif