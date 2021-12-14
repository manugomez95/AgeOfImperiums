#include "BattleRoyale.h"

using namespace std;

BattleRoyale* soldierDemo() {
    BattleRoyale* game = BattleRoyale::create();

    // Map
    game->setMap(new Map(10, 10));

    // Create players
    Player* p1 = new Player(7, true); // debug logging true
    game->players.push_back(p1);

    Player* p2 = new Player(10, true);
    game->players.push_back(p2);
    
    return game;
}

int main()
{    
    soldierDemo()->play();
}