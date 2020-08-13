#include <iostream>
#include <fstream>
#include <string>
#include<math.h>
#include "pa2Functions.h"

using namespace std;

//Prints the program header
void initialize() {
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 2" << endl;
    cout << "Value of Entries is: " << ENTRIES << endl;
}

//Returns TRUE if command code in parameter "code" is legal
bool checkCode(char code) {
    //Probably just make a character array and sort through it to see if one of them is equal
    //char legalCodes[]={'F','f','B','b','R','r','U','u','C','c','E','e','K','k','S','s','N','n','X','x','L','l','Y','y','D','d','I','i','O','o','Q','q'};
    string legalCodes="FfBbRrUuCcEeKkSsNnXxLlYyDdIiOoQq";

    for(int i=0;i<legalCodes.length();i++) {
        if(code==legalCodes[i]) {
            return true;
        }
    }
    return false;
}

//Writes output of program to file specified by user
void writeDataToFile(const char *filename) {
    /*From my understanding, calling this function will effectively create a new instance of the program
    From which it will ask users for inputs and then compute the respective outputs and store them
    In the appropriate file. Then once the user inputs quit, it will the program entirely

    I think the best way to go about would be to first establish how your program runs. The user inputs
    a command which is then passed to the checkCode() function and if it's legal, the program then calls,
    the checkParamters() function which checks to see which parameters are neeeded and returns a code
    based on that. With that code sent back to the main() function, the program asks for the necessary
    inputs and then the user inputs them. With those inputs, then the proper command is called by calling
    function callCommand() which will call the right command for the user. Within the main function, the
    loop necessary to call values from first to last with increments of delta will be located. You could
    potentially make a seperate function but that's a bit too much. 

    For writeDataToFile, once this function is called, it could set a value as true and when that value
    is true, whenever you print the output from a function call, beneath the outprint statements is an
    if statement that checks to see if the writeDataToFile value is true and if so, it'll write that
    value to the specified file. 
    */

    ofstream file1(filename);
    if(file1.is_open()) {
        
    }
    else {
        cout << "Error: File cannot be opened!" << endl;
    }

}

//Reads commands from a file specified by user input and then execute them
void readDataFromFile(const char *filename) {
    string line;
    ifstream file1(filename);
    if(file1.is_open()) {
        while(getline(file1,line))
    }
}

//Returns the factorial value of the given int arg
int factorial(int num) {
    //Result takes the value of num
    int result=num;
    //Will multiply result by num as num decreases by 1 each iteration until num reaches 0
    while (num>0) {
        result*=num-1;
        num--;
    }
    return result;
}

//Returns the Fibonacci number at the index given by the int arg
int fibonacci(int num) {
    int first=0,
        second=1,
        result;
    //0,1,1,2,3,5,8,13,21,34...The next number in the sequence is the sum of the previous two
    //If the index is 0, return 0
    if(num==0) {
        return 0;
    }
    //If the index is 1, return 1
    else if(num==1) {
        return 1;
    }
    //If the index is greater than 1
    else {
        //Calculates the next fibonacci number n-2 times
        for(int i=0;i<num-2;i++) {
            result=first+second;
            first=second;
            second=result;
        }
        return result;
    }
    cout << "Error: Catch-all in fibonacci function tripped" << endl;
    return -1; //This return value indicates an error occurred
}

//Returns the square root of the double arg
double findSqrtValue(double num) {
    return sqrt(num);
}

//Returns the natural log of the double arg
double naturalLog(double num) {
    return log(num);
}

//Returns the area of the circle with the radius given by the double arg
double areaCircle(double num) {
    //PI*num^2
    return M_PI*pow(num,2);
}

//Returns the area of the square with the length given by the double arg
double areaSquare(double num) {
    return pow(num,2);
}

//Returns the odd number CLOSET and HIGHER than the int arg provided
int findNextOddValue(int num) {
    //If num is even, then add 1
    if(num%2 == 0) {
        return num++;
    }
    //If num is odd, then add 2
    else if(num%2 != 0) {
        return num+=2;
    }
    cout << "Error: Catch-all in findNextOddValue function tripped" << endl;
    return -1; //This return value indicates an error occurred
}

//Returns the even number CLOSET and HIGHER than the int arg provided
int findNextEvenValue(int num) {
    //If num is even, then add 2
    if(num%2 == 0) {
        return num+=2;
    }
    //If num is odd, then add 1
    else if(num%2 != 0) {
        return num++;
    }
    cout << "Error: Catch-all in findNextEvenValue function tripped" << endl;
    return -1; //This return value indicates an error occurred
}

//Takes double and calculates (4*num)^num + num + 10
double findNyanCatValue(double num) {
    return pow(4*num,num) + num + 10;
}

//Performs either sin, cosine, or the exponential function depending on the char code provided
double doMath(double num, char chr) {
    switch (chr)
    {
    case 'S':
        return sin(num);
        break;
    case 's':
        return sin(num);
        break;
    case 'N':
        return cos(num);
        break;
    case 'n':
        return cos(num);
        break;
    case 'X':
        return exp(num);
        break;
    case 'x':
        return exp(num);
        break;
    default:
        cout << "Error: Default in doMath function tripped" << endl;
        break;
    }
    cout << "Error: Catch-all in doMath function tripped" << endl;
    return -1; //This return value indicates an error occurred
}

//Returns a random number using the system time and the argument as a seed
double lucky(double num) {
    //srand(time(NULL),num);
    //return rand();
    //You do not use srand, instead you get the time and the multiply by num
}

int checkParameters(char chr) {
    //Codes F, f, B, and b need one parameter, an int
    if (chr=='F' || chr=='f' || 
        chr=='B' || chr=='b') 
    {
        return 1; //A return of 1 indicates user only needs to input a single int
    }
    else if (chr=='R' || chr=='r' || 
             chr=='U' || chr=='u' || 
             chr=='C' || chr=='c' ||
             chr=='K' || chr=='k' ||
             chr=='S' || chr=='s' ||
             chr=='N' || chr=='n' ||
             chr=='X' || chr=='x' ||
             chr=='L' || chr=='l' ||
             chr=='Y' || chr=='y') {
        return 2; //A return of 2 indicates user needs to input 3 ints: first, last, delta
    }

    else if (chr=='E' || chr=='e' || 
             chr=='D' || chr=='d') {
        return 3; //A return of 3 indicates user needs to input 2 ints: first and last
    }
    else if (chr=='I' || chr=='i' || 
             chr=='O' || chr=='o') {
        return 4; //A return of 4 indicates user needs to input a string, the filename
    }

    else if (chr=='Q' || chr=='q') {
        return 5; //A return of 5 indicates user needs to enter no inputs
    }
}

int runFunction1(int first,char chr) {
    int resultInt;
    switch(chr) {
        case 'F':   resultInt=factorial(first); 
                    cout << "Factorial of " << first << " is: " << resultInt << endl;
                    break;

        case 'f':   resultInt=factorial(first);
                    cout << "Factorial of " << first << " is: " << resultInt << endl; 
                    break;

        case 'B':   resultInt=fibonacci(first);  
                    cout << "Fibonacci of " << first << " is: " << resultInt << endl;  
                    break;

        case 'b':   resultInt=fibonacci(first);    
                    cout << "Fibonacci of " << first << " is: " << resultInt << endl;
                    break;

        default: cout << "Error: Default triggered in code==1" << endl;
    }
    return 0;
}

int runFunction2(int first,int last,int delta,char chr) {
    int resultInt,
        count=0;
    double resultDouble;
    if ((chr=='R') || (chr=='r')) {
        for (int i=first;i<=last;i+=delta) {
            if(count<ENTRIES) {
                resultDouble=findSqrtValue(i);
                cout << "Square Root of " << i << " is: " << resultDouble << endl;
                if(((i+delta)>last)&&((count+1)<ENTRIES)){
                    resultDouble=findSqrtValue(i+delta);
                    cout << "Square Root of " << i+delta << " is: " << resultDouble << endl;
                }
            }
            else{
                cout << "Max number of computations reached" << endl;
            }       
        }
        return 0;
    }
    else if ((chr=='U') || (chr=='u')) {
        for (int i=first;i<=last;i+=delta) {
            if(count<ENTRIES) {
                resultDouble=areaSquare(i);
                cout << "Square Area of " << i << " is: " << resultDouble << endl;
                if(((i+delta)>last)&&((count+1)<ENTRIES)){
                    resultDouble=areaSquare(i+delta);
                    cout << "Square Area of " << i+delta << " is: " << resultDouble << endl;
                }
            }
            else{
                cout << "Max number of computations reached" << endl;
            }    
        }
        return 0;
    }
    else if ((chr=='C') || (chr=='c')) {
        for (int i=first;i<=last;i+=delta) {
            if(count<ENTRIES) {
                resultDouble=areaCircle(i);
                cout << "Circle Area of " << i << " is: " << resultDouble << endl;
                if(((i+delta)>last)&&((count+1)<ENTRIES)){
                    resultDouble=areaCircle(i+delta);
                    cout << "Circle Area of " << i+delta << " is: " << resultDouble << endl;
                }
            }
        }
    }
    else if ((chr=='K') || (chr=='k')) {
        for (int i=first;i<=last;i+=delta) {
            if(count<ENTRIES) {
                resultDouble=lucky(i);
                cout << "Lucky number of " << i << " is: " << resultDouble << endl;
                if(((i+delta)>last)&&((count+1)<ENTRIES)){
                    resultDouble=lucky(i+delta);
                    cout << "Lucky number of " << i+delta << " is: " << resultDouble << endl;
                }
            }
        }
        return 0;
    }
    else if ((chr=='S') || (chr=='s')) {
       for (int i=first;i<=last;i+=delta) {
           if(count<ENTRIES) {
                resultDouble=doMath(i,chr);
                cout << "Sin of " << i << " is: " << resultDouble << endl;
                if(((i+delta)>last)&&((count+1)<ENTRIES)){
                    resultDouble=doMath(i+delta,chr);
                    cout << "Sin of " << i+delta << " is: " << resultDouble << endl;
                }
           }
       }
       return 0;
    }
    else if ((chr=='N') || (chr=='n')) {
        for (int i=first;i<=last;i+=delta) {
            if(count<ENTRIES) {
                resultDouble=doMath(i,chr);
                cout << "Cosine of " << i << " is: " << resultDouble << endl;
                if(((i+delta)>last)&&((count+1)<ENTRIES)){
                    resultDouble=doMath(i+delta,chr);
                    cout << "Cosine of " << i+delta << " is: " << resultDouble << endl;
                }
            }
        }
        return 0;
    }
    else if ((chr=='X') || (chr=='x')) {
        for (int i=first;i<=last;i+=delta) {
            if(count<ENTRIES) {
                resultDouble=doMath(i,chr);
                cout << "Exponential of " << i << " is: " << resultDouble << endl;
                if(((i+delta)>last)&&((count+1)<ENTRIES)){
                    resultDouble=doMath(i+delta,chr);
                    cout << "Exponential of " << i+delta << " is: " << resultDouble << endl;
                }
            }
        }
        return 0;
    }
    else if ((chr=='L') || (chr=='y')) {
        for (int i=first;i<=last;i+=delta) {
            if(count<ENTRIES) {
                resultDouble=naturalLog(i);
                cout << "Natural Log of " << i << " is: " << resultDouble << endl;
                if(((i+delta)>last)&&((count+1)<ENTRIES)){
                    resultDouble=naturalLog(i+delta);
                    cout << "Natural Log of " << i+delta << " is: " << resultDouble << endl;
                }
            }
        }
        return 0;
    }
    else if ((chr=='Y') || (chr=='y')) {
        for (int i=first;i<=last;i+=delta) {
            if(count<ENTRIES) {
                resultDouble=findNyanCatValue(i);
                cout << "NyanCat Value of " << i << " is: " << resultDouble << endl;
                if(((i+delta)>last)&&((count+1)<ENTRIES)){
                    resultDouble=findNyanCatValue(i+delta);
                    cout << "NyanCat Value of " << i+delta << " is: " << resultDouble << endl;
                }
            }
        }
        return 0;
    }
}

int runFunction3(int first,int last,char chr) {
    int resultInt;
    if ((chr=='E') || (chr=='e')) {
        cout << "The even values are: " << endl;
        for(int i=first;i<last;i+=2) {
            resultInt=findNextEvenValue(i);
            cout << resultInt << " ";
        }
        cout << "" << endl;
    }
    else if((chr=='D') || (chr=='d')) {
        cout << "The odd values are: " << endl;
        for(int i=first;i<last;i+=2) {
            resultInt=findNextOddValue(i);
            cout << resultInt << " ";
        }
        cout << "" << endl;    
    }
}

int runFunction4(const char* filename,char chr) {
    if((chr=='I') || (chr=='i')) {
        //Read input
    }
    else if ((chr=='O') || (chr=='o')) {
        //Write output
    }
}