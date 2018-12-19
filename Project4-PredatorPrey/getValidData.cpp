/*************************************************************************
 * Date:         July 29, 2018
 * Description:  This is the implementation file for the function getValidData().
 *               This function has a parameter of a user variable (does not have
 *               to be initialized) of type int or double. The function gets a
 *               string value from the user, checks if it is a valid integer or
 *               double, and prints error messages if the user does not enter
 *               the correct data type. The function continues in a loop until
 *               the user provides a valid entry. It then converts the string to
 *               an integer or double and stores this value in the variable
 *               passed by reference. It also checks against minimum and maximum
 *               values. The function is overloaded so that the user may pass
 *               an integer or double by reference to get the correct data type.
 *
 *               (This is Michael's utility function.)
 *******************************************************************************/
#include <string>
#include <iostream>

using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;
using std::stoi;
using std::stod;

//Function for getting and validating a single integer from the user
void getValidData(int &userInt, int min, int max)
{
    string userInput;
    bool isValid;

    do
    {
        isValid = true;

        //Gets value from the user, temporily stored as a string
        getline(cin, userInput);

        //Checks if entry is an integer (assumes the user did not just press enter)
        for (int x = 0; x < userInput.length(); x++)
        {
            //Checks if the first character is a digit or negative sign
            if (x == 0 && !isdigit(userInput[x]) && userInput[x] != '-')
            {
                isValid = false;
            }

            //Checks if all subsequent characters are digits
            if (x > 0 && !isdigit(userInput[x]))
            {
                isValid = false;
            }
        }

        //Displays appropriate error message if needed
        if (!isValid)
        {
            cout << "Invalid Input - An integer only consists of digits and a possible negative sign." << endl;
        }

        //Checks if the user simply pressed enter
        if (userInput.length() < 1)
        {
            isValid = false;
            cout << "Invalid Input - Do not simply press enter." << endl;
        }

        //Checks additional errors with negative numbers
        if (userInput[0] == '-' && isValid)
        {
            //Checks if the user simply entered a negative sign
            if (userInput.length() < 2)
            {
                isValid = false;
                cout << "Invalid Input - You may not simply enter a negative sign." << endl;
            }

            //Checks against the entry of a negative zero
            if (userInput.length() == 2 && userInput[1] == '0')
            {
                isValid = false;
                cout << "Invalid Input - You may not enter negative zero." << endl;
            }

            //Checks if the input is too low to be held by an int variable (below -2,147,483,648)
            if (userInput.length() > 11)
            {
                isValid = false;
                cout << "Invalid Input - This is too extreme of a value." << endl;
            }

            //Does an additional check on whether or not the input is too low
            if (userInput.length() == 11 && isValid)
            {
                //Converts the highest five digits into an integer
                char first[6] = {userInput[1], userInput[2], userInput[3], userInput[4], userInput[5]};
                string firstHalf = first;
                int higherDigits = stoi(firstHalf);

                //Converts the lowest five digits into an integer
                char second[6] = {userInput[6], userInput[7], userInput[8], userInput[9], userInput[10]};
                string secondHalf = second;
                int lowerDigits = stoi(secondHalf);

                //Compares if the absolute value of the user entry is greater than 2,147,483,648
                if (higherDigits >= 21474)
                {
                    if (higherDigits > 21474 || lowerDigits > 83648)
                    {
                        isValid = false;
                        cout << "Invalid Input - This is too extreme of a value." << endl;
                    }
                }
            }
       } 

       //Performs additional checks for errors with positive values
       if (isdigit(userInput[0]) && isValid)
       { 
            //Checks if the input is too high to be held by an int variable (above 2,147,483,647)
            if (userInput.length() > 10)
            {
                isValid = false;
                cout << "Invalid Input - This is too extreme of a value." << endl;
            }

            //Does an additional check on whether or not the input is too high
            if (userInput.length() == 10 && isValid)
            {
                //Converts the highest five digits into an integer
                char first[6] = {userInput[0], userInput[1], userInput[2], userInput[3], userInput[4]};
                string firstHalf = first;
                int higherDigits = stoi(firstHalf);

                //Converts the lowest five digits into an integer
                char second[6] = {userInput[5], userInput[6], userInput[7], userInput[8], userInput[9]};
                string secondHalf = second;
                int lowerDigits = stoi(secondHalf);

                //Compares if the value of the user entry is greater than 2,147,483,647
                if (higherDigits >= 21474)
                {
                    if (higherDigits > 21474 || lowerDigits > 83647)
                    {
                        isValid = false;
                        cout << "Invalid Input - This is too extreme of a value." << endl;
                    }
                }
            }
        }
        
        //If there was an invalid input, gets a new value from the user to once again verify if it is valid
        if (!isValid)
        {
            cout << "Please enter a new value: ";
        }

    } while(!isValid);
        
    //Converts the valid input and stores it in the integer variable passed by reference
    userInt = stoi(userInput);

    if (userInt < min || userInt > max)
    {
        cout << "Invalid Input - You must enter a value in the range of " << min << "-" << max << "." << endl;
        cout << "Please enter a new value: ";
        getValidData(userInt, min, max);
    }
}

//Function for getting and validating a single double from the user
void getValidData(double &userDouble, double min, double max)
{
    string userInput;
    bool isValid;

    do
    {
        isValid = true;

        //Gets value from the user, temporily stored as a string
        getline(cin, userInput);

        //Checks if entry is a double (assumes the user did not just press enter)
        for (int x = 0; x < userInput.length(); x++)
        {
            //Checks if the first character is a digit, negative sign, or decimal point
            if (x == 0 && !isdigit(userInput[x]) && userInput[x] != '-' && userInput[x] != '.')
            {
                isValid = false;
            }

            //Checks if all subsequent characters are digits or decimal points
            if (x > 0 && !isdigit(userInput[x]) && userInput[x] != '.')
            {
                isValid = false;
            }
        }

        //Displays appropriate error message if needed
        if (!isValid)
        {
            cout << "Invalid Input - A double only consists of digits, a decimal point, and a possible negative sign." << endl;
        }

        //Checks if the user simply pressed enter
        if (userInput.length() < 1)
        {
            isValid = false;
            cout << "Invalid Input - Do not simply press enter." << endl;
        }

        //Checks additional errors with negative numbers
        if (userInput[0] == '-' && isValid)
        {
            //Checks if the user simply entered a negative sign
            if (userInput.length() < 2)
            {
                isValid = false;
                cout << "Invalid Input - You may not simply enter a negative sign." << endl;
            }

            //Checks against the entry of a negative zero
            if (userInput.length() == 2 && userInput[1] == '0')
            {
                isValid = false;
                cout << "Invalid Input - You may not enter negative zero." << endl;
            }

            //Checks if the input is extremely low and could cause a loss of significant digits (below -1,000,000,000,000,000)
            if (userInput.length() > 17)
            {
                isValid = false;
                cout << "Invalid Input - Such a long value could result in the loss of significant digits." << endl;
            }
       } 

       //Performs additional checks for errors with positive values
       if (isdigit(userInput[0]) && isValid)
       { 
            //Checks if the input is extremely high and could cause a loss of significant digits
            if (userInput.length() > 16)
            {
                isValid = false;
                cout << "Invalid Input - Such a long value could result in the loss of significant digits." << endl;
            }
        }

        //Performs checks on multiple decimal points being used
        int decAccum = 0;

        for (int x = 0; x < userInput.length(); x++)
        {
            if (userInput[x] == '.')
            {
                decAccum++;
            }
        }

        if (decAccum > 1)
        {
            isValid = false;
            cout << "Invalid Input - You may only use one decimal point." << endl;
        }
        
        //If there was an invalid input, gets a new value from the user to once again verify if it is valid
        if (!isValid)
        {
            cout << "Please enter a new value: ";
        }

    } while(!isValid);
        
    //Converts the valid input and stores it in the double variable passed by reference
    userDouble = stod(userInput);

    if (userDouble < min || userDouble > max)
    {
        cout << "Invalid Input - You must enter a value in the range of " << min << "-" << max << "." << endl;
        cout << "Please enter a new value: ";
        getValidData(userDouble, min, max);
    }
}
