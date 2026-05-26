#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> 

using namespace std;

// SETTING
const int width = 60;
const int height = 30;
const int stepDefault = 600;
char map[height][width];


int main() {
    srand(time(0)); 

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = '#';
        }
    }

    // RANDOM WALK
    int pX = width / 2;  
    int pY = height / 2;
    int startX = pX, startY = pY; 

    map[pY][pX] = ' '; 
    int steps = stepDefault;   

    while (steps > 0) {
        int dir = rand() % 4; 

        // Di chuyen tho mo
        if (dir == 0 && pY > 1) pY--;
        else if (dir == 1 && pY < height - 2) pY++;
        else if (dir == 2 && pX > 1) pX--;
        else if (dir == 3 && pX < width - 2) pX++;

        // Pha tuong
        if (map[pY][pX] == '#') {
            map[pY][pX] = ' ';
            steps--;
        }
    }

    // Cua ra
    int exitX = pX, exitY = pY;
    map[exitY][exitX] = 'E';
    // Nguoi choi
    pX = startX; pY = startY;
    map[pY][pX] = 'P';


    // GAME START
    bool playing = true;
    while (playing) {
        system("cls"); 

        // Ve map
        cout << "=== CLB NHA SANG TAO GAME PTIT<3 ===" << "\n\n";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << map[i][j] << " "; 
            }
            cout << endl;
        }
        cout << "\nDung W A S D de di chuyen 'P' toi cua 'E'!" << endl;

        // Di chuyen
        char move = _getch();

        int nextX = pX, nextY = pY;
        if (move == 'w' || move == 'W') nextY--;
        if (move == 's' || move == 'S') nextY++;
        if (move == 'a' || move == 'A') nextX--;
        if (move == 'd' || move == 'D') nextX++;

        // Kiem tra va cham
        if (map[nextY][nextX] == ' ' || map[nextY][nextX] == 'E') {
            
            if (map[nextY][nextX] == 'E') {
                system("cls");
                cout << "\n\n   HIEN THUC HOA UOC MO   \n   HIEN THUC HOA UOC MO   \n   HIEN THUC HOA UOC MO   \n\n";
                playing = false; 
            }

            map[pY][pX] = ' ';

            pX = nextX;
            pY = nextY;

            if (playing) map[pY][pX] = 'P';
        }
    }
    return 0;
}