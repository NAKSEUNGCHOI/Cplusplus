#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
        string name;
        int health;
        int xp;
    public:
        //Default parameter
        std::string get_name() {return name;}
        int get_health() { return health; }
        int get_xp() { return xp; }
        // single 3 args constructor with default parameters. 
        Player(string name_val = "None", int health_val = 0, int xp_val = 0);
        // Copy constructor
        Player(const Player &source);
        // Destructor
        ~Player() { cout << "Destructor called for: " << name << endl; }
};
Player::Player(string name_val, int health_val, int xp_val) : name{name_val}, health{health_val}, xp{xp_val} {
    cout << "three-agrs constructor" << endl;
}

Player::Player(const Player &source) 
    : name{source.name}, health{source.health}, xp{source.xp} {
    cout << "Copy constructor - made copy of: " << source.name << endl;
}

// Copy
void display_player(Player p){
    cout << "Name: " << p.get_name() << endl;
    cout << "health: " << p.get_health() << endl;
    cout << "XP: " << p.get_xp() << endl;
}

int main(){

    Player empty;

    display_player(empty);

    Player frank {"Nakseung"};
    Player hero {"Hero", 100};
    Player villain {"Kristal", 100, 55};

    return 0;

}