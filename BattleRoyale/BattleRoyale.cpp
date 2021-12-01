#include "BattleRoyale.h"
#include "Transform.h"
#include "Utils.h"
using namespace std;

// TODO make some variables private

BattleRoyale* BattleRoyale::instance = NULL;

BattleRoyale* BattleRoyale::create() {
    if (instance != NULL) {
        return instance;
    }
    instance = new BattleRoyale();
    return instance;
}

BattleRoyale* BattleRoyale::getInstance() {
    return instance;
}

void BattleRoyale::setMap(Map* map) {
    this->map = map;
}

Map* BattleRoyale::getMap() {
    return map;
}

void BattleRoyale::initPlayers(int n) {
    for (int i = 0; i < n; i++) {
        Player p = Player(10);
        players.push_back(p); // TODO, allow customization
    }
}

void BattleRoyale::update() {
    int directions[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

    for (auto& pl : players) {
        for (Soldier s : pl.army) {
            int* dir = directions[Utils::randomRange(0, 3)];
            s.transform->move(dir[0], dir[1]);
        }
    }

    map->print();
}

void BattleRoyale::destroy() {
    map->destroy();
}