#include "Account.h"
#include "Savings_Account.h"
#include "Savings_Account.cpp"
#include "Account.cpp"
#include <iostream>

using namespace std;

int main(){
    cout << "\n============================ Account ============================" << endl;
    Account acct {};
    acct.deposit(2000.0);
    acct.withdraw(500.0);

    cout << endl;

    Account *p_acc {nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;

    cout << "\n======================== Savings Account ========================" << endl;
    Savings_Account sav_acc {};
    sav_acc.deposit(2000.0);
    sav_acc.withdraw(500.0);

    cout << endl;

    Savings_Account *p_sav_acc {nullptr};
    p_sav_acc = new Savings_Account();
    p_sav_acc->deposit(1000.0);
    p_sav_acc->withdraw(500.0);
    p_sav_acc->name = {"Choi"};
    cout << p_sav_acc->name << endl;
    
    delete p_sav_acc;
    cout << "\n=================================================================" << endl;

    cout << endl;

    return 0;
}