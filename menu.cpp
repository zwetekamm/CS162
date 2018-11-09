/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/1/18
 * Description: Menu function which presents a menu to the user. User provides
 * input which is implemented to other programs.
*******************************************************************************/
#include "menu.hpp"
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::toupper;


// validate user input for an integer
void getInt(int& input, int min, int max) {
    string temp;
    bool valid;

    do {
        valid = true;
        getline(cin, temp);

        for (int i = 0; i < temp.length(); i++) {
            if (!isdigit(temp[i])) {
                valid = false;
            }
        }

        // if not an integer
        if (!valid) {
            cout << "Please enter an integer." << endl;
        }

        // if user only presses Enter
        if (temp.length() < 1) {
            valid = false;
            cout << "Must enter a value." << endl;
        }

        // check for negative input
        if (temp[0] == '-' && valid) {
            valid = false;
            cout << "Integer must be positive." << endl;
        }
    }
    while(!valid);

    input = std::atoi(temp.c_str());

    if (input < min || input > max) {
        cout << "Must be within range." << endl;
        getInt(input, min, max);
    }
}


// validate user input for character or string only
void getString(string& input) {
    string temp;
    bool valid;

    do {
        valid = true;
        getline(cin, temp);

        for (int i = 0; i < temp.length(); i++) {
            if (i > 0 && isdigit(temp[i])) {
                valid = false;
            }
        }

        if (!valid) {
            cout << "String cannot have numbers." << endl;
        }

        // if user only presses Enter
        if (temp.length() < 1) {
            valid = false;
            cout << "Must enter a value." << endl;
        }
    }
    while(!valid);

    input = temp;
}


//validate user input for boolean; will adjust for each project assignment
void getBool(bool& input) {
    string temp;
    bool valid;

    do {
        valid = true;
        getline(cin, temp);

        for (int i = 0; i < temp.length(); i++) {
            if (!isalpha(temp[i])) {
                valid = false;
            } else {
                // Convert to uppercase and validate Y or N
                temp[i] = toupper(temp[i]);
                if (temp[i] != 'Y' && temp[i] != 'N') {
                    valid = false;
                }
            }
        }

        if (!valid) {
            cout << "Enter only Y or N." << endl;
        }

        // if user only presses Enter
        if (temp.length() < 1) {
            valid = false;
            cout << "Must enter a value." << endl;
        }
    }
    while(!valid);

    if(temp[0] == 'Y') {
        input = true;
    } else if(temp[0] == 'N') {
        input = false;
    }
}

