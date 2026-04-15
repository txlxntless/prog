#include <iostream>
#include <fstream>
#include <ctime>
#include "file.cpp"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int n, m;
    cout << "Введите количество строк (n) и столбцов (m): ";
    cin >> n >> m;
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
    // вывод матрицы
    cout << "\nМатрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << M[i][j] << "\t";
        cout << endl;
    }
    // задание
    int maxNeg, minPos;
    int maxNegR, maxNegC, minPosR, minPosC;
    bool foundNeg = false, foundPos = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // поиск макс. отрицательного
            if (M[i][j] < 0) {
                if (!foundNeg || M[i][j] > maxNeg) {
                    maxNeg = M[i][j];
                    maxNegR = i; maxNegC = j;
                    foundNeg = true;
                }
            }
            // поиск мин. положительного
            if (M[i][j] > 0) {
                if (!foundPos || M[i][j] < minPos) {
                    minPos = M[i][j];
                    minPosR = i; minPosC = j;
                    foundPos = true;
                }
            }
        }
    }
    cout << "\nРезультаты поиска:" << endl;
    if (foundNeg)
        cout << "Макс. отрицательный: " << maxNeg << " в позиции [" << maxNegR << "][" << maxNegC << "]" << endl;
    else
        cout << "Отрицательных элементов не найдено." << endl;

    if (foundPos)
        cout << "Мин. положительный: " << minPos << " в позиции [" << minPosR << "][" << minPosC << "]" << endl;
    else
        cout << "Положительных элементов не найдено." << endl;
    // вывод элементов главной диагонали
    cout << "\nЭлементы главной диагонали: ";
    for (int i = 0; i < n; i++) {
        cout << M[i][i] << " ";
    }
    cout << endl;
    OutFileMatr(M, n, m);
    for (int i = 0; i < n; i++) delete[] M[i];
    delete[] M;
    return 0;
}
