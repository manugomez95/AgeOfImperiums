#include "BattleRoyale.h"

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
    for (auto& pl : players) {
        for (Soldier& s : pl.army) {
            s.action();
        }
    }

    map->print(true);
}

void BattleRoyale::destroy() {
    map->destroy();
}