#include <iostream> 
#include "file.cpp"
using namespace std;

int main() {
    int n;
    cout << "Введите размер подблока n (например, 2 для 4x4 матрицы): ";
    cin >> n;
    if (n <= 0) {
        cout << "Размер n должен быть положительным числом." << endl;
        return 1;
    }
    int totalMatrixSize = 2 * n; // определяем общий размер матрицы
    // заполняем матрицу по правилу
    int** myMatrix = createAndFillSpecialMatrix(n);
    printMatrix(myMatrix, totalMatrixSize); // Выводим полученную матрицу
    // вычисляем суммы по диагоналям, параллельным главной
    calculateMainDiagonalSums(myMatrix, totalMatrixSize);
    // вычисляем количество нулей по диагоналям, параллельным побочной
    countAntiDiagonalZeros(myMatrix, totalMatrixSize);
    deleteMatrix(myMatrix, totalMatrixSize);
    myMatrix = nullptr; // обнуляем указатель
    cout << "\nПрограмма завершена." << endl;
    return 0;
}
