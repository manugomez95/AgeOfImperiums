#include "Player.h"
#include "BattleRoyale.h"
#include "Utils.h"

using namespace std;

int Player::counter = 0;

// TODO add deletes everywhere to clean memory
// TODO use global counter to check how many players remaining in match
Player::Player(int armySize, bool debug) {
    //enum class Color { Green = 10, Yellow = 14, Magenta = 13 }; TODO REVIEW
    int colors[] = { 10, 14, 13 }; // TODO change
    
    this->id = counter;
    counter++;
    
    this->color = colors[id];
    this->armySize = armySize;
    this->debug = debug;

    this->army = vector<Soldier*>();

    Map* map = BattleRoyale::getInstance()->getMap();

    // For each soldier
    for (int i = 0; i < armySize; i++) {
        Soldier* s = new Soldier(this, map, { -1,-1 });
        if (!map->add(s)) throw runtime_error("Map is too crowded.");
        army.push_back(s);
    }
}

Player::Player(int armySize) : Player(armySize, false) {}

string Player::str() {
    return "P" + to_string(id);
}