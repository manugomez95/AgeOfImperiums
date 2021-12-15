#include <chrono>
#include <thread>
#include <iostream>
#include <windows.h> // WinApi header

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
    // Movement turn
    for (auto& pl : players)
        for (Soldier*& s : pl->getArmy())
            if (!s->isDead()) s->move();

    // Print map
    map->print(viewMode == ViewMode::Debug);

    // Combat turn
    for (auto& pl : players)
        for (Soldier*& s : pl->getArmy())
            if (!s->isDead()) s->combat();
}

void BattleRoyale::play() {
    printBegginingText();

    int remainingPlayers = players.size();

    // Game loop
    while (remainingPlayers> 1) {
        if (viewMode == ViewMode::Minimalist) system("cls");

        // Remove if armySize == 0
        for (auto& pl : players) {
            if (!pl->getEliminated() && !pl->getArmySize()) {
                pl->setEliminated(true);
                remainingPlayers--;
            }
        }

        update();
        sleep_for(refreshRate);
    }

    Player* winner = NULL;
    for (auto& pl : players)
        if (!pl->getEliminated()) winner = pl;
    cout << endl << "The winner is " << winner->str() << "!!" << endl << endl;
    destroy();
}

void BattleRoyale::printBegginingText() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (unsigned int i = 0; i < players.size(); i++) {
        SetConsoleTextAttribute(hConsole, players[i]->getColor());
        cout << players[i]->str();
        SetConsoleTextAttribute(hConsole, WHITE);
        if (i < players.size() - 1) cout << " vs ";
    }
    cout << endl << endl;
}

Map* BattleRoyale::getMap() {
    return map;
}

void BattleRoyale::destroy() {
    map->destroy();
    for (auto& pl : players)
        pl->destroy();
    delete this;
}