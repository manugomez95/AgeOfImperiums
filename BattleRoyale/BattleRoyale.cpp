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
    players = new Player * [nPlayers];
    for (int i = 0; i < nPlayers; i++) {
        players[i] = new Player(30 * (i + 1)); // TODO revisar
    }
    map = new Map(25, 50);
    map->matrix[0][0] = &players[0]->army[0];
    map->matrix[1][1] = &players[1]->army[0];
}

/*void BattleRoyale::start() {
    Player* winner = NULL;
    while (winner == NULL) {
        playFrame();
    }
}*/

void BattleRoyale::destroy() {
    for (int i = 0; i < nPlayers; i++) {
        players[i]->destroy();
    }
    map->destroy();
}