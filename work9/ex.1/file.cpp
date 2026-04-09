#include <iostream>
#include <vector> 
using namespace std;

// печать матрицы
void printMatrix(int** matrix, int n) {
    if (n <= 0) {
        cout << "Матрица пуста или некорректного размера." << endl;
        return;
    }
    cout << "Матрица размера " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++) { // проход по строкам
        for (int j = 0; j < n; j++) { // проход по столбцам
            cout << matrix[i][j] << "\t"; // табуляция для разделения
        }
        cout << endl; // новая строка после каждой строки матрицы
    }
    cout << endl; // + пустая строка для отделения матриц
}

// освобождение памяти, выделенной под матрицу
void deleteMatrix(int** matrix, int n) {
    if (matrix == nullptr || n <= 0) {
        return; // нечего удалять, если матрица не существует или некорректна
    }
    for (int i = 0; i < n; i++) {
        delete[] matrix[i]; // удаляем каждую строку
    }
    delete[] matrix; // удаляем массив указателей на строки
}

// заполнение матрицы A1
int** fillMatrixA1(int n) {
    // выделяем память
    int** A1 = new int*[n]; // создаем массив указателей на строки
    for (int i = 0; i < n; i++) {
        A1[i] = new int[n]; // для каждой строки создаем массив int
    }
    // если n=0, просто вернем пустой массив
    if (n == 0) return A1;
    // заполнение матрицы A1 по правилу
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) { // первая строка
                A1[i][j] = 1;
            } else if (i == n - 1) { // последняя строка
                A1[i][j] = n;
            } else if (j == 0) { // первый столбец (кроме первой и последней строк)
                A1[i][j] = i + 1;
            } else if (j == n - 1) { // последний столбец (кроме первой и последней строк)
                A1[i][j] = i + 1;
            } else { // остальные элементы
                A1[i][j] = 0;
            }
        }
    }
    return A1;
}

// заполнение A2
int** fillMatrixA2(int n) {
    int** A2 = new int*[n];
    for (int i = 0; i < n; i++) {
        A2[i] = new int[n];
    }
    if (n == 0) return A2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // элементы на границе (первая/последняя строка, первый/последний столбец) равны 1
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                A2[i][j] = 1;
            } else {
                A2[i][j] = 0; // остальные элементы равны 0
            }
        }
    }
    return A2;
}

// заполнение A3
int** fillMatrixA3(int n) {
    int** A3 = new int*[n];
    for (int i = 0; i < n; i++) {
        A3[i] = new int[n];
    }
    if (n == 0) return A3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) { // первый столбец
                A3[i][j] = 1;
            } else if (j == n - 1) { // последний столбец
                A3[i][j] = -1;
            } else { // внутренние столбцы
                A3[i][j] = 0;
            }
        }
    }
    return A3;
}

// заполнение A4
int** fillMatrixA4(int n) {
    int** A4 = new int*[n];
    for (int i = 0; i < n; i++) {
        A4[i] = new int[n];
    }
    if (n == 0) return A4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) { // первая строка
                A4[i][j] = 3;
            } else if (i == n - 1) { // последняя строка
                A4[i][j] = 3 * n;
            } else { // остальные строки
                A4[i][j] = 0;
            }
        }
    }
    return A4;
}

// 2 задание Для матрицы A1 вычислить среднее арифметическое чисел из k-ой строки.
double calculateAverageOfKthRowA1(int** A1, int n, int krowidx) {
    if (krowidx < 1 || krowidx > n || n == 0) {
        cout << "Ошибка: Неверный номер строки для A1." << endl;
        return 0.0;
    }
    long long sum = 0; 
    // krowidx - 1, потому что индексы в C++ начинаются с 0
    for (int j = 0; j < n; j++) {
        sum += A1[krowidx - 1][j];
    }
    return (double)sum / n; // делим на n, чтобы получить среднее
}

// задание 3 Для матрицы A2 вычислить количество нулей в k-ом столбце.
int countZerosInKthColumnA2(int** A2, int n, int kcolidx) {
    if (kcolidx < 1 || kcolidx > n || n == 0) {
        cout << "Ошибка: Неверный номер столбца для A2." << endl;
        return 0;
    }
    int zeroCount = 0;
    for (int i = 0; i < n; i++) {
        if (A2[i][kcolidx - 1] == 0) {
            zeroCount++;
        }
    }
    return zeroCount;
}

// 4. Для матрицы A3 выводить номера столбцов, в которых все элементы положительные.
// для возврата нескольких значений будем использовать вектор
vector<int> findPositiveColumnsA3(int** A3, int n) {
    vector<int> positiveColumns; // вектор для хранения номеров столбцов
    if (n == 0) return positiveColumns;
    for (int j = 0; j < n; j++) { // проход по каждому столбцу
        bool allPositive = true; // думаем, что столбец положительный
        for (int i = 0; i < n; i++) { // проверка все ли элементы в текущем столбце
            if (A3[i][j] <= 0) { // если нет, этот столбец не подходит
                allPositive = false;
                break; // нет смысла проверять дальше, переходим к следующему столбцу
            }
        }
        if (allPositive) {
            positiveColumns.push_back(j + 1); // добавляем номер столбца 
        }
    }
    return positiveColumns;
}

// 5. Для матрицы A4 выводить номера строк, в которых все элементы кратны трем и не равны нулю.
vector<int> findSpecialRowsA4(int** A4, int n) {
    vector<int> specialRows;
    if (n == 0) return specialRows;
    for (int i = 0; i < n; i++) { // проход по каждой строке
        bool allMatch = true; // предполагаем, что строка подходит
        for (int j = 0; j < n; j++) { // проверяем все элементы в текущей строке
            // если элемент равен нулю или не кратен трем
            if (A4[i][j] == 0 || A4[i][j] % 3 != 0) {
                allMatch = false; // то строка не подходит
                break; // и нет смысла проверять дальше, переходим к следующей строке
            }
        }
        if (allMatch) {
            specialRows.push_back(i + 1); // Добавляем номер строки 
        }
    }
    return specialRows;
}
