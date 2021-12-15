#include "BattleRoyale.h"
#include "Utils.h"
#include "Player.h"
#include "Map.h"
#include "Soldier.h"
#include <iostream>

using namespace std;

int Player::counter = 0;

// TODO add deletes everywhere to clean memory
// TODO use global counter to check how many players remaining in match
Player::Player(Map* map, int armySize, bool debug) {
    array<int, 4> colors = { LIGHTGREEN, YELLOW, LIGHTBLUE, LIGHTGRAY };
    
    this->id = counter;
    counter++;
    
    if (id >= colors.size())
        throw runtime_error("Too many players. Maximum is " + to_string(colors.size()));
    else this->color = colors[id];

    this->armySize = armySize;
    this->debug = debug;

    this->army = vector<Soldier*>();

    // For each soldier
    for (int i = 0; i < armySize; i++) {
        Soldier* s = new Soldier(this, map);
        army.push_back(s);
    }
}

string Player::str() {
    return "P" + to_string(id+1);
}

vector<Soldier*> Player::getArmy() {
    return army;
}

int Player::getArmySize() {
    return armySize;
}

void Player::decreaseArmySize() {
    armySize--;
}

int Player::getColor() {
    return color;
}

bool Player::isDebugged() {
    return debug;
}