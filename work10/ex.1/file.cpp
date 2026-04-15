#include <iostream>
#include <fstream>
using namespace std;

// функция заполнения случайными числами
void RandomMatr(int** M, int n, int m, int A, int B) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            M[i][j] = A + rand() % (B - A + 1);
        }
    }
}
// функция заполнения в зависимости от выбора пользователя
void fillChoice(int choice, int n, int m, int** M) {
    if (choice == 1) {
            cout << "Введите элементы матрицы:" << endl;
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
            int A, B;
            cout << "Введите интервал [a, b]: ";
            cin >> A >> B;
            RandomMatr(M, n, m, A, B);
        }
    }
    // функция вывода в файл
    void OutFileMatr(int** M, int n, int m) {
        ofstream fout("output_matrix.txt");
        if (fout.is_open()) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    fout << M[i][j] << " ";
                }
                fout << endl;
            }
            fout.close();
            cout << "\nМатрица успешно сохранена в файл output_matrix.txt" << endl;
        } else {
            cout << "Ошибка при открытии файла!" << endl;
        }
}
