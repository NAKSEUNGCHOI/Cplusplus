#include <iostream>
#include <memory>

class Base{
    public:
        virtual void say_hello() const{
            std::cout << "Hello - I'm a Base class object" << std::endl;
        }
        virtual ~Base() {}
};

/*
 *  Its a good practice to write "override" for dynamic polymorphic function.
 *  As you can see on the bottom, you write override at the end of the function followed by virtual and the same name of the function.
 *  By making it overiding, dynamic polymorphic functions can be achieved (dynamic binding not staic binding.)
 */
class Derived: public Base{
    public:
        virtual void say_hello() const override{    
            std::cout << "Hello - I'm a Derived class object" << std::endl;
        }
        virtual ~Derived() {}
};


int main(){
    Base *p1 = new Base();                 // static binding at compile time
    p1->say_hello();

    Derived *p2 = new Derived();              // static binding at complie time
    p2->say_hello();

    Base *p3 = new Derived();
    p3->say_hello();

    return 0;
}