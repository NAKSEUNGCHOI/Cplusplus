#include <iostream>
#include <string>

using namespace std;

class Account{
    private:
        string name;
        double balance;
    
    public:
        void set_balance(double bal) { balance = bal; }
        double get_balance() { return balance; }
        
        void set_name(string n);
        string get_name();

        bool deposit(double amount);
        bool withdraw(double amount);
};

void Account::set_name(string n){
    name = n;
}
string Account::get_name(){
    return name;
}

bool Account::deposit(double amount){
    balance += amount;
    cout << "Your balance is now " << balance << endl;
    return true;
}

bool Account::withdraw(double amount){
    if(balance-amount > 0){
        balance -= amount;
        cout << "Your balance is now " << balance << endl;
        return true;
    }else{
        return false;
    }
}

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