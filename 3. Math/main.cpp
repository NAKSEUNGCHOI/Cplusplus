#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double num {};
    cout << "Enter a number: ";
    cin >> num;

    cout << "The sqrt of " << num << " is: " << sqrt(num) << endl;
    cout << "The cubed root of " << num << " is: " << cbrt(num) << endl;
    cout << "The power of " << num << " is: " << pow(num, 2) << endl;

    cout << "The sin of " << num << " is: " << sin(num) << endl;


    return 0;
}