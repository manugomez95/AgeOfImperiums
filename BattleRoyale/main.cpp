#include <iostream>
#include <string>
#include "BattleRoyale.h"
using namespace std;

int main()
{
    BattleRoyale* game = BattleRoyale::create(2);
    cout << game->players[0]->str() << endl;
    cout << game->players[1]->str() << endl;
    game->map->print();
}