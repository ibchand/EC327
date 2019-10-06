#include <iostream>
#include "PA1P1.h"
#include <string>
using namespace std;

double let2num(string classX) {
    double value;

    if (classX=="A") {
        value=4.0;
    }
    else if (classX=="A-") {
        value=3.7;
    }
    else if (classX=="B+") {
        value=3.3;
    }
    else if (classX=="B") {
        value=3.0;
    }
    else if (classX=="B-") {
        value=2.7;
    }
    else if (classX=="C+") {
        value=2.3;
    }
    else if (classX=="C") {
        value=2.0;
    }
    else if (classX=="C-") {
        value=1.7;
    }
    else if (classX=="D") {
        value=1.0;
    }
    else if (classX=="F") {
        value=0;
    }
    else {
        cout << "Error: let2num, else triggered!" << endl;
        value=-1;
    }
    return value;
}
//A (4.0), A- (3.7), B+ (3.3), B (3.0), B- (2.7), C+ (2.3), C (2.0), C- (1.7), D (1.0), F(0)

double calcGPA(double class1, double class2, double class3, double class4, double class5) {
    double output= (class1+class2+class3+class4+class5) / 5;
    return output;
}

bool errorCheck(string classX) {
    if ( !(classX=="A")  && 
         !(classX=="A-") && 
         !(classX=="B+") && 
         !(classX=="B")  && 
         !(classX=="B-") &&
         !(classX=="C+") &&
         !(classX=="C")  &&
         !(classX=="C-") &&
         !(classX=="D")  &&
         !(classX=="F")
        ) {
            return true;
        }
    return false;
}