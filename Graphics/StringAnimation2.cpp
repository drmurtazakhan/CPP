#include <iostream>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    int x = 5, y = 5;
    const int width = 60, height = 20;

    while (x < width && y < height) {
        system("cls");  // Clear screen
        gotoxy(x, y);
        cout << "String Animation";
        x += 1;
        y += 1;
        Sleep(100);  // Delay for animation
    }

    return 0;
}
