#include "BattleRoyale.h"
#include "Consumable.h"
#include "Map.h"
#include "Player.h"

using namespace std;

BattleRoyale* demo() {
    Map* map = new Map(12, 12);
    int n_potions = 4;
    for (int i = 0; i < n_potions; i++)
        new HealthPotion(map);
    BattleRoyale* game = new BattleRoyale(map, ViewMode::Debug);
    game->addPlayer(3); // change this so I only define size
    game->addPlayer(10);
    return game;
}

int main()
{   
    demo()->play();
    //BattleRoyale::launchMenu();
}