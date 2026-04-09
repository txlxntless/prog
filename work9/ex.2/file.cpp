#include <iostream> 
using namespace std;

void printMatrix(int** matrix, int n) {
    // проверка, что матрица не пустая
    if (n <= 0) {
        cout << "Матрица пуста или имеет некорректный размер." << endl;
        return;
    }

    cout << "Матрица " << n << "x" << n << ":" << endl;
    // проход по каждой строке
    for (int i = 0; i < n; i++) {
        // проход по каждому элементу в строке
        for (int j = 0; j < n; j++) {
            // вывод элементов и табуляции для разделения
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// освобождение памяти, которую мы выделили для матрицы
void deleteMatrix(int** matrix, int n) {
    // проверка, что матрица вообще существует
    if (matrix == nullptr || n <= 0) {
        return; // если нет, то и удалять нечего
    }

    // удаляем каждую строку матрицы по очереди
    for (int i = 0; i < n; i++) {
        delete[] matrix[i]; // удаляем массив чисел в этой строке
    }
    // удаляем сам массив указателей на строки
    delete[] matrix;
    matrix = nullptr; // обнуляем указатель, чтобы не использовать его
}
// 1. функция создания и заполнения квадратной матрицы порядка n
// матрица будет диагональной: A[i][i] = i+1, остальные элементы = 0
int** createAndFillDiagonalMatrix(int n) {
    // сначала выделяем память для "столбца" указателей на строки
    int** matrix = new int*[n];
    // для каждой строки выделяем память под n целых чисел
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    // заполняем матрицу по правилам
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            if (i == j) { // если это элемент на главной диагонали
                matrix[i][j] = i + 1; 
            } else { // это не на главной диагонали
                matrix[i][j] = 0; 
            }
        }
    }
    return matrix; // возвращаем матрицу
}
// функция вычисления среднего арифметического по каждой строке
void calculateAverageByRows(int** matrix, int n) {
    if (n <= 0) {
        std::cout << "Невозможно вычислить среднее для пустой матрицы." << endl;
        return;
    }

    cout << "\n--- Вычисление среднего арифметического по строкам" << endl;
    for (int i = 0; i < n; i++) { // проход по каждой строке
        long long sum = 0; 
        for (int j = 0; j < n; j++) { // проход по элементам текущей строки
            sum += matrix[i][j]; 
        }
        double average = (double)sum / n;
        cout << "Среднее для строки " << (i + 1) << ": " << average << endl;
    }
}
// функция подсчета количества нулей в каждом столбце
void countZerosByColumns(int** matrix, int n) {
    if (n <= 0) {
        cout << "Невозможно посчитать нули для пустой матрицы." << endl;
        return;
    }
    cout << "\n--- Подсчет нулей по столбцам" << endl;
    for (int j = 0; j < n; j++) { 
        int zeroCount = 0; // сбрасываем счетчик нулей для нового столбца
        for (int i = 0; i < n; i++) { 
            if (matrix[i][j] == 0) { 
                zeroCount++; 
            }
        }
        cout << "Количество нулей в столбце " << (j + 1) << ": " << zeroCount << endl;
    }
}
