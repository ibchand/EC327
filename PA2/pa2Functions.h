#ifndef PA2FUNCTIONS_H
#define PA2FUNCTION_H

    //Global variable that is the max number of computations the program can perform
    extern const int ENTRIES = 10;

    //Prints the program header
    void initialize();

    //Returns TRUE if command code in parameter "code" is legal
    bool checkCode(char code);

    //Writes output of program to file specified by user
    void writeDataToFile(const char *filename);

    //Reads commands from a file specified by user input 
    void readDataFromFile(const char *filename);

    //Returns the factorial value of the given int arg
    int factorial(int num);

    //Reutnrs the Fibonacci number at the index given by the int arg
    int fibonacci(int num);

    //Returns the square root of the double arg
    double findSqrtValue(double num);

    //Returns the natural log of the double arg
    double naturalLog(double num);

    //Returns the area of the circle with the radius given by the double arg
    double areaCircle(double num);

    //Returns the area of the square with the length given by the double arg
    double areaSquare(double num);

    //Returns the odd number CLOSET and HIGHER than the int arg provided
    int findNextOddValue(int num);

    //Returns the even number CLOSET and HIGHER than the int arg provided
    int findNextEvenValue(int num);

    //Takes double and calculates (4*num)^num + num + 10
    double findNyanCatValue(double num);

    //Performs either sin, cosine, or the exponential function depending on the char code provided
    double doMath(double num, char chr);
    
    //Returns a random number using the system time and the argument as a seed
    double lucky(double num);

    //Will return int value representing the inputs necessary for function
    int checkParameters(char chr);

    int runFunction1(int first,char chr);

    int runFunction2(int first,int last,int delta,char chr);

    int runFunction3(int first,int last,char chr);

    int runFunction4(const char* filename,char chr);
#endif