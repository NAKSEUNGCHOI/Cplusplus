#include <iostream>
#include <memory>

class Base{
    public:
        void say_hello() const{
            std::cout << "Hello - I'm a Base class object" << std::endl;
        }
};

class Derived: public Base{
    public:
        void say_hello() const{
            std::cout << "Hello - I'm a Derived class object" << std::endl;
        }
};

void greetings(const Base &obj){
    std::cout << "Greetings: ";
    obj.say_hello();
}

int main(){
    Base b;                 // static binding at compile time
    b.say_hello();

    Derived d;              // static binding at complie time
    d.say_hello();
    
    /* Issues */
    greetings(b);
    greetings(d);           // The reason this prints out "I'm a Base class object" is 
                            // dynamic polymorphism is not used here. 

    Base *ptr = new Derived();
    ptr->say_hello();       // expecting to print "I'm a Derive class object," but it doesn't

    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();   // smart pointer initialization
    ptr1->say_hello();                                          // no need to delete it.

    return 0;
}