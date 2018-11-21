/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Header file for the class Student.
*******************************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"
#include <string>

class Student : public Person
{
	private:
		float gpa;

	public:
		Student();
		Student(string, int, float);
		virtual void do_work();
		virtual void print();
		virtual string getName();
};

#endif
