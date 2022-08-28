#include <iostream>
#include "Mystring.cpp"
#include "Mystring.h"
#include <vector>

using namespace std;

int main(){

    Mystring a {"Hello"};            // Overloaded constructor
    a = Mystring{"Hola"};           // Overloaded constructor then move assignment
    a = "Bonjour";                  // Overloaded constructor then move assignment
    
    Mystring empty;
    Mystring larry{"Larry"};
    Mystring stooge {larry};
    Mystring stooges;

    empty = stooge;

    empty.display();
    larry.display();
    stooge.display();
    empty.display();

    stooges = "Larry, Moe, and Curly";
    stooges.display();

    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");

    cout << "============ Loop 1 =============" << endl;
    for(const Mystring &s: stooges_vec) s.display();

    cout << "============ Loop 2 =============" << endl;
    for(Mystring &s: stooges_vec) s = "Changed";

    cout << "============ Loop 3 =============" << endl;
    for(const Mystring &s: stooges_vec) s.display();
    
    return 0;
}