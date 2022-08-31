#include "Account.h"
#include "Savings_Account.h"
#include "Savings_Account.cpp"
#include "Account.cpp"
#include "Account_util.h"
#include "Account_util.cpp"
#include "Checking_Account.h"
#include "Checking_Account.cpp"
#include "Trust_Account.h"
#include "Trust_Account.cpp"
#include "I_Printable.h"
#include "I_Printable.cpp"
#include <iostream>
#include <memory>

using namespace std;

class Test{
    private:
        int data;
    public:
        Test(): data{0} {std::cout << "Test Constructor (" << data << ")" << std::endl; }
        Test(int data): data{data} {std::cout << "Test Constructor (" << data << ")" << std::endl; }
        int get_data() const { return data; }
        ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

void func(std::shared_ptr<Test> p){
    std::cout << "Use count: " << p.use_count() << std::endl;
}

int main(){
    // std::shared_ptr<int> p1 {new int {100}};
    // std::cout << "Use count: " << p1.use_count() << std::endl;

    // std::shared_ptr<int> p2 {p1};
    // std::cout << "Use count: " << p1.use_count() << std::endl;

    // p1.reset();
    // std::cout << "Use count: " << p1.use_count() << std::endl;
    // std::cout << "Use count: " << p2.use_count() << std::endl;


    // std::cout << "\n==============================================" << std::endl;
    // std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
    // func(ptr);
    // std::cout << "Use count: " << ptr.use_count() << std::endl;
    // {
    //     std::shared_ptr<Test> ptr1 = ptr;
    //     std::cout << "Use count: " << ptr.use_count() << std::endl;
    //     {
    //         std::shared_ptr<Test> ptr2 = ptr;
    //         std::cout << "Use count: " << ptr.use_count() << std::endl;
    //         std::cout << "Use count: " << ptr2.use_count() << std::endl;
    //         ptr.reset();
    //         std::cout << "Use count: " << ptr2.use_count() << std::endl;
    //     }
    //     std::cout << "Use count: " << ptr.use_count() << std::endl;
    //     std::cout << "Use count: " << ptr1.use_count() << std::endl;
    // }
    // std::cout << "Use count: " << ptr.use_count() << std::endl;
    
    std::cout << "\n==============================================" << std::endl;
    std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account>("Larry", 10000, 3.1);
    std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account>("Moe", 5000);
    std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account>("Curly", 6000);

    std::vector<std::shared_ptr<Account>> accounts;
    accounts.push_back(acc1); // make a copy of acc1 so count becomes 2 shared ownership
    accounts.push_back(acc2); // make a copy of acc2 so count becomes 2 shared ownership
    accounts.push_back(acc3); // make a copy of acc3 so count becomes 2 shared ownership

    for (const auto &acc: accounts){
        std::cout << *acc << std::endl;
        std::cout << "Use count: " << acc.use_count() << std::endl;
    }
    std::cout << "\n==============================================" << std::endl;


    return 0;
}