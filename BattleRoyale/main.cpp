#include "BattleRoyale.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;
using namespace chrono_literals; // ns, us, ms, s, h, etc.
using chrono::system_clock;

int main()
{
    BattleRoyale* game = BattleRoyale::create();
    game->setMap(new Map(25, 50));
    game->initPlayers(2);
    while (true) {
        game->update();
        sleep_for(1000ms);
        system("cls");
    }
}