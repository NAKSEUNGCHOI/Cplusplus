#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
        string name;
        int health;
        int xp;
    public:
    //Overloaded Constructors
        Player();
        Player(string name_val);
        Player(string name_val, int health, int xp);
};
Player::Player() : Player{"None", 0, 0} {
    cout << "No-agrs constructor" << endl;
}
Player::Player(string name_val) : Player{name_val, 0, 0} {
    cout << "one-agrs constructor" << endl;
}
Player::Player(string name_val, int health_val, int xp_val) : name{name_val}, health{health_val}, xp{xp_val} {
    cout << "three-agrs constructor" << endl;
}

int main(){
    Player empty;
    Player frank {"Nakseung"};
    Player villain {"Kristal", 100, 55};
    return 0;

}