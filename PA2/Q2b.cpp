#include <iostream>
using namespace std;

double series(double n,double count,double sum);

int main() {
    double sum=0;
    double count=1;

    double n;
    double result;

    cout << "Enter n: ";
    cin >> n;

    result=series(n,count,sum);
    cout << "Series(" << n << ") is: " << result << endl;
    return 0;
}

double series(double n,double count,double sum) {
    if(n<count) {
        //cout << "if: Count is: " << count << endl;
        //cout << "if: Sum is: " << sum << endl;
        return sum;
    }
    else {
        //cout << "else: Count is: " << count << endl;
        //cout << "else: Sum is: " << sum << endl;
        sum+=(2*count)/(3*count+2);
        //cout << "else2: Sum is: " << sum << endl;
        count++;
        sum=series(n,count,sum);
        return sum;
    }
    cout << "Error: series() catch-all triggered!" <<endl;
    return 0;
}

