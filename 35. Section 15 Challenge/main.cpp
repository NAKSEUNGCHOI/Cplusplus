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
#include <iostream>

using namespace std;

int main(){
    cout.precision(2);
    cout << fixed;

    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000});
    accounts.push_back(Account {"Curly", 5000});
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    
    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {});
    sav_accounts.push_back(Savings_Account {"Superman"});
    sav_accounts.push_back(Savings_Account {"Batman", 2000});
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0});
    
    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    vector<Checking_Account> checking_accounts;
    checking_accounts.push_back(Checking_Account {});
    checking_accounts.push_back(Checking_Account {"kirk"});
    checking_accounts.push_back(Checking_Account {"Spock", 2000});
    checking_accounts.push_back(Checking_Account {"Bones", 5000});
    
    display(checking_accounts);
    deposit(checking_accounts, 1000);
    withdraw(checking_accounts, 2000);

    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account {});
    trust_accounts.push_back(Trust_Account {"Athos", 10000, 5.0});
    trust_accounts.push_back(Trust_Account {"Porthos", 20000, 4.0});
    trust_accounts.push_back(Trust_Account {"Aramis", 30000});
    
    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);

    for(int i = 1; i <=5; i++)
        withdraw(trust_accounts, 1000);

    return 0;
}