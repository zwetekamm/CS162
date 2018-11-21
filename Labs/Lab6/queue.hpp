/**********************************************************
* Author: Zachary Wetekamm
* Date : 8/5/18
* Description: Header file for the class Queue.
**********************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "menu.hpp"

class Queue
{
	struct QueueNode
	{
		int val;
		QueueNode *next;
		QueueNode *prev;
		QueueNode (int v, QueueNode* next = NULL)
		{
			val = v;
		}
	};

	private:
		QueueNode *head;

	public:
		Queue();
		~Queue();
		bool isEmpty();
		void addBack(int);
		int getFront();
		void removeFront(int&);
		void printQueue();
		void menu();
};

#endif