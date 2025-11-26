#include "h.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillKeyboard(vector<vector<int>> &matrix) {
    clearMatrix(matrix);
    int n, m;
    cout << "Введите размер массива n * m" << endl;                                                     
    cout << "Введите количество строк: " << endl;
    cin >> n;
    cout << "Введите количество столбцов: " << endl;
    cin >> m;
    if (n <= 0 || m <= 0) {
        cout << "Error: неверный размер матрицы!" << endl;
        return;
    }
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

void fillRandom(vector<vector<int>> &matrix) {
    clearMatrix(matrix);
    int a,b;
    int n, m;
    cout << "Введите размер массива n * m" << endl;
    cout << "Введите количество строк: " << endl;
    cin >> n;
    cout << "Введите количество столбцов: " << endl;
    cin >> m;
    cout << "Введите диапазон чисел от a до b" << endl;
    cin >> a >> b;
    if (n <= 0 || m <= 0) {
        cout << "Error: неверный размер матрицы!" << endl;
        return;
    }
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);
    }
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (b - a + 1) + a;
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
    if (!file.is_open()) {
        cout << "Error: нет такого файла" << endl;
        return;
    }
    file >> n >> m;
    if (n <= 0 || m <= 0) {
        cout << "Error: неверный размер матрицы в файле!" << endl;
        return;
    }
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);
        for (int j = 0; j < m; j++) {
            if (!(file >> matrix[i][j])) {
                cout << "Error: ошибка чтения данных из файла!" << endl;
                matrix.clear();
                return;
            }
        }
    }
    file.close();
    cout << "Матрица заполнена из файла!" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void matrix29Console(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        cout << "Error: матрица пустая!" << endl;
        return;
    }
    int n = matrix.size(); // количество строк 
    int m = matrix[0].size(); // количество эл в первой строке равное количеству слобцов => количество столбцов
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

void matrix29File(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        cout << "Error: матрица пустая!" << endl;
        return;
    }
    ofstream file("c.txt");
    if (!file.is_open()) {
        cout << "Error: не удалось создать файл c.txt" << endl;
        return;
    }
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

void matrix59Console(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        cout << "Error: матрица пустая!" << endl;
        return;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> tempMatrix = matrix;
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

void matrix59File(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        cout << "Error: матрица пустая!" << endl;
        return;
    }
    ofstream file("c.txt");
    if (!file.is_open()) {
        cout << "Error: не удалось создать файл c.txt" << endl;
        return;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> tempMatrix = matrix;
    
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m; j++) {
            int temp = tempMatrix[i][j];
            tempMatrix[i][j] = tempMatrix[n - 1 - i][j];
            tempMatrix[n - 1 - i][j] = temp;
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
void darray3console(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        cout << "Матрица пуста" << endl;
        return;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    int h = 0;
    int l = 0;
    if (n != m) {
        cout << "Матрица не квадратная" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < m; j++) {
            h = h + matrix[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = n - i; j < n; j++) {
            l += matrix[i][j];
        }
    }
    cout << "Сумма выше главной диагонали = " << h << endl;
    cout << "Сумма ниже побочной диагонали = " << l << endl;
}   
void darray3file(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        cout << "Матрица пуста" << endl;
        return;
    }
    ofstream file("c.txt");
    if (!file.is_open()) {
        cout << "Error: не удалось открыть файл " << endl;
        return;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    int h = 0;
    int l = 0;
    if (n != m) {
        cout << "Матрица не квадратная" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < m; j++) {
            h = h + matrix[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = n - i; j < n; j++) {
            l += matrix[i][j];
        }
    }
    file << "Сумма выше главной диагонали = " << h << endl;
    file << "Сумма ниже главной диагонали = " << l << endl;
    file.close();
    cout << "Результаты darray3 записаны в файл c.txt" << endl;
    cout << endl;
}
void darray16console(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        cout << "Матрица пуста" << endl;
        return;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum_neighbors = 0;
            int neighbor_count = 0;
            if (i > 0) { // сверху
                sum_neighbors += matrix[i-1][j];
                neighbor_count++;
            }
            if (i < n-1) { // снизу
                sum_neighbors += matrix[i+1][j];
                neighbor_count++;
            }
            if (j > 0) { // слева
                sum_neighbors += matrix[i][j-1];
                neighbor_count++;
            }
            if (j < m-1) { // справа
                sum_neighbors += matrix[i][j+1];
                neighbor_count++;
            }
            // Сравниваем элемент с суммой соседей
            if (neighbor_count > 0 && matrix[i][j] == sum_neighbors) {
                cnt++;
                cout << "Элемент [" << i << "][" << j << "] = " << matrix[i][j] 
                     << " равен сумме соседей: " << sum_neighbors << endl;
            }
        }
    }
    cout << "Количество таких элементов: " << cnt << endl;
}
void darray16file(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        cout << "Матрица пуста" << endl;
        return;
    }
    ofstream file("c.txt");
    if (!file.is_open()) {
        cout << "Error: не удалось открыть файл " << endl;
        return;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file << matrix[i][j] << " ";
        }
        file << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum_neighbors = 0;
            int neighbor_count = 0;
            if (i > 0) { // сверху
                sum_neighbors += matrix[i-1][j];
                neighbor_count++;
            }
            if (i < n-1) { // снизу
                sum_neighbors += matrix[i+1][j];
                neighbor_count++;
            }
            if (j > 0) { // слева
                sum_neighbors += matrix[i][j-1];
                neighbor_count++;
            }
            if (j < m-1) { // справа
                sum_neighbors += matrix[i][j+1];
                neighbor_count++;
            }
            // Сравниваем элемент с суммой соседей
            if (neighbor_count > 0 && matrix[i][j] == sum_neighbors) {
                cnt++;
                file << "Элемент [" << i << "][" << j << "] = " << matrix[i][j] 
                     << " равен сумме соседей: " << sum_neighbors << endl;
            }
        }
    }
    file << "Количество таких элементов: " << cnt << endl;
    file.close();
    cout << "Результаты darray3 записаны в файл c.txt" << endl;
    cout << endl;
}
void clearMatrix(vector<vector<int>> &matrix) {
    matrix.clear();
    cout << "Матрица очищена!" << endl;
}
