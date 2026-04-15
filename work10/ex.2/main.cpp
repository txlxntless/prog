#include <iostream>
#include <fstream>
#include <ctime>
#include "file.cpp"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
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
    fillChoice(M, n, m, choice);
    // вывод всей матрицы на экран
    cout << "\nПолученная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    // новое задание
    if (n != m) {
        cout << "\nОшибка: Операции с главной диагональю возможны только для квадратных матриц (n=m)!" << endl;
    } else {
        // 1. поиск максимума на главной диагонали
        int max_diag = M[0][0];
        int max_idx = 0;
        for (int i = 1; i < n; i++) {
            if (M[i][i] > max_diag) {
                max_diag = M[i][i];
                max_idx = i;
            }
        }

        // 2. Вывод элементов диагонали в диагональном виде
        cout << "\nЭлементы главной диагонали в диагональном виде:" << endl;
        for (int i = 0; i < n; i++) {
            // Печатаем отступы (табуляции), чтобы сдвинуть элемент
            for (int j = 0; j < i; j++) {
                cout << "\t";
            }
            cout << M[i][i] << endl;
        }

        cout << "\nМаксимальный элемент на главной диагонали: " << max_diag << endl;
        cout << "Его позиция: строка " << max_idx << ", столбец " << max_idx << endl;
    }
    OutFileMatr(M, n, m); // вывод в файл
    for (int i = 0; i < n; i++) {
        delete[] M[i];
    }
    delete[] M;
    return 0;
}
