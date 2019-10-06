#include <iostream>
#include <string>
using namespace std;

int main() {
    int num,
        num2,
        count=0;
        
    string forSTR,
           revSTR="";

    cout << "Enter a number: " << endl;
    cin >> num;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Inncorrect Input type!" << endl;
        return 0;
    }
    if (num <0) {
        cout << "Error: Inncorrect Input, No Negative Values!" << endl;
        return 0;
    }

    forSTR=to_string(num);

    for (int i=forSTR.length()-1;i>=0;i--) {
        revSTR+=forSTR[i];
    }

    // int str1len,
    //     str2len;

    // str1len=forSTR.length();
    // str2len=revSTR.length();

    // cout << forSTR << " and " << revSTR << endl;
    // cout << str1len << " and " << str2len << endl;
    // (strcmp(forSTR.c_str(),revSTR.c_str())

    for (int i=0;i<forSTR.length();i++) {
        if (forSTR[i] != revSTR[i]) {
            // cout << count << endl;
            count++;
        }
    }

    if (forSTR==revSTR) {
        cout << "The number " << forSTR << " is a palindrome." << endl;
    }
    else {
        cout << "The number " << forSTR << " is not a palindrome." << endl;
    }

    return 0;
}