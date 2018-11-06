/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/01/18
 * Description: Source file for class Ant for the Langton's Ant simulation.
*******************************************************************************/
#include "ant.hpp"

/*******************************************************************************
 * Ant()
 * Descripton: Default constructor for Ant class.
*******************************************************************************/
Ant::Ant() {}


/*******************************************************************************
 * Ant(int, int, int, int)
 * Descripton: Initializes the game board based on user inputs--which are passed
 * as arguments to the function.  The board is dynamically allocated and the
 * ant is placed in its starting coordinate.  The board is printed to output.
*******************************************************************************/
void Ant::setBoard(int r, int c, int sR, int sC) {
  	rows = r;
  	columns = c;
	startR = sR;
	startC = sC;
	direction = NORTH;
	xPos = startC - 1;		// Adjust for 0 index
	yPos = startR - 1;

  	// Dynamically allocate the game board based on user input
	board = new char*[rows];
	for(int i = 0; i < rows; i++)	{
		board[i] = new char[columns];
	}

	// Initialize blank spaces for each cell
	for(int i = 0; i < rows; i++)	{
		for(int j = 0; j < columns; j++) {
			board[i][j] = ' ';
		}
	}

  	// Starting location for ant
  	setAnt();

    cout << "Initial Setup:" << endl;

  	printBoard();

    cout << "-----Prepare to Launch-----" << endl;
}


/*******************************************************************************
 * printBoard()
 * Descripton: Prints the game board to the screen.
*******************************************************************************/
void Ant::printBoard() {
  for (int i = 0; i < rows; i++) {
		  for (int j = 0; j < columns; j++) {
			  cout << board[i][j] << " ";
		  }
		  cout << endl;
	}
}


/*******************************************************************************
 * makeMove()
 * Descripton: Function that "looks ahead" before the ant moves. The current
 * direction determines which case of the switch. Then the board boundaries are
 * checked to prevent extending off the board. If valid, the ant will move to
 * the next location and the new direction is updated.
*******************************************************************************/
void Ant::makeMove() {
	switch (getDirection())	{
		case NORTH:								// --Logic repeats for each case--
      		if ((getY() - 1) < 0) {				// Protects movement off board
        		setDirection(SOUTH);
        		moveAnt();
      		} else {
				if(getNext(-1, 0) == "white") { // White space ahead, turn right
					moveAnt();
					setDirection(EAST);
			  	} else {						// Black space ahead, turn left
					moveAnt();
				  	setDirection(WEST);
			  	}
      		}
			break;

		case EAST:
      		if ((getX() + 1) >= columns) {
        		setDirection(WEST);
        		moveAnt();
      		} else {
			  	if(getNext(0, 1) == "white") {
				  	moveAnt();
				  	setDirection(SOUTH);
			  	} else {						
				  	moveAnt();
				  	setDirection(NORTH);
			  	}
      		}
			break;

		case SOUTH:
      		if((getY() + 1) >= rows) {
        		setDirection(NORTH);
        		moveAnt();
      		} else {
			  	if(getNext(1, 0) == "white") {
				  	moveAnt();
				  	setDirection(WEST);
			  	} else {
				  	moveAnt();
				  	setDirection(EAST);
			  	}
      		}
			break;

		case WEST:
      		if((getX() - 1) < 0) {
        		setDirection(EAST);
        		moveAnt();
      		} else {
			  	if(getNext(0, -1) == "white") {
				  	moveAnt();
				  	setDirection(NORTH);
			  	} else {
				  	moveAnt();
				  	setDirection(SOUTH);
			  	}
      		}
			break;
	}
	printBoard();
}


/*******************************************************************************
 * moveAnt()
 * Descripton: Moves the ant to the new location. Border boundaries have already
 * been validated and depending on the current direction, the initial cell is
 * flipped in color and the ant is moved to the intended cell.
*******************************************************************************/
void Ant::moveAnt() {
	switch(getDirection()) {
		case NORTH:								// --Logic repeats for each case--
			if(getNext(-1, 0) == "white") {		// flip the color of the cell
				setCurrent("black");
			} else {						
				setCurrent("white");
			}
			setY(-1);							// Update new ant coordinates
			setAnt();							// Move the ant
			break;

		case EAST:
			if(getNext(0, 1) == "white") {	
				setCurrent("black");		
			} else {						
				setCurrent("white");		
			}
			setX(1);				
			setAnt();					
			break;

		case SOUTH:
			if(getNext(1, 0) == "white") {	
				setCurrent("black");		
			} else {						
				setCurrent("white");		
			}
			setY(1);				
			setAnt();					
			break;

		case WEST:
			if(getNext(0, -1) == "white") {	
				setCurrent("black");		
			} else {						
				setCurrent("white");		
			}
			setX(-1);				
			setAnt();					
			break;
	}
}


/*******************************************************************************
 * getDirection()
 * Descripton: Returns the current ant direction.
*******************************************************************************/
cardinal Ant::getDirection() {
	return direction;
}


/*******************************************************************************
 * setDirection(cardinal)
 * Descripton: Assigns a new cardinal value to the direction variable.
*******************************************************************************/
void Ant::setDirection(cardinal d) {
	direction = d;
}


/*******************************************************************************
 * getX()
 * Descripton: Returns the X position.
*******************************************************************************/
int Ant::getX() {
	return xPos;
}


/*******************************************************************************
 * setX(int)
 * Descripton: Assigns a new value to xPos.
*******************************************************************************/
void Ant::setX(int x) {
	xPos += x;
}


/*******************************************************************************
 * getY()
 * Descripton: Returns the Y position.
*******************************************************************************/
int Ant::getY() {
	return yPos;
}


/*******************************************************************************
 * setY(int)
 * Descripton: Assigns a new value to yPos.
*******************************************************************************/
void Ant::setY(int y) {
	yPos += y;
}


/******************************************************************************
 * getNext()
 * Description: Returns a string ("black" or "white") of a specific location.
 * Used to determine the ant's next move. 
*******************************************************************************/
std::string Ant::getNext(int y, int x) {
	int newY = yPos + y;
	int newX = xPos + x;
	
	if (board[newY][newX] == '#') {
		return "black";
	} else {
		return "white";
	}
}


/******************************************************************************
 * setCurrent(string)
 * Description: Accepts a string argument and sets the board cell to the char
 * output associated with the color.
*******************************************************************************/
void Ant::setCurrent(string s) {
	if (s == "black") {
		board[yPos][xPos] = '#';
	} else if (s == "white") {
		board[yPos][xPos] = ' ';
	}
}


/*******************************************************************************
 * setAnt()
 * Descripton: Assigns the ant to the current board position.
*******************************************************************************/
void Ant::setAnt() {
	board[yPos][xPos] = '*';
}


/*******************************************************************************
 * deleteBoard()
 * Descripton: Deallocates the game board.
*******************************************************************************/
void Ant::deleteBoard() {
	for(int i = 0; i < rows; i++) {
		delete [] board[i];
	}
	delete [] board;
}	