#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip> // для адекватного вывода вещественных чисел(2 знака после ",")
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
    // выделение памяти под double
    double** M = new double*[n];
    for (int i = 0; i < n; i++) {
        M[i] = new double[m];
    }
    // меню ввода
    cout << "------Меню ввода------" << endl;
    cout << "1. Ввод с экрана" << endl;
    cout << "2. Ввод из файла" << endl;
    cout << "3. Заполнение случайными вещественными числами" << endl;
    int choice;     cin >> choice;
    if (choice == 1) {
        cout << "Введите элементы матрицы (вещественные числа):" << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
    } 
    else if (choice == 2) {
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        ifstream fin(filename);
        if (!fin) {
            cout << "Ошибка: файл не найден! Введите матрицу с экрана:" << endl;
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
        double A, B;
        cout << "Введите интервал [a, b]: ";
        cin >> A >> B;
        RandomMatr(M, n, m, A, B);
    }
    // вывод на экран
    cout << "\nПолученная матрица:" << endl;
    cout << fixed << setprecision(2); // вывод с 2 знаками после запятой
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    OutFileMatr(M, n, m);    // вывод в файл
    for (int i = 0; i < n; i++) {
        delete[] M[i];
    }
    delete[] M;
    return 0;
}
