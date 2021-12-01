#include "BattleRoyale.h"
using namespace std;

// TODO make some variables private

BattleRoyale* BattleRoyale::instance = NULL;

BattleRoyale* BattleRoyale::create(int n) {
    if (instance != NULL) {
        return instance;
    }
    instance = new BattleRoyale(n);
    return instance;
}

BattleRoyale* BattleRoyale::getInstance() {
    return instance;
}

BattleRoyale::BattleRoyale(int n) {
    nPlayers = n;
    for (int i = 0; i < n; i++) players.push_back(Player(30));
    map = new Map(25, 50);
    
    map->matrix[0][0] = &players[0].army[0];
    map->matrix[1][1] = &players[1].army[0];
}

/*void BattleRoyale::start() {
    Player* winner = NULL;
    while (winner == NULL) {
        playFrame();
    }
}*/

void BattleRoyale::destroy() {
    map->destroy();
}