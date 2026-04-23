#include <iostream>
#include <fstream>
#include <algorithm> // для swap
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
// новая функция: Переставить местами первый столбец и столбец с последним максимальным элементом
void SwapFirstColumnWithLastMaxColumn(int** M, int n, int m) {
    if (n <= 0 || m <= 0) {
        cout << "Ошибка: Матрица пуста или имеет некорректные размеры." << endl;
        return;
    }
    if (m == 1) {
        cout << "Матрица имеет только один столбец. Перестановка не требуется." << endl;
        return;
    }
    int maxVal = M[0][0];
    int maxColIndex = 0; // индекс столбца, содержащего последний максимальный элемент
    // находим максимальный элемент и индекс столбца его последнего вхождения, чтобы 
    // 'maxColIndex' всегда указывал на самый правый/нижний из максимальных.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j] >= maxVal) { // используем >= чтобы найти последнее вхождение при равных значениях
                maxVal = M[i][j];
                maxColIndex = j;
            }
        }
    }
    if (maxColIndex == 0) {
        cout << "Максимальный элемент уже находится в первом столбце. Перестановка не требуется." << endl;
        return;
    }
    cout << "\n--- Информация о перестановке столбцов" << endl;
    cout << "Максимальный элемент: " << maxVal << " найден в столбце с индексом: " << maxColIndex << " (это столбец #" << maxColIndex + 1 << ")" << endl;
    cout << "Первый столбец (индекс 0) будет переставлен со столбцом с индексом " << maxColIndex << "." << endl;
    // выполняем перестановку столбцов
    for (int i = 0; i < n; i++) {
        std::swap(M[i][0], M[i][maxColIndex]);
    }
    cout << "Столбцы успешно переставлены." << endl;
}
