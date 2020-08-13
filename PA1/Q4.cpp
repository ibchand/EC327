#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//toString Function Prototype: Takes int input and returns it as a string
string toString(int input);

int main() {
    int num,
        num2,
        count=0;
        
    string forSTR,
           revSTR="";

    //Asks user for input a number
    cout << "Enter a number: " << endl;
    cin >> num;
    if (cin.fail()) {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Inncorrect Input type!" << endl;
        return 0;
    }
    if (num <0) {
        cout << "Error: Inncorrect Input, No Negative Values!" << endl;
        return 0;
    }

    //Converts num to string
    forSTR=toString(num);

    //Reverses the string
    for (int i=forSTR.length()-1;i>=0;i--) {
        revSTR+=forSTR[i];
    }

    //Counts the differences, if there are any. Not used
    for (int i=0;i<forSTR.length();i++) {
        if (forSTR[i] != revSTR[i]) {
            // cout << count << endl;
            count++;
        }
    }

    //If the strings are equal, it's a palindrome
    if (forSTR==revSTR) {
        cout << "The number " << forSTR << " is a palindrome." << endl;
    }
    else {
        cout << "The number " << forSTR << " is not a palindrome." << endl;
    }

    return 0;
}

string toString(int input) {
    ostringstream stream;
    stream << input;
    return stream.str();
}