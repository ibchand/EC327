#include "View.h"

View::View() {
    this -> size=11; //Sets size to 11
    this -> scale=2; //Sets scale to 2
    this -> origin=Point2D(0,0); //Sets the origin to PointD(0,0)
}

void View::Clear() {
    //Iterates through the x-axis
    for (int i=0; i<size; i++) {
        //Iterates through the y-axis
        for (int j=0; j<size; j++) {
            grid[i][j][0]='.'; //First layer
            grid[i][j][1]=' '; //Second layer
        }
    }
}

void View::Plot(GameObject* ptr) {
    int x,
        y;
    
    //Checks if Subscripts are valid
    bool IsValid=GetSubscripts(x,y,ptr -> GetLocation());
    //If the subscripts are valid
    if (IsValid) {
        //If there's an object already plotted, replaces characters with an '*'
        if (grid[x][y][0] != '.') {
            grid[x][y][0] = '*';
            grid[x][y][1] = ' ';
        }
        else {
            char* CHARizard = new char; //Creates a char pointer on the heap
            ptr -> DrawSelf(CHARizard); //Calls DrawSelf function from GameObject Class
            grid[x][y][0]=*CHARizard;
            grid[x][y][1]=*(CHARizard+1); //Plots Object
            delete CHARizard; //Deletes CHARizard from the heap
        }
    }
}

void View::Draw() {
	/*So first you start off by checking if it's an even row. If so, you draw the axis value,
	then the objects and dots. Then you keep moving row by row until you reach the x-axis.
	Then you go column by column filling in the x-axis values and then you're done*/

	//Iterates through the rows
	for (int row = this -> size-1; row>=0; row--) {
		//If even row, then draw axis #
		if (row % 2 == 0) {
			//If single digit, add extra space
			if (row* this -> scale < 10) {
				cout << row * this -> scale << " ";
			}
			else {
				cout << row * this -> scale; //Prints with no space is double digit
			}
		}
		else {
			cout << "  "; //If odd, print 2 blank spaces
		}

		//Iterates through columns, printing
		for (int col=0; col< this-> size; col++) {
			cout << this -> grid[col][row][0] << this -> grid[col][row][1];
		}
		cout << endl; //Move to newline after finishing row
	}

	//Now need to display x-axis, start two spaces over
	cout << "  ";
	for (int col = 0; col < this -> size; col++) {
		//Checks if col is even, if so, print axis value
		if (col % 2 == 0) {
			//If single digit, print extra space
			if (col * this -> scale < 10) {
				cout << col * this -> scale << " ";
			}
			else {
				cout << col * this -> scale;
			}
		}
		else {
			cout << "  "; //Print two blank spaces if odd
		}
	}
	cout << endl; //Print a new line for clarity
}

//Calculate the column and row subscripts of the grid array that corresspon to the supplied location
bool View::GetSubscripts(int &out_x, int &out_y, Point2D location) {
    Vector2D vec=(location- this -> origin) / this -> scale; //X and Y values for subscripts
    vec.x=(int)vec.x; //Truncate Value by casting to an int
    vec.y=(int)vec.y; //Truncate Value by casting to an int

    //If the subscripts are within the size of the grid being displayed
    if ((vec.x <= this -> size* this -> scale) && (vec.y <= this -> size* this -> scale)) {
        out_x=vec.x; //Assigns X value
        out_y=vec.y; //Assigns Y value
        return true; //Returns true if subscripts are valid
    }
    else {
        cout << "An object is outside the display" << endl;
        return false;
    }
}
