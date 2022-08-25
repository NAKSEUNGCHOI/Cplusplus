#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player{
    private:
        // attributes
        string name;
        int health;
        int xp;
        int level;
    
    public:  
        // methods
        void talk(string text_to_say) { cout << name << " says " << "\"" << text_to_say << "\"" << endl; }
        bool is_dead();

};

class Account{
    private:
        // attributes
        string name;
        double balance;

    public:    
        // methods
        bool deposit(double bal) {balance += bal; cout << "In deposit" << endl; return true; };
        bool widthdraw(double bal) {balance -= bal; cout << "In widthdrawl" << endl; return true; };

};


int main(){
    

    return 0;
}