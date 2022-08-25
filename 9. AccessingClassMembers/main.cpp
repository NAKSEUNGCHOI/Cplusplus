#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player{
    public:
        // attributes
        string name;
        int health;
        int xp;
        int level;
        
        // methods
        void talk(string text_to_say) { cout << name << " says " << "\"" << text_to_say << "\"" << endl; }
        bool is_dead();

};

class Account{
    public:
        // attributes
        string name;
        double balance;
        
        // methods
        bool deposit(double bal) {balance += bal; cout << "In deposit" << endl; return true; };
        bool widthdraw(double bal) {balance -= bal; cout << "In widthdrawl" << endl; return true; };

};


int main(){
    Account choi_account;
    choi_account.name = "Choi's account";
    choi_account.balance = 35'223'443'264;
    choi_account.deposit(1000.0);
    choi_account.widthdraw(500.0);

    Player nakseung;
    nakseung.name = "Nakseung";
    nakseung.health = 100;
    nakseung.xp = 12;
    nakseung.level = 87;
    nakseung.talk("Hi there!");

    Player *kristal = new Player();
    (*kristal).name = "kristal";
    kristal->health = 100;
    kristal->xp = 50;
    kristal->level = 85;
    kristal->talk("I will destroy you!");
    delete kristal;

    return 0;
}