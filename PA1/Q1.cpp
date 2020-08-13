#include <iostream>
#include <string>
#include  <iomanip>
using namespace std;

//let2num function prototype: Will convert strings to doubles
double let2num(std::string classX);

//calcGPA function prototype: Will calculate GPA from given doubles
double calcGPA(double class1, double class2, double class3, double class4, double class5);

//errorCheck function prototype: Will check if string input is correct
bool errorCheck(std::string);

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
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

//Compares the input to each possible letter and assigns the proper numerical value
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
//Calculates the GPA by finding the mean of the inputs
double calcGPA(double class1, double class2, double class3, double class4, double class5) {
    double output= (class1+class2+class3+class4+class5) / 5;
    return output;
}

//If the input if not equal to one of these strings, then will print an error and end program
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