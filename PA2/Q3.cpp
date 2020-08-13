#include <iostream>
using namespace std;

int* ReverseMultiply(int* list,int size);

int* ReverseAdd(int* list,int size);

int main() {
    
    int numEntries;

    cout << "Enter the number of entries: ";
    cin >> numEntries;

    int entries[numEntries];

    for(int i=0;i<numEntries;i++) {
        cout << "Entry " << i << " is: ";
        cin >> entries[i];
    }

    int* ReverseMultiplyResult=ReverseMultiply(entries,numEntries);    
    int* ReverseAddResult=ReverseAdd(entries,numEntries);

    cout << "*****" << endl;

    cout << "Original array is: ";
    for (int i=0;i<numEntries;i++) {
        cout << entries[i] << " ";
    }
    cout << "and the address of the zero element is: " << &entries[0] << endl;

    cout << "One array is: ";
    for (int i=0;i<(numEntries*2+1);i++) {
        cout << ReverseMultiplyResult[i] << " ";
    }
    cout << "and the address of the zero element is: " << &ReverseMultiplyResult[0] << endl;
    
    cout << "Two array is: ";
    for (int i=0;i<(numEntries*2-1);i++) {
        cout << ReverseAddResult[i] << " ";
    }
    cout << "and the address of the zero element is: " << &ReverseAddResult[0] << endl;


    // for (int i=0;i<(size*2-1);i++) {
    //     cout << result[i] << endl;
    // }

    // for (int i=0;i<(size*2+1);i++) {
    //     cout << result[i] << endl;
    // }

    // for (int i=0;i<(numEntries*2+1);i++) {
    //     cout << ReverseMultiplyResult[i] << endl;
    // }

    return 0;
}

int* ReverseMultiply(int* list,int size) {
    int* result= new int[size*2+1];
    int product=1;
    for (int i=0;i<size;i++) {
        result[i]=list[i];
        result[size*2-i-1]=list[i];
    }
    for (int i=0;i<(size*2);i++) {
        product*=result[i];
    }
    result[size*2]=product;

    // for (int i=0;i<(size*2+1);i++) {
    //     cout << result[i] << endl;
    // }

    return result;
}

int* ReverseAdd(int* list,int size) {
    int* result= new int[size*2-1];

    for (int i=0;i<size;i++) {
        result[i]=list[i];
        //result[i+size]=list[size-1-i]+list[size-2-i];
    }
    for (int i=0;i<(size-1);i++) {
        result[i+size]=list[size-1-i]+list[size-2-i];
    }

    // for (int i=0;i<(size*2-1);i++) {
    //     cout << result[i] << endl;
    // }

    return result;
}


