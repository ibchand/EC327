#include <iostream>
#include "PA1P1.h"
#include <string>
#include  <iomanip>
using namespace std;

int main() {
    string class1Let,
           class2Let,
           class3Let,
           class4Let,
           class5Let;
    double class1Num,
           class2Num,
           class3Num,
           class4Num,
           class5Num;

    double GPA;

    //cin.fail will return true if an input error occured. cin.clear() allows the buffer to exit the error state. cin.ignore allows you to skip the rest of the line from the error point

    cout << "Class 1 " << endl;
    cin >> class1Let;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Inncorrect Input!" << endl;
        return 0;
    }
    if (errorCheck(class1Let)) {
        cout << "Inncorrect Input!" << endl;
        return 0;
    }    
    class1Num=let2num(class1Let);

    cout << "Class 2 " << endl;
    cin >> class2Let;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Inncorrect Input!" << endl;
        return 0;
    }
    if (errorCheck(class2Let)) {
        cout << "Inncorrect Input!" << endl;
        return 0;
    }
    class2Num=let2num(class2Let);

    cout << "Class 3 " << endl;
    cin >> class3Let;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Inncorrect Input!" << endl;
        return 0;
    }
    if (errorCheck(class3Let)) {
        cout << "Inncorrect Input!" << endl;
        return 0;
    }
    class3Num=let2num(class3Let);

    cout << "Class 4 " << endl;
    cin >> class4Let;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Inncorrect Input!" << endl;
        return 0;
    }
    if (errorCheck(class4Let)) {
        cout << "Inncorrect Input!" << endl;
        return 0;
    }
    class4Num=let2num(class4Let);

    cout << "Class 5 " << endl;
    cin >> class5Let;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Inncorrect Input!" << endl;
        return 0;
    }
    if (errorCheck(class5Let)) {
        cout << "Inncorrect Input!" << endl;
        return 0;
    }
    class5Num=let2num(class5Let);

    GPA=calcGPA(class1Num,class2Num,class3Num,class4Num,class5Num);

    cout << "GPA: " << setprecision(3) << GPA << endl;

    return 0;
}