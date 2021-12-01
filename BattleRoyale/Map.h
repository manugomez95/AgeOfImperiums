#pragma once

#include <iostream>
#include <string>
#include <windows.h> // WinApi header
#include "Soldier.h"

#define LOG_COLOR_WHITE 7

class Map {
public:
    int rows, cols;
    Soldier*** matrix;

    Map(int, int);
    void destroy();
    void print();
};

Map::Map(int m, int n) {
    rows = m;
    cols = n;
    matrix = new Soldier * *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new Soldier * [cols];
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
void Map::print() {
    HANDLE hConsole;
    int k;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << endl;
    int i, j;
    for (i = 0; i <= 2 * rows; i++) {
        for (j = 0; j <= 2 * cols; j++) {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                    cout << " ";
                else cout << "---";
            }
            else {
                if (j % 2 == 0)
                    cout << "|";
                else {
                    Soldier* s = matrix[(i - 1) / 2][(j - 1) / 2];
                    if (s != NULL) {
                        SetConsoleTextAttribute(hConsole, 10); // BattleRoyale::getInstance()->players[s->playerId]->color
                        cout << " " << s->str() << " ";
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