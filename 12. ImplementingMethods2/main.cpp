#include <iostream>
#include "Account.h"
#include "Account.cpp"


using namespace std;

int main(){
    Account nakseung_accout;
    nakseung_accout.set_name("Nakseung's Account");
    nakseung_accout.set_balance(10000.0);

    if(nakseung_accout.deposit(200.0)){
        cout << "Deposit Complete" << endl;
    }else{
        cout << "Deposit not allowed" << endl;
    }

    if(nakseung_accout.withdraw(5000.0)){
        cout << "Withdraw Complete" << endl;
    }else{
        cout << "Insufficient Amount" << endl;
    }


    return 0;
}