#include <iostream> 
using namespace std;

// функция печати матрицы
void printMatrix(int** matrix, int size) {
    if (size <= 0) {
        cout << "Матрица пуста или некорректного размера." << endl;
        return;
    }
    cout << "Матрица размера " << size << "x" << size << ":" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout.width(3);      // чтобы столбцы были ровными
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void deleteMatrix(int** matrix, int size) {
    if (matrix == nullptr || size <= 0) {
        return;
    }
    for (int i = 0; i < size; i++) {
        delete[] matrix[i]; // удаляем каждую строку
    }
    delete[] matrix; // удаляем массив указателей на строки
    matrix = nullptr; // обнуляем указатель
}
// функция создания и заполнения матрицы
// n - размер подблоков, матрица будет (2n)x(2n)
int** createAndFillSpecialMatrix(int n) {
    int totalSize = 2 * n; // общий размер большой матрицы
    // выделяем память
    int** matrix = new int*[totalSize];
    for (int i = 0; i < totalSize; i++) {
        matrix[i] = new int[totalSize];
    }
    // заполняем матрицу нулями по умолчанию
    for (int i = 0; i < totalSize; i++) {
        for (int j = 0; j < totalSize; j++) {
            matrix[i][j] = 0;
        }
    }
    // заполняем ненулевые элементы по правилам для каждого блока
    for (int i = 0; i < totalSize; i++) {
        for (int j = 0; j < totalSize; j++) {
            // верхний левый блок (0 <= i < n, 0 <= j < n)
            if (i < n && j < n) {
                if (i == j) { // главная диагональ этого блока
                    matrix[i][j] = 1;
                }
            }
            // верхний правый блок (0 <= i < n, n <= j < 2n)
            else if (i < n && j >= n) {
                // j_block = j - n
                // побочная диагональ в n x n блоке
                if (i + (j - n) == n - 1) {
                    matrix[i][j] = 2;
                }
            }
            // нижний левый блок (n <= i < 2n, 0 <= j < n)
            else if (i >= n && j < n) {
                // главная диагональ в блоке
                if ((i - n) == j) {
                    matrix[i][j] = 3;
                }
            }
            // нижний правый блок (n <= i < 2n, n <= j < 2n)
            else if (i >= n && j >= n) {
                // iblock = i - n, jblock = j - n
                // побочная диагональ в n x n блоке: iblock + jblock == n - 1 вроде
                if ((i - n) + (j - n) == n - 1) {
                    matrix[i][j] = 4;
                }
            }
        }
    }
    return matrix; // возвращаем заполненную матрицу пожалуйста
}
// 1. найти суммы элементов по диагоналям, параллельным главной диагонали
void calculateMainDiagonalSums(int** matrix, int size) {
    if (size <= 0) {
        cout << "Матрица пуста, суммы не вычислить." << endl;
        return;
    }
    int numDiagonals = 2 * size - 1;
    long long* diagonalSums = new long long[numDiagonals]; // массив хранения сумм
    for (int k = 0; k < numDiagonals; k++) {
        diagonalSums[k] = 0;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int diagonalIndex = (j - i) + (size - 1);
            diagonalSums[diagonalIndex] += matrix[i][j];
        }
    }
    cout << "\n--- Суммы по диагоналям, параллельным главной" << endl;
    for (int k = 0; k < numDiagonals; k++) {
        cout << "Диагональ с 'смещением' " << (k - (size - 1)) << ": " << diagonalSums[k] << endl;
    }
    delete[] diagonalSums;
}
// 2. Вычислить количество нулевых элементов по диагоналям, параллельным побочной диагонали
void countAntiDiagonalZeros(int** matrix, int size) {
    if (size <= 0) {
        cout << "Матрица пуста, количество нулей не подсчитать." << endl;
        return;
    }
    int numDiagonals = 2 * size - 1;
    int* zeroCounts = new int[numDiagonals]; // массив для хранения количества нулей
    // инициализируем счетчики нулями
    for (int k = 0; k < numDiagonals; k++) {
        zeroCounts[k] = 0;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 0) {
                int diagonalIndex = i + j;
                zeroCounts[diagonalIndex]++;
            }
        }
    }
    cout << "\n--- Количество нулевых элементов по диагоналям, параллельным побочной" << endl;
    for (int k = 0; k < numDiagonals; k++) {
        cout << "Диагональ с суммой индексов " << k << ": " << zeroCounts[k] << " нулей" << endl;
    }
    delete[] zeroCounts;
}
