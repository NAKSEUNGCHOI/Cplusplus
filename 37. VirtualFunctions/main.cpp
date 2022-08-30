#include <iostream>

class Account{
    public:
        virtual void withdraw(double amount){
            std::cout << "In Account::withdraw" << std::endl;
        }
        virtual ~Account() { std::cout << "Account:: destructor" << std::endl; }
};

class Checking: public Account{
    public:
        virtual void withdraw(double amount){
            std::cout << "In Checking::withdraw" << std::endl;
        }
        virtual ~Checking() { std::cout << "Checking:: destructor" << std::endl; }
};

class Savings: public Account{
    public:
        virtual void withdraw(double amount){
            std::cout << "In Savings::withdraw" << std::endl;
        }
        virtual ~Savings() { std::cout << "Savings:: destructor" << std::endl; }
};

class Trust: public Account{
    public:
        virtual void withdraw(double amount){
            std::cout << "In Trust::withdraw" << std::endl;
        }
        virtual ~Trust() { std::cout << "Trust:: destructor" << std::endl; }
};

int main(){
    std::cout << "\n === Pointers ====" << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();

    p1->withdraw(10000);
    p2->withdraw(10000);
    p3->withdraw(10000);
    p4->withdraw(10000);

    std::cout << "\n === Clean up ==== " << std::endl;
    /*
     * virtual destructor is needed to prevent it from ominous errors and memory leaking
     * The syntax is simple. virtual ~Account();
     */
    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}