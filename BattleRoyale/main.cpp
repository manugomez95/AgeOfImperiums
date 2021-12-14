#include "BattleRoyale.h"

using namespace std;

BattleRoyale* soldierDemo() {
    BattleRoyale* game = BattleRoyale::create(ViewMode::Debug);

    // Map
    game->setMap(new Map(10, 10));

    // Create players
    Player* p1 = new Player(10);
    game->addPlayer(p1);

    Player* p2 = new Player(10);
    game->addPlayer(p2);
    
    return game;
}

int main()
{   
    soldierDemo()->play();
}