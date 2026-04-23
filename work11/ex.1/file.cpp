#include <iostream>
#include <fstream>
#include <algorithm> // Для swap
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
// новая функция: переставить местами максимальный и минимальный элементы
void SwapMinMaxElements(int** M, int n, int m) {
    if (n <= 0 || m <= 0) {
        cout << "Ошибка: Матрица пуста или имеет некорректные размеры." << endl;
        return;
    }
    int minVal = M[0][0];
    int maxVal = M[0][0];
    int minRow = 0, minCol = 0;
    int maxRow = 0, maxCol = 0;
    // находим минимальный и максимальный элементы и их индексы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j] < minVal) {
                minVal = M[i][j];
                minRow = i;
                minCol = j;
            }
            if (M[i][j] > maxVal) {
                maxVal = M[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    if (minRow == maxRow && minCol == maxCol) {
        cout << "Минимальный и максимальный элементы совпадают или находятся в одной позиции. Перестановка не требуется." << endl;
        return;
    }
    cout << "\n--- Информация о перестановке ---" << endl;
    cout << "Минимальный элемент: " << minVal << " находится в позиции [" << minRow << "][" << minCol << "]" << endl;
    cout << "Максимальный элемент: " << maxVal << " находится в позиции [" << maxRow << "][" << maxCol << "]" << endl;
    // Выполняем перестановку
    std::swap(M[minRow][minCol], M[maxRow][maxCol]);
    cout << "Элементы успешно переставлены." << endl;
    cout << "Теперь элемент " << minVal << " (бывший минимальный) находится в позиции [" << maxRow << "][" << maxCol << "]" << endl;
    cout << "А элемент " << maxVal << " (бывший максимальный) находится в позиции [" << minRow << "][" << minCol << "]" << endl;
}
