#include <iostream>

using namespace std;

class Base{
    private:
        int value;
    public:
        Base() : value{0} { cout << "Base no-args constructor" << endl; }
        Base(int x) : value{x} { cout << "Base (int) overloaded constructor" << endl; }
        Base(const Base &other)
            : value {other.value} {
            cout << "Base copy Constructor" << endl;
        }
        Base &operator=(const Base &rhs){ //Overloaded copy assignment
            cout <<"Base operator=" << endl;
            if(this == &rhs) return *this;
            value = rhs.value;
            return *this;
        }
        ~Base() { cout << "Base destructor" << endl; }
};

class Derived: public Base {
    
    private:
        int doubled_value;
    public:
        Derived(): Base{}, doubled_value {0} { cout << "Drived no-args constructor " << endl; }
        Derived(int x): Base{x}, doubled_value {x*2} { cout << "Drived (int) overloaded constructor " << endl; }
        Derived(const Derived &other)
            : Base(other), doubled_value {other.doubled_value} {
            cout << "Derived copy constructor" << endl;
        }
        Derived &operator=(const Derived &rhs){ //overloaded copy assignment
            cout << "Derived operator=" <<endl;
            if(this == &rhs) return *this;
            Base::operator=(rhs);
            doubled_value = rhs.doubled_value;
            return *this;
        } 
        ~Derived() { cout << "Derived destructor " << endl; }
};

int main() {
    Base b {100};           // Overloaded constructor
    Base b1 {b};            // copy constructor
    b = b1;                 // Copy assignment
    
    Derived d;              // Overloaded constructor
    Derived d1 {d};         // copy constructor
    d = d1;                 // Copy assignment

    return 0;
}