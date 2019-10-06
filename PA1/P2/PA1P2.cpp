#include <iostream>
#include <math.h>
using namespace std;

bool checkINTERSECT(int x1TL, int y1TL, int x1BR, int y1BR, int x2TL, int y2TL, int x2BR, int y2BR);

int main() {

    int x1TL, y1TL,
        x1BR, y1BR,
        x2TL, y2TL,
        x2BR, y2BR,
        area1, area2;
    
    
    cout << "Enter the information for the first square" << endl;
    cout << "x-coordinate: " << endl;
    cin >> x1TL;

    cout << "y-coordinate: " << endl;
    cin >> y1TL;

    cout << "area: " << endl;
    cin >> area1;

    cout << "Enter the information for the second square" << endl;

    cout << "x-coordinate: " << endl;
    cin >> x2TL;

    cout << "y-coordinate: " << endl;
    cin >> y2TL;

    cout << "area: " << endl;
    cin >> area2;

    x1BR = x1TL + sqrt(area1);
    y1BR = y1TL - sqrt(area1);

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
    if(x1TL > x2BR || x2TL > x1BR) {
        return false;
    }
    else if(y1TL < y2BR || y2TL < y1BR) {
        return false;
    }
    else {
        return true;
    }
}