#include <iostream>
#include <math.h>
using namespace std;

//checkINTERSECT function prototype: Will check to see if squares intersect
bool checkINTERSECT(int x1TL, int y1TL, int x1BR, int y1BR, int x2TL, int y2TL, int x2BR, int y2BR);

int main() {

    int x1TL, y1TL,
        x1BR, y1BR,
        x2TL, y2TL,
        x2BR, y2BR,
        area1, area2;
    
    //Asks user to input values for first square
    cout << "Enter the information for the first square" << endl;
    cout << "x-coordinate: " << endl;
    cin >> x1TL;
    //Makes sure the correct type of input was entered
    if (cin.fail()) {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Inncorrect Input type!" << endl;
        return 0;
    }

    cout << "y-coordinate: " << endl;
    cin >> y1TL;
    if (cin.fail()) {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Inncorrect Input type!" << endl;
        return 0;
    }

    cout << "area: " << endl;
    cin >> area1;
    if (cin.fail()) {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Inncorrect Input type!" << endl;
        return 0;
    }
    //Value of area can't be negative
    if (area1 < 0) {
        cout << "Error: Incorrect Input!" << endl;
        return 0;
    }

    //Asks user for values of second square
    cout << "Enter the information for the second square" << endl;
    cout << "x-coordinate: " << endl;
    cin >> x2TL;
    if (cin.fail()) {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Inncorrect Input type!" << endl;
        return 0;
    }

    cout << "y-coordinate: " << endl;
    cin >> y2TL;
    if (cin.fail()) {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Inncorrect Input type!" << endl;
        return 0;
    }

    cout << "area: " << endl;
    cin >> area2;
    if (cin.fail()) {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Inncorrect Input type!" << endl;
        return 0;
    }
    if (area2 < 0) {
        cout << "Error: Incorrect Input!" << endl;
        return 0;
    }

    //Finds the bottom right coordinate of first square
    x1BR = x1TL + sqrt(area1);
    y1BR = y1TL - sqrt(area1);

    //Find the bottom right coordinate of the second square
    x2BR = x2TL + sqrt(area2);
    y2BR = y2TL - sqrt(area2);    

    if(checkINTERSECT(x1TL, y1TL, x1BR, y1BR, x2TL, y2TL, x2BR, y2BR)) {
        cout << "THE SQUARES INTERSECT" << endl;
    }
    else {
        cout << "THE SQUARES DO NOT INTERSECT" << endl;
    }

    return 0;
}

bool checkINTERSECT(int x1TL, int y1TL, int x1BR, int y1BR, int x2TL, int y2TL, int x2BR, int y2BR) {
    /*The reasoning behind these if statements is that if the top left x-coordinate of square 1 is greater than 
    the x-coordinate of the the bottom right of square 2, that means square one is to the right of square 2 and
    they do not overlap. This holds true for the reverse as well. So if either is true, then the squares
    do not overlap.
    If the top left y-coordinate of the first square is less than the bottom right y-coordinate of the
    second square, than the first square is below the second square and they do not overlap. This holds
    true for the reverse as well. So if either is true, then the squares do not overlap.
    If all four conditions fail, then the squares overlap. 
    */
    //Check if one square is to the right of the other
    if(x1TL > x2BR || x2TL > x1BR) {
        return false;
    }
    //Check if one square is beneath the other
    else if(y1TL < y2BR || y2TL < y1BR) {
        return false;
    }
    else {
        return true;
    }
}