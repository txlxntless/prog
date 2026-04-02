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
        cout << "Ошибка при открытии файла для записи!" << endl;
    }
}
