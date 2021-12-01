#include "Player.h"
#include "BattleRoyale.h"
#include "Transform.h"
#include "Utils.h"
using namespace std;

int Player::counter = 0;

// TODO add deletes everywhere to clean memory

string Player::str() {
    string res = "";
    res += "id: " + to_string(id) + "\n";
    res += "color: " + to_string(color) + "\n";
    for (int i = 0; i < armySize; i++) {
        res = res + army[i].str();
    }
    return res;
}

Player::Player(int size) {
    //enum class Color { Green = 10, Yellow = 14, Magenta = 13 }; TODO REVIEW
    int colors[] = { 10, 14, 13 }; // TODO change
    id = counter;
    counter++;
    color = colors[id];
    armySize = size;
    army = vector<Soldier>();

    Map* map = BattleRoyale::getInstance()->getMap();

    // For each soldier
    for (int i = 0; i < armySize; i++) {
        int pos[2] = { Utils::randomRange(1,20), Utils::randomRange(1,20) };
        Soldier* s = new Soldier(id, new Transform(map, pos));
        map->matrix[pos[0]][pos[1]] = s; // TODO take into account collisions
        army.push_back(*s);
    }
}