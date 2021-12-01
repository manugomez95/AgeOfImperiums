#include "Player.h"
using namespace std;

int Player::counter = 0;

string Player::str() {
    string res = "";
    for (int i = 0; i < armySize; i++) {
        res = res + army[i].str();
    }
    return res;
}

void Player::destroy() {
    delete[] army;
}

Player::Player(int size) {
    int colors[] = { 10, 14, 13 }; // TODO change
    id = counter;
    counter++;
    color = colors[id];
    armySize = size;
    army = new Soldier[armySize];
}