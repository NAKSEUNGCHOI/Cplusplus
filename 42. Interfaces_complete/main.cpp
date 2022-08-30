#include <iostream>

class Printable{
    friend std::ostream &operator<<(std::ostream &os, const Printable &obj);
    public:
        virtual void print(std::ostream &os) const = 0;
};

std::ostream &operator<<(std::ostream &os, const Printable &obj){
    obj.print(os);
    return os;
}

class Account: public Printable{

    public:
        virtual void withdraw(double amount){
            std::cout << "In Account::withdraw" << std::endl;
        }
        virtual void print(std::ostream &os) const override{
            os << "Account display";
        }
    virtual ~Account() {}
};


class Checking: public Account{

    public:
    virtual void withdraw(double amount) override {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override{
            os << "Checking display";
    }
    virtual ~Checking() {}
};

class Savings: public Account{

    public:
    virtual void withdraw(double amount) override {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override{
            os << "Savings display";
    }
    virtual ~Savings() {}
};

class Trust: public Account{

    public:
    virtual void withdraw(double amount) override {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override{
            os << "Trust display";
    }
    virtual ~Trust() {}
};

class Dog: public Printable{
    public:
        virtual void print(std::ostream &os) const override{
            os << "Woof Woof";
    }
};

void print(const Printable &obj){
    std::cout << obj << std::endl;
}

int main(){
    Account *p1 = new Account();
    std::cout << *p1 << std::endl;

    Checking *p2 = new Checking();
    std::cout << *p2 << std::endl;

    Dog *dog = new Dog();
    std::cout << *dog << std::endl;
    print(*dog);

    // Account a;
    // std::cout << a << std::endl;

    // Checking b;
    // std::cout << b << std::endl;

    // Savings c;
    // std::cout << c << std::endl;

    // Trust d;
    // std::cout << d << std::endl;

    delete p1;
    delete p2;
    delete dog;


    return 0;
}