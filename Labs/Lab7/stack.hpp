/**********************************************************
* Author: Zachary Wetekamm
* Date : 8/12/18
* Description: Header file for the class Stack.
**********************************************************/
#ifndef STACK_HPP
#define STACK_HPP

#include <stack>
#include <iostream>
#include <string>
#include <cstring>

using std::string;

class Stack
{
	private:
		std::stack<char> stk;
		string resultString;

	public:
		Stack();
		string palindrome(string);
};

#endif
