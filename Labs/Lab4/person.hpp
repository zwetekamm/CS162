/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Header file for the class Person.
*******************************************************************************/ 

#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::string;

class Person
{
	protected:
		string name;
		int age;
		
	public:
		Person();
		virtual ~Person();
		Person(string, int);
		virtual void do_work() = 0;
		virtual void print();
		virtual string getName();
};

#endif
