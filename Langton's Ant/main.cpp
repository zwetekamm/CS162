/*****************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/01/18
 * Description: Main file for Langton's Ant simulation, which uses the class
 * Ant and functions from menu.cpp for input validation. The ant will move
 * around a board with parameters set by the user. The ant changes direction
 * based on the 'color' of the next board--white space (' ') turn right, black
 * space ('#') turn left. Each time the ant ('*') moves onto any cell, it
 * changes the color to opposite.
*****************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "ant.hpp"
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "CS 162 Project 1: Langton's Ant" << endl;
    cout << "Programmed by: Zachary Wetekamm" << endl;
    cout << "Extra Credit: Ask user for random starting location." << endl << endl;

    int start;

    // Begin or exit; validates input
    cout << "1. Begin Langton's Ant Simulation" << endl;
    cout << "2. Exit the program" << endl;
    getInt(start, 1, 2);

    if (start == 2) {
        cout << "Exiting..." << endl;
        return 1;
    }

    int nRows,
        nColumns,
        nSteps,
        nStartRow,
        nStartCol,
        steps = 1;
    bool randomStart;	//extra credit variable

    cout << "How many rows for the board?" << endl;
    getInt(nRows, 1, 15000);

    cout << "How many columns for the board?" << endl;
    getInt(nColumns, 1, 15000);

    cout << "How many steps will the ant take?" << endl;
    getInt(nSteps, 1, 15000);

    cout << "Begin the ant at a random location? Y for yes, N for no. " << endl;
    getBool(randomStart);

    // If user confirms a random starting location for the ant
    if(randomStart)	{
        nStartRow = rand() % nRows + 1;
        nStartCol = rand() % nColumns + 1;

        cout << "Ant will begin on row " << nStartRow << " and column " << nStartCol << endl << endl;
    } else {
        cout << "At which row will the ant begin? Must be within range." << endl;
        getInt(nStartRow, 1, nRows);

        cout << "At which column will the ant begin? Must be witin range." << endl;
        getInt(nStartCol, 1, nColumns);
    }

    Ant game;

    // Dynamically allocate the game board
    game.setBoard(nRows, nColumns, nStartRow, nStartCol);

    // Begin the simulation
    while(steps <= nSteps) {
        cout << "Step " << steps << ":" << endl;
        game.makeMove();
        steps++;
    }

    // Free the allocated memory
    game.deleteBoard();

    return 0;
}
