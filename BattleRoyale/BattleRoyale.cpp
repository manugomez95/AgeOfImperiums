#include <chrono>
#include <thread>
#include <iostream>

#include "BattleRoyale.h"
#include "Utils.h"
#include "Player.h"
#include "Map.h"
#include "Consumable.h"
#include "Soldier.h"

using namespace std;
using namespace chrono_literals; // ns, us, ms, s, h, etc.
using chrono::system_clock;
using namespace this_thread;

BattleRoyale::BattleRoyale(Map* map, ViewMode viewMode) {
    this->viewMode = viewMode;
    this->map = map;
    refreshRate = this->viewMode == ViewMode::Minimalist ? 1000ms : 3000ms;
}

void BattleRoyale::launchMenu() {
    cout << "Hi, welcome to Age Of Imperiums!" << endl << endl;
    cout << "This application simulates a battle between N players, each with an army." << endl << endl;
    cout << "You can watch the action on Debug (d) or Minimalist (m) mode. Please choose one:" << endl;

    string viewMode;
    cin >> viewMode;

    cout << endl << "Great. Let's define the size of the map (as a grid):" << endl;
    cout << endl << "Enter rows:" << endl;
    int rows;
    cin >> rows;

    cout << endl << "Enter columns:" << endl;
    int cols;
    cin >> cols;

    Map* map = new Map(rows, cols);

    BattleRoyale* game = new BattleRoyale(map, viewMode == "m" ?
        ViewMode::Minimalist : ViewMode::Debug);

    cout << endl << "Now, how many players?" << endl;

    int nPlayers;
    cin >> nPlayers;

    for (int i = 0; i < nPlayers; i++) {
        cout << endl << "- Army size of P" << i + 1 << endl;
        int armySize;
        cin >> armySize;
        game->addPlayer(armySize);
    }

    cout << endl << "Lastly, let's throw some health potions on the map. How many?" << endl;

    int n_potions;
    cin >> n_potions;

    for (int i = 0; i < n_potions; i++)
        new HealthPotion(map);

    cout << endl << "Done! Starting game..." << endl;
    sleep_for(1000ms);
    game->play();
}

void BattleRoyale::addPlayer(int armySize) {
    Player* player = new Player(map, armySize, this->viewMode == ViewMode::Debug);
    players.push_back(player);
}

void BattleRoyale::update() {
    for (auto& pl : players)
        for (Soldier*& s : pl->getArmy())
            if (!s->isDead()) s->move();

    map->print(viewMode == ViewMode::Debug);

    for (auto& pl : players)
        for (Soldier*& s : pl->getArmy())
            if (!s->isDead()) s->combat();
}

void BattleRoyale::play() {
    // Game loop
    Player* loser = NULL;
    while (!loser) {
        if (viewMode == ViewMode::Minimalist) system("cls");
        for (auto& pl : players)
            if (pl->getArmySize() == 0)
                loser = pl;

        update();
        sleep_for(refreshRate);
    }

    // TODO show winner message
}

Map* BattleRoyale::getMap() {
    return map;
}

// TODO finish
void BattleRoyale::destroy() {
    map->destroy();
}