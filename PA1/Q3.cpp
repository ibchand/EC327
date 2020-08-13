#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//dec2ter Function prototype: Will convert int decimal input into ternary and return it as string
string dec2ter(int num);
//toString Function prototype: Will convert int input into a string and return it
string toString(int input);

int main () {    
    int decNUM1,
        decNUM2,
        result=0;

    string terNUM1,
           terNUM2,
           errorCheck1,
           errorCheck2;

    //Asks user for input
    cout << "Enter two numbers between 0-100: " << endl;
    cin >> decNUM1;
    //Checks that input is of the correct data type
    if (cin.fail()) {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Inncorrect Input type!" << endl;
        return 0;
    }
    //Checks that input is in the correct range
    if (decNUM1 < 0 || decNUM1 > 100) {
        cout << "Error: Input out of range!" << endl;
        return 0;
    }

    cin >> decNUM2;
    if (cin.fail()) {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error! Inncorrect Input type!" << endl;
        return 0;
    }
    if (decNUM2 < 0 || decNUM2 > 100) {
        cout << "Error: Input out of range!" << endl;
        return 0;
    }

    terNUM1 = dec2ter(decNUM1);
    terNUM2 = dec2ter(decNUM2);

    //The length of ternary values may vary so this adds zeroes to the front of the shorter string
    if (terNUM1.length() != terNUM2.length()) {
        if (terNUM1.length() > terNUM2.length()) {
            int diffLENGTH=terNUM1.length()-terNUM2.length();
            string diff="";
            for (int i=0;i<diffLENGTH;i++) {
                diff+="0";
            }
            diff+=terNUM2;
            terNUM2=diff;
        }
        else if (terNUM1.length() < terNUM2.length()) {
            int diffLENGTH=terNUM2.length()-terNUM1.length();
            string diff="";
            for (int i=0;i<diffLENGTH;i++) {
                diff+="0";
            }
            diff+=terNUM1;
            terNUM1=diff;
        }
    }

    //Used for debugging
    //cout << terNUM1 << " and " << terNUM2 << endl;

    //Calculates the hamming distance between the ternary strings
    for (int i=0; i<terNUM1.length(); i++) {
        if (terNUM1[i] != terNUM2[i]) {
            result++;
        }
    }

    cout << "Hamming distance between " << decNUM1 << " and " << decNUM2 << " when numbers are in ternary format is " << result << "." << endl;
    return 0;
}

string dec2ter(int num) {
    string result="",
           remainder="";

    //While the quotient is greater than zero, divide the quotient by 3 and store the remainder as a string
    while (num > 0) {
        remainder=toString(num % 3);
        remainder+=result;
        result=remainder;
        num /=3;
    }
    //cout << result << endl; Used for Debugging
    return result;
}

string toString(int input) {
    ostringstream stream;
    stream << input;
    return stream.str();
}