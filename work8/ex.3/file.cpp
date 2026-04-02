#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// функция для выделения памяти
double** allocateMatr(int n, int m) {
    double** M = new double*[n];
    for (int i = 0; i < n; i++) {
        M[i] = new double[m];
    }
    return M;
}
// функция для освобождения памяти
void freeMem(double** M, int n) {
    for (int i = 0; i < n; i++) {
        delete[] M[i];
    }
    delete[] M;
    cout << "\nПамять успешно очищена." << endl;
}
// функция заполнения случайными вещественными числами
void RandomMatr(double** M, int n, int m, double A, double B) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double r = (double)rand() / RAND_MAX;
            M[i][j] = A + r * (B - A);
        }
    }
}
// функция вывода в файл с форматированием
void OutFileMatr(double** M, int n, int m) {
    ofstream fout("output_matrix.txt");
    if (fout.is_open()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                fout << setw(3) << M[i][j] << " ";
            }
            fout << endl;
        }
        fout.close();
        cout << "\nМатрица сохранена в output_matrix.txt" << endl;
    }
}
