#include <iostream>
#include <ctime>

using namespace std;

// Генерация игрового поля с минами
char** gen_field(int rows, int cols, int bombs) {
    char** field = new char* [rows];
    for (int i = 0; i < rows; i++) {
        field[i] = new char[cols];
        for (int j = 0; j < cols; j++)
            field[i][j] = ' ';
    }

    // Генерация мин
    int bombs_placed = 0;
    while (bombs_placed < bombs) {
        int row = rand() % rows;
        int col = rand() % cols;
        if (field[row][col] != '*') {
            field[row][col] = '*';
            bombs_placed++;
        }
    }

    return field;
}

int main() {
    srand(time(NULL));

    int rows = 9;
    int cols = 9;
    int bombs = 10;

    char** field = gen_field(rows, cols, bombs);

    // Вывод меню
    cout << "Minesweeper" << "\n";
    cout << "1. Play" << "\n";
    cout << "2. Exit" << "\n";
    cout << "Your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        // Вывод игрового поля в консоль
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << field[i][j] << " ";
            }
            cout << "\n";
        }
        break;
    case 2:
        cout << "Exiting game..." << "\n";
        break;
    default:
        cout << "Wrong choice. Exiting game..." << "\n";
        break;
    }

    return 0;
}