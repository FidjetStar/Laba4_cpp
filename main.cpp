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
        cout << "3. Заполнить двумерный массив из файла (b.txt)" << endl;
        cout << "4. Задание Matrix29 - ответы выводятся в консоль и в файл " << endl;
        cout << "5. Задание Matrix59 - ответы выводятся в консоль и в файл " << endl;
        cout << "6. Задание DArray3(Матрица должна быть квадратная) - ответы выводятся в консоль и в файл " << endl;
        cout << "7. Задание DArray16 - ответы выводятся в консоль и в файл " << endl;
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
            case 4: { // 29 //
                matrix29Console(matrix);
                matrix29File(matrix);
                break;
            }
            case 5: { // 59 //
                matrix59Console(matrix);
                matrix59File(matrix);
                break;
            }
            case 6: {
                darray3console(matrix);
                darray3file(matrix);
                break;
            }
            case 7: {
                darray16console(matrix);
                darray16file(matrix); 
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
/*
matrix - это vector<vector<int>> (вектор векторов)
resize(n) устанавливает, что во внешнем векторе будет n элементов
Каждый элемент внешнего вектора - это отдельный вектор (строка матрицы)
После этой операции у нас есть n пустых строк
matrix[0] = []  (пустой вектор)
matrix[1] = []  (пустой вектор)  
matrix[2] = []  (пустой вектор)
Проходим по каждой строке (от 0 до n-1)
matrix[i].resize(m) устанавливает, что в каждой строке будет m элементов
Все элементы инициализируются значением по умолчанию (для int - это 0)
matrix[0] = [0, 0, 0, ..., 0]  (m нулей)
matrix[1] = [0, 0, 0, ..., 0]  (m нулей)
matrix[2] = [0, 0, 0, ..., 0]  (m нулей)
*/
