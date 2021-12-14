#include "Map.h"
#include "BattleRoyale.h"
#include "GameObject.h"
#include "Utils.h"
#include <windows.h> // WinApi header

using namespace std;

// In this map when a unit reaches the limit, it continues on the contrary side
Map::Map(int m, int n) {
    rows = m;
    cols = n;
    matrix = new GameObject **[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new GameObject * [cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = NULL;
        }
    }
}

void Map::destroy() {
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

// https://stackoverflow.com/questions/48677066/printing-a-grid
void Map::print(bool grid) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << endl;
    int i, j;
    for (i = 0; i <= 2 * rows; i++) {
        for (j = 0; j <= 2 * cols; j++) {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                    cout << " ";
                else if (grid) cout << "---";
            }
            else {
                if (j % 2 == 0 && grid)
                    cout << "|";
                else {
                    GameObject* go = matrix[(i - 1) / 2][(j - 1) / 2];
                    if (go != NULL) {
                        SetConsoleTextAttribute(hConsole, go->color);
                        cout << " " << go->icon << " ";
                        SetConsoleTextAttribute(hConsole, LOG_COLOR_WHITE);
                    }
                    else cout << "   ";
                }
            }
        }
        cout << endl;
    }
    return;
}

array<int, 2> Map::translatePosition(array<int, 2> pos) {
    array<int, 2> new_pos{pos[0],pos[1]};

    if (pos[0] < 0) new_pos[0] = rows + pos[0];
    else if (pos[0] >= rows) new_pos[0] = pos[0] % rows;

    if (pos[1] < 0) new_pos[1] = cols + pos[1];
    else if (pos[1] >= cols) new_pos[1] = pos[1] % cols;

    return new_pos;
}

GameObject* Map::get(array<int, 2> pos) {
    array<int, 2> new_pos = translatePosition(pos);
    return matrix[new_pos[0]][new_pos[1]];
}