/**********************************************************
* Author: Zachary Wetekamm
* Date : 8/12/18
* Description: Source file for the class Queue.
**********************************************************/
#include "queue.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>

using std::cout;
using std::endl;


/**********************************************************
* Queue())
* Description: Constructor for Queue.
**********************************************************/
Queue::Queue()
{
	average = 0.0;
	averagePrev = 0.0;
	count = 1.0;
}

/**********************************************************
* randomNum(int, int)
* Description: Returns a randomly generated number between
* 1 and a specific max.
**********************************************************/
int Queue::randomNum(int nMax)
{
	int max = nMax;
	int randomNum = 0;

	randomNum = rand() % max + 1;

	return randomNum;
}


/**********************************************************
* simulation(int, int, int)
* Description: Queue simulation. 
* The following is the flow of each round in the simulation:
* 1. Generate a random number from 1 – 1000 called N.
* 2. Appending number: Generate another random number from 
* 	 1 – 100, if the outcome is less than or equal to the 
*		 user specified percentage for adding value, then append 
*		 the number N into the queue.
*	3. Removing numbers: Generate another random number from 
*		 1 – 100, if the outcome is less than or equal to the 
* 	 user specified percentage for removing value, then 
* 	 remove a number from the front of queue.
* 4. Output the values in the buffer and the buffer length.
* 5. Output the average length of buffer.
**********************************************************/
void Queue::simulation(int nRounds, int addChance, int rmvChance)
{
	rounds = nRounds;
	
	for (int i = 0; i < rounds; i++)
	{
		cout << "-------" << endl;
		cout << "Round: " << i + 1 << endl;

		// 1. random integer n 1-1000
		n = randomNum(1000);

		// 2. Append number
		nChance = randomNum(100);
		if (nChance <= addChance)
		{
			cout << "Added: " << n << endl;
			// push value n to queue
			buffer.push(n);
		}
		else
		{
			cout << "Added: None" << endl;
		}

		// 3. Remove number
		nChance = randomNum(100);
		if (nChance <= rmvChance)
		{
			if (!buffer.empty())
			{
				cout << "Removed: " << buffer.front() << endl;
				// pop front value from queue
				buffer.pop();
			}
		}
		else
		{
			cout << "Removed: None" << endl;
		}

		// 4. Output buffer contents and size
		print();
		cout << "Buffer size: " << buffer.size() << endl;

		// 5. Output average length
		cout << "Average length: " << calculateAverage() << endl;
	}
}

/**********************************************************
* print()
* Description: Prints the contents of the buffer.
**********************************************************/
void Queue::print()
{
	if (buffer.empty())
	{
		cout << "Buffer is empty." << endl;
	}
	else
	{
		int temp = 0;
		cout << "Buffer contents: ";

		// copy elements to a temporary queue
		while (!buffer.empty())
		{
			// print first element in buffer
			cout << buffer.front() << " ";

			// copy to temp, pop, and repeat
			temp = buffer.front();
			q.push(temp);
			buffer.pop();
		}

		// swap back to original queue
		std::swap(q, buffer);	
		cout << endl;	
	}
}

/**********************************************************
* calculateAverage()
* Description: Calculates the average length of the buffer.
* Equation: ALi = (ALi-1 * (i – 1) + Li ) / i
* where ALi and ALi-1 are the average length in the ith and
* (i-1)th round, Li is buffer length in the ith round.
**********************************************************/
double Queue::calculateAverage()
{
	// update the previous round average
	averagePrev = average;

	// calculate new average give assignment formula
	average = (averagePrev * (count-1) + buffer.size()) / count;
	
	count++;

	return average;
}
