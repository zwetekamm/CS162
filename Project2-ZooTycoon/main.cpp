/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Main function for the Zoo Tycoon game, which uses the classes
 * Animal, Tiger, Penguin, Turtle, and Game.
*******************************************************************************/

#include "game.hpp"
#include <iostream>
#include <string>

int main() {
    cout << "CS 162 Project 2: Zoo Tycoon" << endl;
    cout << "Programmed by: Zachary Wetekamm" << endl << endl;

    int begin;

    cout << "1. Begin Zoo Tycoon Simulator" << endl;
    cout << "2. Exit the Program" << endl;
    getInt(begin, 1, 2);

    if (begin == 2) {
        cout << "Exiting..." << endl;
        return 1;
    }

    srand(time(NULL));

	Game zoo;

	zoo.play();

	delete zoo;

	return 0;
}
