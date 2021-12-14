#include "BattleRoyale.h"
#include "Utils.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono_literals; // ns, us, ms, s, h, etc.
using chrono::system_clock;
using namespace this_thread;

// TODO make some variables private

BattleRoyale* BattleRoyale::instance = NULL;

BattleRoyale::BattleRoyale(ViewMode viewMode) {
    this->viewMode = viewMode;
    refreshRate = this->viewMode == ViewMode::Cinematic ? 1000ms : 3000ms;
}

BattleRoyale* BattleRoyale::create(ViewMode viewMode) {
    if (instance != NULL) {
        return instance;
    }
    instance = new BattleRoyale(viewMode);
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

// TODO deprecated? revisar
void BattleRoyale::initPlayers(int n_players, int army_size) {
    for (int i = 0; i < n_players; i++) {
        Player* p = new Player(army_size);
        players.push_back(p);
    }
}

void BattleRoyale::addPlayer(Player* player) {
    player->debug = this->viewMode == ViewMode::Debug;
    players.push_back(player);
}

void BattleRoyale::update() {
    for (auto& pl : players)
        for (Soldier*& s : pl->army)
            if (!s->dead) s->move();

    map->print(viewMode == ViewMode::Debug);

    for (auto& pl : players)
        for (Soldier*& s : pl->army)
            if (!s->dead) s->combat();
}

void BattleRoyale::play() {
    // Game loop
    Player* loser = NULL;
    while (!loser) {
        
        for (auto& pl : players)
            if (pl->armySize == 0)
                loser = pl;

        update();
        sleep_for(refreshRate);
        if (viewMode == ViewMode::Cinematic) system("cls");
    }
}

void BattleRoyale::destroy() {
    map->destroy();
}