#include <iostream>
#include <fstream>
#include <algorithm> // для swap и sort
#include <vector>    // для vector
#include <utility>   // для pair (используется в vector<pair>)
using namespace std;

// функция заполнения матрицы случайными числами
void RandomMatr(int** M, int n, int m, int A, int B) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            M[i][j] = A + rand() % (B - A + 1);
        }
    }
}
// функция вывода матрицы в файл
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
// новая функция: упорядочить столбцы матрицы по убыванию сумм элементов в них
void SortColumnsBySumDescending(int** M, int n, int m) {
    if (n <= 0 || m <= 0) {
        cout << "Ошибка: Матрица пуста или имеет некорректные размеры." << endl;
        return;
    }
    if (m == 1) { // если всего один столбец, то нечего упорядочивать
        cout << "Матрица имеет только один столбец. Упорядочение не требуется." << endl;
        return;
    }
}
