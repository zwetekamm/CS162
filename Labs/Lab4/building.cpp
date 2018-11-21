/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Source file for the class Building.
*******************************************************************************/ 
#include "building.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/*******************************************************************************
* Building()
* Description: Default Constructor
*******************************************************************************/
Building::Building()
{}

/*******************************************************************************
* ~Building()
* Description: Default Destructor
*******************************************************************************/
Building::~Building()
{}

/*******************************************************************************
* Building(string, int, string)
* Description: Constructs a Building object using 3 parameters.
*******************************************************************************/
Building::Building(string name, int size, string address)
{
  this->name = name;
  this->size = size;
  this->address = address;
}
/*******************************************************************************
* print()
* Description: Prints all Building information. 
*******************************************************************************/
void Building::print()
{
  cout << "Building: " << name << endl;
  cout << "Size: " << size << endl;
  cout << "Address: " << address << endl;
}