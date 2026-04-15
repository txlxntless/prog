#include <iostream>
#include <fstream>
#include <ctime>
#include "file.cpp"
using namespace std;

int main() {
    srand(time(0));
    int n, m;
    // ввод размера с проверкой
    do {
        cout << "Введите количество строк (n) и столбцов (m): ";
        cin >> n >> m;
        if (n <= 0 || m <= 0) {
            cout << "Ошибка! Размеры должны быть больше нуля.\n";
        }
    } while (n <= 0 || m <= 0);
    // выделение памяти
    int** M = new int*[n];
    for (int i = 0; i < n; i++) {
        M[i] = new int[m];
    }
    // меню ввода
    cout << "------Меню ввода------" << endl;
    cout << "1. Ввод с экрана" << endl;
    cout << "2. Ввод из файла" << endl;
    cout << "3. Заполнение случайными числами" << endl;
    int choice; cin >> choice;
    fillChoice(choice, n, m, M);
    // вывод на экран
    cout << "\nПолученная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    // 1. максимальный элемент в k-ом столбце
    int k_col;
    cout << "\nВведите номер столбца k для поиска MAX (0.." << m - 1 << "): ";
    cin >> k_col;
    if (k_col >= 0 && k_col < m) {
        int max_val = M[0][k_col];
        int max_pos = 0;
        for (int i = 1; i < n; i++) {
            if (M[i][k_col] > max_val) {
                max_val = M[i][k_col];
                max_pos = i;
            }
        }
        cout << "Максимальный элемент в " << k_col << "-м столбце: " << max_val 
             << " (позиция: строка " << max_pos << ")" << endl;
    } else {
        cout << "Ошибка: неверный индекс столбца!" << endl;
    }
    // 2. минимальный элемент в k-ой строке
    int k_row;
    cout << "\nВведите номер строки k для поиска MIN (0.." << n - 1 << "): ";
    cin >> k_row;
    if (k_row >= 0 && k_row < n) {
        int min_val = M[k_row][0];
        int min_pos = 0;
        for (int j = 1; j < m; j++) {
            if (M[k_row][j] < min_val) {
                min_val = M[k_row][j];
                min_pos = j;
            }
        }
        cout << "Минимальный элемент в " << k_row << " строке: " << min_val 
             << " (позиция: столбец " << min_pos << ")" << endl;
    } else {
        cout << "Ошибка: неверный индекс строки!" << endl;
    }
    OutFileMatr(M, n, m); // вывод в файл
    for (int i = 0; i < n; i++) {
        delete[] M[i];
    }
    delete[] M;
    return 0;
}
