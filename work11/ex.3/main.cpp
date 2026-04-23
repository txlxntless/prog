#include <iostream>
#include <fstream>
#include <ctime>
#include "file.cpp" 
#include <algorithm> 
#include <vector>   
#include <utility>   
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0)); // инициализация генератора случайных чисел
    int n, m;
    // ввод размера с проверкой
    do {
        cout << "Введите количество строк (n) и столбцов (m): ";
        cin >> n >> m;
        if (n <= 0 || m <= 0) {
            cout << "Ошибка! Размеры должны быть больше нуля.\n";
        }
    } while (n <= 0 || m <= 0);
    // выделение памяти для двумерного динамического массива (матрицы)
    int** M = new int*[n];
    for (int i = 0; i < n; i++) {
        M[i] = new int[m];
    }
    // меню ввода
    cout << "------Меню ввода------" << endl;
    cout << "1. Ввод с экрана" << endl;
    cout << "2. Ввод из файла" << endl;
    cout << "3. Заполнение случайными числами" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "Введите элементы матрицы:" << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
    }
    else if (choice == 2) {
        // считывание из файла с проверкой
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        ifstream fin(filename);
        if (!fin.is_open()) { 
            cout << "Ошибка: файл не найден или не может быть открыт! Введите матрицу с экрана:" << endl;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    cin >> M[i][j];
        } else {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    fin >> M[i][j];
            fin.close();
        }
    }
    else if (choice == 3) {
        int A, B;
        cout << "Введите интервал [a, b] для случайных чисел: ";
        cin >> A >> B;
        // проверка на корректность интервала
        if (A > B) std::swap(A, B); 
        RandomMatr(M, n, m, A, B);
    }
    else {
        cout << "Некорректный выбор. Матрица будет заполнена нулями." << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                M[i][j] = 0;
    }
// вывод исходной матрицы на экран
    cout << "\nПолученная исходная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
    cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    // вызов функции для упорядочивания столбцов
    SortColumnsBySumDescending(M, n, m);
    // вывод матрицы после упорядочивания на экран
    cout << "\nМатрица после упорядочивания столбцов по убыванию сумм:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    OutFileMatr(M, n, m);    // вывод измененной матрицы в файл
    for (int i = 0; i < n; i++) {
        delete[] M[i];
    }
    delete[] M;
    return 0;
}
