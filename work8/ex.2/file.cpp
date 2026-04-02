#include <iostream>
#include <fstream>
#include <iomanip> 
using namespace std;

// функция заполнения случайными вещественными числами
void RandomMatr(double** M, int n, int m, double A, double B) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // генерация числа от 0 до 1
            double r = (double)rand() / RAND_MAX;
            // масштабирование под интервал [A, B]
            M[i][j] = A + r * (B - A);
        }
    }
}
// функция вывода в файл
void OutFileMatr(double** M, int n, int m) {
    ofstream fout("output_matrix.txt");
    if (fout.is_open()) {
        fout << fixed << setprecision(2); // сохранение с точностью 2 знака
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
