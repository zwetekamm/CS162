
#include "queue.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

/**********************************************************
* Queue()
* Description: Default constructor. 
**********************************************************/
Queue::Queue()
{
	head = NULL;
}

/**********************************************************
* ~Queue()
* Description: Default destructor. Navigates the queue and
* deletes each pointer until all are NULL.
**********************************************************/
Queue::~Queue()
{
	QueueNode *temp = head;
	while (temp != NULL)
	{
		QueueNode *garbage = temp;
		temp = temp->next;
		delete garbage;
	}	
}

/**********************************************************
* isEmpty()
* Description: If queue is empty, return true. 
**********************************************************/
bool Queue::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**********************************************************
* addBack(int)
* Description: Creates a QueueNode with an integer argument
* and appends it to the back of the list.
**********************************************************/
void Queue::addBack(int val)
{
	if (isEmpty())
	{
		// if first item in queue
		head = new QueueNode(val);
	}
	else
	{
		// check queue for empty pointer
		// (Figure 17-3 in text, p.1046)
		QueueNode *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		// create new node at end of queue
		temp->next = new QueueNode(val);	
	}
}

/**********************************************************
* getFront()
* Description: Returns the value of node at front of queue. 
**********************************************************/
int Queue::getFront()
{
	if (head == NULL)
	{
		cout << "The queue is empty." << endl;
	}
	else
	{
		return head->val;
	}
}

/**********************************************************
* removeFront()
* Description: Removes the front QueueNode and frees the
* memory.
**********************************************************/
void Queue::removeFront(int &n)
{
	QueueNode *temp = NULL;
	if (isEmpty())
	{
		cout << "The queue is empty." << endl;
	}
	else
	{
		// move current head value to temp and update
		// the new head to next in queue; delete old head.
		n = head->val;
		temp = head;
		head = head->next;
		delete temp;
	}
}

/**********************************************************
* printQueue()
* Description: Traverses through the queue from head using
* next pointers, and prints the values of each QueueNode
* in the queue.
**********************************************************/
void Queue::printQueue()
{
	if (head == NULL)
	{
		cout << "The queue is empty." << endl;
	}
	else
	{
		QueueNode *temp = head;
		cout << "Your Queue is: ";

		// using a temp pointer, naviagate each next
		// pointer in the queue
		while (temp != NULL)
		{
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

/**********************************************************
* menu()
* Description: Displays the main menu, where the user
* selects from various commands to control the queue.
**********************************************************/
void Queue::menu()
{
	int choice;

	cout << "Lab 6: Circular Linked List" << endl;
	cout << "1. Begin Program" << endl;
	cout << "2. Exit Program" << endl;
	getInt(choice, 1, 2);

	if (choice == 2)
	{
		cout << "Exiting..." << endl;
		std::exit(0);
	}

	while (true)
	{
		choice = 0;

		cout << "1. Add a value to the back of queue" << endl;
		cout << "2. Display the front value" << endl;
		cout << "3. Remove the front node" << endl;
		cout << "4. Display the queue's content" << endl;
		cout << "5. Exit" << endl;
		getInt(choice, 1, 5);

		switch (choice)
		{
			case 1:	// add value to back of queue
			{
				int n = 0;
				cout << "Enter an integer to add to queue: " << endl;
				getInt(n, 1, 9999);
				addBack(n);
				break;
			}
			
			case 2:	// display front value
			{
				if (isEmpty())
				{
					cout << "The queue is empty." << endl;
					break;
				}

				cout << "Front node: " << getFront() << endl;
				break;
			}
			
			case 3: // remove front node
			{
				if (isEmpty())
				{
					cout << "The queue is empty." << endl;
					break;
				}

				int n = getFront();
				removeFront(n);
				break;
			}
			
			case 4: // display queue's content
			{
				printQueue();
				break;
			}

			case 5: // exit
			{
				std::exit(0);
				break;
			}
		}
	}
}