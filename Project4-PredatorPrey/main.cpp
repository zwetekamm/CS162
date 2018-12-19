/*************************************************************************
 * Date:         July 29, 2018
 * Description:  This program simulates a predator-prey relationship
 *               between Doodlebugs (predators) and Ants (prey). It sets
 *               up a grid of Ants and Doodlebugs and then has them move,
 *               potentially breed, potentially eat, and potentially
 *               starve each time step. It will run simulations until the
 *               user decides to quit.
 ************************************************************************/
#include "Grid.hpp"
#include "readMenu.hpp"
#include "getValidData.hpp"
#include <iostream>
#include <string>
#include <ctime>

using std::cout;
using std::endl;
using std::string;

int main()
{
    int numRows;
    int numCols;
    int numDBugs;
    int numAnts;

    //Sets up calls to rand within the classes
    unsigned seed = time(0);
    srand(seed);

    string menuItems[] = {"Default", "Customized"};

    //Prints out opening messages
    cout << "This program simulates a predator-prey scenario where" << endl;
    cout << "Doodlebugs (represented by Xs) are the predators" << endl;
    cout << "and Ants (represented by 0s) are the prey." << endl << endl;
    cout << "EXTRA CREDIT: This allows the user to specify" << endl;
    cout << "the initial values of the Grid." << endl << endl;

    //Has the user set up the board according to default or customizable settings
    cout << "How would you like to set up the board?" << endl;
    int choice = readMenu(menuItems, 2);

    //Default
    if (choice == 1)
    {
        numRows = 20;
        numCols = 20;
        numDBugs = 5;
        numAnts = 100;
    }

    //Gets information for a customized setup
    else
    {
        cout << endl << "Enter a number of rows 5-50: ";
        getValidData(numRows, 5, 50);
        cout << "Enter a number of columns 5-50: ";
        getValidData(numCols, 5, 50);
        cout << "Enter a number of Doodlebugs 1-249: ";
        getValidData(numDBugs, 1, 249);
        cout << "Enter a number of Ants 1-249: ";
        getValidData(numAnts, 1, 249);
    }

    //Creates the grid and declares variables to run the game
    Grid grid(numRows, numCols, numDBugs, numAnts);
    int count;
    int timeSteps = 0;
    int continueChoice;
    string continueMenu[] = {"Continue Simulation", "Quit"};

    //Prints out the initial state of the board
    cout << endl << "Here is your initial board:" << endl;
    grid.printGrid();

    //Runs the simulation until the user decides to quit
    do
    {
        //Gets how many time steps the user wants to simulate
        cout << endl << "Enter 1-1000 time steps to simulate: " ;
        getValidData(count, 1, 1000); 

        //Simulates the time steps
        for (int x = 0; x < count; x++)
        {
            grid.addTimeSteps();
            timeSteps++;
            grid.callMoves();
            grid.callBreeds();
            grid.callStarves();

            //Prints out the time step and the board
            cout << endl << "Board at Time Step # " << timeSteps << ":" << endl;
            grid.printGrid();
        }

        //Checks if they would like to stop or continue
        cout << endl << "What would you like to do?" << endl;
        continueChoice = readMenu(continueMenu, 2);

    } while (continueChoice == 1);

    return 0;
}
