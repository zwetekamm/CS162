/**********************************************************
* Author: Zachary Wetekamm
* Date : 8/12/18
* Description: Source file for the class Stack.
**********************************************************/
#include "stack.hpp"
#include <iostream>

using std::string;

/**********************************************************
* Stack()
* Description: Constructor for Stack.
**********************************************************/
Stack::Stack()
{
	resultString = "";	
}


/**********************************************************
* palindrome(string)
* Description: Concatenates a series of characters into a
* string, which is reversed as a palindrome in this case.
**********************************************************/
string Stack::palindrome(string input)
{
	// dynamically allocate a character array
	char* temp = new char[input.length()+1];
	std::strcpy(temp, input.c_str());

	// push each character to the stack
	for (int i = 0; i < input.length(); i++)
	{
		stk.push(temp[i]);
	}

	// go through and concatenate each stack element
	while (!stk.empty())
	{
		// add an element to result, pop off stack
		resultString += stk.top();
		stk.pop(); 
	}

	// free created memory
	delete [] temp;
	
	// initialize the new result with palindrome
	resultString = input + resultString;

	return resultString;
}
