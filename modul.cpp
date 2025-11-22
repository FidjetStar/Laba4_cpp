#include "h.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для заполнения матрицы с клавиатуры
void fillKeyboard(vector<vector<int>> &matrix) {
    clearMatrix(matrix);
    int n, m;
    cout << "Введите размер массива n * m" << endl;
    cout << "Введите количество строк: " << endl;
    cin >> n;
    cout << "Введите количество столбцов: " << endl;
    cin >> m;
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);
    }
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Матрица заполнена с клавиатуры!" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для заполнения матрицы случайными числами
void fillRandom(vector<vector<int>> &matrix) {
    clearMatrix(matrix);
    int n, m;
    cout << "Введите размер массива n * m" << endl;
    cout << "Введите количество строк: " << endl;
    cin >> n;
    cout << "Введите количество столбцов: " << endl;
    cin >> m;
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);
    }
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 201 - 100;
        }
    }
    cout << "Матрица заполнена случайными числами!" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void fill_file(vector<vector<int>> &matrix, string filename) {
    int n, m;
    ifstream file(filename);
    if (file.is_open()) {
        file >> n >> m;
        matrix.resize(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                file >> matrix[i][j];
            }
        }
        file.close();
    }
    cout << "Матрица заполнена из файла!" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Matrix29 - вывод в консоль
void matrix29Console(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) {
            sum += double(matrix[i][j]);
        }
        double srznach = sum / double(m);
        cout << "Среднее арифметическое " << i + 1 << " строки = " << srznach << endl;
        int count = 0;
        for (int j = 0; j < m; j++) {
            if (double(matrix[i][j]) < srznach) {
                count++;
            }
        }
        cout << "Строка " << i + 1 << ": " << count << " элементов меньше среднего" << endl;
    }
    cout << endl;
}

// Matrix29 - запись в файл
void matrix29File(vector<vector<int>> &matrix) {
    ofstream file("c.txt");
    if (file.is_open()) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < m; j++) {
                sum += double(matrix[i][j]);
            }
            double srznach = sum / double(m);
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (double(matrix[i][j]) < srznach) {
                    count++;
                }
            }
            file << "Строка " << i + 1 << ": среднее = " << srznach 
                 << ", элементов меньше среднего = " << count << endl;
        }
        file.close();
        cout << "Результаты Matrix29 записаны в файл c.txt" << endl;
    }
    cout << endl;
}

// Matrix59 - вывод в консоль
void matrix59Console(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    // Создаем копию матрицы чтобы не изменять оригинал
    vector<vector<int>> tempMatrix = matrix;
    
    // Отражаем строки относительно горизонтали
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m; j++) {
            int temp = tempMatrix[i][j];
            tempMatrix[i][j] = tempMatrix[n - 1 - i][j];
            tempMatrix[n - 1 - i][j] = temp;
        }
    }
    
    cout << "Преобразованная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << tempMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Matrix59 - запись в файл
void matrix59File(vector<vector<int>> &matrix) {
    ofstream file("c.txt");
    if (file.is_open()) {
        int n = matrix.size();
        int m = matrix[0].size();
        // Создаем копию матрицы чтобы не изменять оригинал
        vector<vector<int>> tempMatrix = matrix;
        
        // Отражаем строки относительно горизонтали
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m; j++) {
                int temp = tempMatrix[i][j];
                tempMatrix[i][j] = tempMatrix[n-1-i][j];
                tempMatrix[n-1-i][j] = temp;
            }
        }
        
        file << "Преобразованная матрица:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                file << tempMatrix[i][j] << " ";
            }
            file << endl;
        }
        file.close();
        cout << "Результаты Matrix59 записаны в файл c.txt" << endl;
    }
    cout << endl;
}

// Функция для очистки матрицы
void clearMatrix(vector<vector<int>> &matrix) {
    matrix.clear();
    cout << "Матрица очищена!" << endl;
}