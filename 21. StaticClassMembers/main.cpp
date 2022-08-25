#include <iostream>
#include "Player.h"
#include "Player.cpp"

using namespace std;

void display_active_player(){
    cout << "Active players: " << Player::get_num_players() << endl;
}

int main(){

    display_active_player();
    Player kristal {"kristal", 100, 90};
    display_active_player();

    {
        Player frank {"frank"};
        display_active_player();
    }
    display_active_player();

    Player *enemy = new Player("Enemy", 100, 90);
    display_active_player();
    delete enemy;
    display_active_player();
    
    return 0;
}