#include "Player.h"
#include "BattleRoyale.h"
#include "Utils.h"

using namespace std;

int Player::counter = 0;
int const PLACEMENT_MAX_TRIES = 10;

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
        bool has_place = false;
        for (int tries = 0; tries < PLACEMENT_MAX_TRIES && !has_place; tries++) {
            array<int, 2> pos = { Utils::randomRange(0,map->rows - 1), Utils::randomRange(0,map->cols - 1) };
            if (map->matrix[pos[0]][pos[1]] == NULL) {
                has_place = true;
                Soldier* s = new Soldier(this, map, pos);
                map->matrix[pos[0]][pos[1]] = s;
                army.push_back(s);
            }
        }
        if (!has_place) throw runtime_error("Map is too crowded.");
    }
}

Player::Player(int armySize) : Player(armySize, false) {}

string Player::str() {
    return "P" + to_string(id);
}