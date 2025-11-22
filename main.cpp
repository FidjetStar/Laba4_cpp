#include <iostream>
#include <vector>
#include <string>
#include "h.h"
#ifdef _WIN64
#include <windows.h>
#endif
using namespace std;

int main() {
    #ifdef _WIN64
    SetConsoleOutputCP(65001);
    #endif
    vector<vector<int>> matrix;
    int choice;
    do {
        cout << "1. Заполнить двумерный массив с клавиатуры" << endl;
        cout << "2. Заполнить двумерный массив случайными числами" << endl;
        cout << "3. Заполнить двумерный массив из файла" << endl;
        cout << "4. Задание Matrix29" << endl;
        cout << "5. Задание Matrix59" << endl;
        cout << "777. Выход" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                fillKeyboard(matrix);
                break;
            }
            case 2: {
                fillRandom(matrix);
                break;
            }
            case 3: {
                clearMatrix(matrix);
                string filename;
                cout << "Введите имя файла: ";
                cin >> filename;
                fill_file(matrix, filename);
                break;
            }
            case 4: {
                matrix29Console(matrix);
                matrix29File(matrix);
                break;
            }
            case 5: {
                matrix59Console(matrix);
                matrix59File(matrix);
                break;
            }
            case 777:
                cout << "Работа завершена" << endl;
                break;
            default:
                cout << "Неверные данные" << endl;
                break;
        }
    } while (choice != 777);
    return 0;
}