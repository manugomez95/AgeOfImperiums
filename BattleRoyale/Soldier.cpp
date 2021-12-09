#include "Soldier.h"
#include "Utils.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
using namespace std;

Soldier::Soldier(Player* player, Map* map, array<int,2> pos) : GameObject(map, pos) {
    this->player = player;
    velocity = 1;
    icon = char(2);
    color = player->color;
}

void Soldier::action() {
    // Move randomly
    move(GameObject::DIRECTIONS[Utils::randomRange(0, 3)]);

    // Attack if enemy near
    //vector<Soldier*> enemies = getEnemiesAround();
}

/*vector<Soldier*> Soldier::getEnemiesAround() {
    for (auto d : Transform::DIRECTIONS) {
        transform->map->matrix[transform->pos[0] + d[0]];
    }
}*/