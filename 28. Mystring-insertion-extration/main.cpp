#include <iostream>
#include "Mystring.cpp"
#include "Mystring.h"
#include <vector>

using namespace std;

int main(){

    cout << boolalpha << endl;

    Mystring larry {"Larry"};
    Mystring moe {"Moe"};
    Mystring curly;

    cout << "Enter the third stooge's first name: ";
    cin >> curly;

    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;

    cout << "\n Enter the three stooges names separated by a space: ";
    cin >> larry >> moe >> curly;

    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl; 
    
    return 0;
}