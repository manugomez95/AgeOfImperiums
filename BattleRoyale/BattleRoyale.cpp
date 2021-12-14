#include "BattleRoyale.h"
#include "Utils.h"
#include "Player.h"
#include "Map.h"
#include <chrono>
#include <thread>
#include "Consumable.h"

using namespace std;
using namespace chrono_literals; // ns, us, ms, s, h, etc.
using chrono::system_clock;
using namespace this_thread;

// TODO make some variables private

BattleRoyale* BattleRoyale::instance = NULL;

BattleRoyale::BattleRoyale(ViewMode viewMode) {
    this->viewMode = viewMode;
    refreshRate = this->viewMode == ViewMode::Cinematic ? 1000ms : 3000ms;
}

void BattleRoyale::launchMenu() {
    cout << "Hi, welcome to Age Of Imperiums!" << endl << endl;
    cout << "Watch the action with Debug (d) or Cinematic (c) mode?" << endl;

    string viewMode;
    cin >> viewMode;

    BattleRoyale* game = BattleRoyale::create(viewMode == "c" ?
        ViewMode::Cinematic : ViewMode::Debug);

    cout << endl << "Let's define the map's size." << endl;
    cout << endl << "How many rows?" << endl;
    int rows;
    cin >> rows;

    cout << endl << "How many columns?" << endl;
    int cols;
    cin >> cols;

    Map* map = new Map(rows, cols);
    game->setMap(map);

    cout << endl << "Enter the number of players:" << endl;

    int nPlayers;
    cin >> nPlayers;

    for (int i = 0; i < nPlayers; i++) {
        cout << endl << "Enter the army size of P" << i + 1 << endl;
        int armySize;
        cin >> armySize;
        Player* p = new Player(armySize);
        game->addPlayer(p);
    }

    cout << endl << "Lastly, I'm throwing some health potions on the map. How many?" << endl;

    int n_potions;
    cin >> n_potions;

    for (int i = 0; i < n_potions; i++)
        map->add(new HealthPotion(map, { -1,-1 }));

    cout << "Done! Starting game...";
    sleep_for(1000ms);
    game->play();
}

BattleRoyale* BattleRoyale::create(ViewMode viewMode) {
    if (instance != NULL) {
        return instance;
    }
    instance = new BattleRoyale(viewMode);
    return instance;
}

BattleRoyale* BattleRoyale::getInstance() {
    return instance;
}

void BattleRoyale::setMap(Map* map) {
    this->map = map;
}

Map* BattleRoyale::getMap() {
    return map;
}

// TODO deprecated? revisar
void BattleRoyale::initPlayers(int n_players, int army_size) {
    for (int i = 0; i < n_players; i++) {
        Player* p = new Player(army_size);
        players.push_back(p);
    }
}

void BattleRoyale::addPlayer(Player* player) {
    player->debug = this->viewMode == ViewMode::Debug;
    players.push_back(player);
}

void BattleRoyale::update() {
    for (auto& pl : players)
        for (Soldier*& s : pl->army)
            if (!s->dead) s->move();

    map->print(viewMode == ViewMode::Debug);

    for (auto& pl : players)
        for (Soldier*& s : pl->army)
            if (!s->dead) s->combat();
}

void BattleRoyale::play() {
    // Game loop
    Player* loser = NULL;
    while (!loser) {
        if (viewMode == ViewMode::Cinematic) system("cls");
        for (auto& pl : players)
            if (pl->armySize == 0)
                loser = pl;

        update();
        sleep_for(refreshRate);
    }

    // TODO show winner message
}

void BattleRoyale::destroy() {
    map->destroy();
}