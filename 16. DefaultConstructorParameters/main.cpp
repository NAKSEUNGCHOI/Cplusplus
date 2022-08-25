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
        Player(string name_val = "None", int health_val = 0, int xp_val = 0);
};
Player::Player(string name_val, int health_val, int xp_val) : name{name_val}, health{health_val}, xp{xp_val} {
    cout << "three-agrs constructor" << endl;
}

int main(){

    Player empty;
    Player frank {"Nakseung"};
    Player hero {"Hero", 100};
    Player villain {"Kristal", 100, 55};

    return 0;

}