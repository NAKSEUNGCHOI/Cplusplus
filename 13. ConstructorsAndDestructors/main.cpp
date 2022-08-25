#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
        string name;
        int health;
        int xp;

    public:
        void set_name(string name_val){
            name = name_val;
        }

        Player(){ // Three constructors
            cout << "No args constructor called" << endl;
        }
        Player(string name){
            cout << "string arg constructor called" << endl;
        }
        Player(string name, int health, int xp){
            cout << "three args constructor called" << endl;
        }
        ~Player(){ //Destructor LIFO
            cout << "Destructor called " << name << endl;
        }
};

int main(){

    {
        Player slayer;
        slayer.set_name("Slayer");
    }

    {
        Player choi;
        choi.set_name("choi");
        Player hero("Hero");
        hero.set_name("Hero");
        Player vallen("vallen", 100, 12);
        vallen.set_name("Vallen");
    }

    Player *enemy = new Player;
    enemy->set_name("Enemy");

    Player *level_boss = new Player("Level Boss", 1000, 300);
    level_boss->set_name("Death Knight");

    delete enemy;
    delete level_boss;

    return 0;
}