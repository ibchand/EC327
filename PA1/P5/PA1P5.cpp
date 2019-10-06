#include <iostream>
#include <string>
using namespace std;

int main() {
    char CHAR;
    int OP,
        index;

    string abc="abcdefghijklmnopqrstuvwxyz";
    string zyx="zyxwvutsrqponmlkjihgfedcba";
    string abcABC="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    cout << "Enter char, operation: " << endl;
    
    cin >> CHAR;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Inncorrect Input type!" << endl;
        return 0;
    }

    cin >> OP;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Inncorrect Input type!" << endl;
        return 0;
    }

    switch (OP) {
        case 1: 
            if (isupper(CHAR)) {
                CHAR=tolower(CHAR);
            } 
            else {
                CHAR=toupper(CHAR);
            }
        break;
        case 2:
            for (int i=0;i<abc.length();i++) {
                if (abc[i]==tolower(CHAR)) {
                    index=i;
                }
            }
            if (isupper(CHAR)) {
                CHAR=zyx[index];
            }
            else {
                CHAR=toupper(zyx[index]);
            }
        break;
        case 3:
            for (int i=0;i<abcABC.length();i++) {
                if (abcABC[i]==CHAR) {
                    index=i;
                }
            }
            index+=6;
            if (index>51) {
                index-=51;
            }
            CHAR=abcABC[index];
        break;
        default:
            cout << "Error: Deafult Trigggered" << endl;
    }

    cout << "Result: " << CHAR << endl;
    
    return 0;
}