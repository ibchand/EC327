#include <iostream>
#include <string>
#include "pa2Functions.h"

using namespace std;

int main() {
    
    int first,
        last,
        delta,
        parametersCode,
        resultInt;

    double resultDouble;

    bool resultBool,
            write,
            quit;
    
    char code;

    string fileName;

    while(quit) {

        cout << "Please enter command code: " << endl;
        cin >> code;
        if (cin.fail()) { //If input is not the same type as code, cin.fail()==TRUE
            cin.clear(); //cin.clear() takes buffer out of error state
            cout << "Error: Inncorrect Input type!" << endl; //Error message to indicate error
            //return 0; //Ends program
        }
        while (!checkCode(code)) { //If checkCode() returns false, then trip error condition
            cout << "Invalid command code" << endl;
            cout << "Please enter command code: " << endl;
            cin >> code;
            if (cin.fail()) { //If input is not the same type as code, cin.fail()==TRUE
                cin.clear(); //cin.clear() takes buffer out of error state
                cout << "Error: Inncorrect Input type!" << endl; //Error message to indicate error
                //return 0; //Ends program
            }
        }
        
        parametersCode=checkParameters(code);
        //If checkCode is good, ask for parameters, depending on which code requested. 
        //This may be best done in a function.

        if((code=='Q') || (code=='q')) {
            quit=false;
            return 0;
        }

        if((code=='O') || (code=='o')) {
            write=true;
            cout << "Enter filename: " << endl;
            cin >> fileName;
                if (cin.fail()) { //If input is not the same type as code, cin.fail()==TRUE
                    cin.clear(); //cin.clear() takes buffer out of error state
                    cout << "Error: Inncorrect Input type!" << endl; //Error message to indicate error
                    return 0; //Ends program
                }
            const char* fileN=fileName.c_str();
            
        }

        if((code=='I') || (code=='i')) {

        }

        if(parametersCode==1) {
            cout << "Enter an integer value: " << endl;
            cin >> first;
            if (cin.fail()) { //If input is not the same type as code, cin.fail()==TRUE
                cin.clear(); //cin.clear() takes buffer out of error state
                cout << "Error: Inncorrect Input type!" << endl; //Error message to indicate error
                return 0; //Ends program
            }
            resultInt=runFunction1(first,code,);
        }
        else if(parametersCode==2) {
            cout << "Enter value of first: " << endl;
            cin >> first;
            if (cin.fail()) { //If input is not the same type as code, cin.fail()==TRUE
                cin.clear(); //cin.clear() takes buffer out of error state
                cout << "Error: Inncorrect Input type!" << endl; //Error message to indicate error
                return 0; //Ends program
            }
            cout << "Enter value of second: " << endl;
            cin >> last;
            if (cin.fail()) { //If input is not the same type as code, cin.fail()==TRUE
                cin.clear(); //cin.clear() takes buffer out of error state
                cout << "Error: Inncorrect Input type!" << endl; //Error message to indicate error
                return 0; //Ends program
            }
            cout << "Enter value of delta: " << endl;
            cin >> delta;
            if (cin.fail()) { //If input is not the same type as code, cin.fail()==TRUE
                cin.clear(); //cin.clear() takes buffer out of error state
                cout << "Error: Inncorrect Input type!" << endl; //Error message to indicate error
                return 0; //Ends program
            }
            resultDouble=runFunction2(first,last,delta,code);
        }
        else if(parametersCode==3) {
            cout << "Enter value of first: " << endl;
            cin >> first;
            if (cin.fail()) { //If input is not the same type as code, cin.fail()==TRUE
                cin.clear(); //cin.clear() takes buffer out of error state
                cout << "Error: Inncorrect Input type!" << endl; //Error message to indicate error
                return 0; //Ends program
            }
            cout << "Enter value of second: " << endl;
            cin >> last;
            if (cin.fail()) { //If input is not the same type as code, cin.fail()==TRUE
                cin.clear(); //cin.clear() takes buffer out of error state
                cout << "Error: Inncorrect Input type!" << endl; //Error message to indicate error
                return 0; //Ends program
            }
            resultInt=runFunction3(first,last,code);
        }
        //Read command Command. Aka, error check it to make sure it's legal

        //Now that we have the correct parameters, we can call the correct function

    }
    return 0;
}