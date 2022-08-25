#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
        string name;
        int health;
        int xp;
    public:
        // all of the getters should be const.
        string get_name() const {
            return name;
        }
        void set_name(string name_val){
            name = name_val;
        }
        // single 3 args constructor with default parameters. 
        Player();
        Player(string name_val);
        Player(string name_val, int health_val, int xp_val);
};
Player::Player() : Player{"None", 0, 0} {
}
Player::Player(string name_val) : Player{name_val, 0, 0} {
}
Player::Player(string name_val, int health_val, int xp_val) : name{name_val}, health{health_val}, xp{xp_val} {
}

// Copy
void display_player(const Player &p){
    cout << "Name: " << p.get_name() << endl;
}

int main(){

    const Player villain {"Villain", 100, 50};
    Player hero {"Hero", 100, 50};
    cout << villain.get_name() << endl;
    cout << hero.get_name() << endl;

    //villain.set_name("Super Villain"); // should not work.
    display_player(villain);
    display_player(hero);

    return 0;

}