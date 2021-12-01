#include <iostream>
#include <string>
#include "BattleRoyale.h"
using namespace std;

int main()
{
    BattleRoyale* game = BattleRoyale::create(2);
    game->map->print();
}