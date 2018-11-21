/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Header file for the class Instructor.
*******************************************************************************/ 

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "person.hpp"
#include <iostream>
#include <string>

using std::string;

class Instructor : public Person
{
	protected:
		float rating;

	public:
		Instructor();
		~Instructor();
		Instructor(string, int, float);
		virtual void do_work();
		virtual void print();
		virtual string getName();
};

#endif
