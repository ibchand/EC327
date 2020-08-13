#include <iostream>
using namespace std;

int gcd(int m, int n);


int main() {
    int m,
        n,
        result;
    
    cout << "Enter m: ";
    cin >> m;

    cout << "Enter n: ";
    cin >> n;

    result=gcd(m,n);
    cout << "GCD is: " << result << endl;

    return 0;
}

int gcd(int m,int n) {
    if((m<0) || (n<0)) {
        return 0;
    }
    else if(m%n==0) {
        return n;
    }
    else {
        return gcd(n,m%n);
    }
    cout << "Error: gcd catch-all triggered!" <<endl;
    return 0;
}