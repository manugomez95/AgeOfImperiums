#include "BattleRoyale.h"
#include "Consumable.h"
#include "Map.h"
#include "Player.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono_literals; // ns, us, ms, s, h, etc.
using chrono::system_clock;
using namespace this_thread;

BattleRoyale* demo() {
    BattleRoyale* game = BattleRoyale::create(ViewMode::Debug);
    Map* map = new Map(12, 12);
    int n_potions = 4;
    for (int i=0; i<n_potions; i++)
        map->add(new HealthPotion(map, { -1,-1 }));
    game->setMap(map);
    game->addPlayer(new Player(10));
    game->addPlayer(new Player(10));
    return game;
}

int main()
{   
    //demo()->play();
    BattleRoyale::launchMenu();
}