/**********************************************************
* Author: Zachary Wetekamm
* Date : 8/12/18
* Description: Header file for the class Queue.
**********************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "menu.hpp"
#include <queue>
#include <iostream>
#include <string>

class Queue
{
	private:
		int n;
		int nChance;
		int rounds;
		double average;
		double averagePrev;
		double count;		
		std::queue<int> buffer;
		std::queue<int> q;

	public:
		Queue();
		int randomNum(int);
		void simulation(int, int, int);	
		void print();
		double calculateAverage();
};

#endif