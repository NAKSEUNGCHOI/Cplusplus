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

int main(){
    std::unique_ptr<Test> t1 {new Test{100}};
    std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);

    std::unique_ptr<Test> t3;
    t3 = std::move(t1);                                             // pass the ownership.
    if(!t1)
        std::cout << "t1 is nullptr" << endl; 

    
    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
    std::cout << *a1 << endl;
    a1->deposit(5000);
    std::cout << *a1 << endl;

    std::vector<std::unique_ptr<Account>> accounts;
    accounts.push_back( make_unique<Checking_Account>("James", 1000));
    accounts.push_back( make_unique<Savings_Account>("Billy", 1000, 5.2));
    accounts.push_back( make_unique<Trust_Account>("Bobby", 1000, 4.5));

    for(const auto &acc: accounts)
        std::cout << *acc << std::endl;
    
    return 0;
}