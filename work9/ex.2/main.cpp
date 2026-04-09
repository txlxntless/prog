#include <iostream> 
#include "file.cpp"
using namespace std;

int main() {
    int n; 
    cout << "Введите размер матрицы: ";
    cin >> n; 

    // проверяем введенный размер на корректность
    if (n <= 0) {
        cout << "Размер матрицы должен быть положительным числом. Пожалуйста, запустите программу снова." << endl;
        return 1; 
    }
    // создаем и заполняем матрицу, используя нашу функцию
    int** myMatrix = createAndFillDiagonalMatrix(n);
    printMatrix(myMatrix, n);   // вывод созданной матрицы
    calculateAverageByRows(myMatrix, n); // вычисляем и выводим среднее по строкам
    countZerosByColumns(myMatrix, n);   // считаем и выводим количество нулей по столбцам
    deleteMatrix(myMatrix, n);
    myMatrix = nullptr; // обнуляем указатель после удаления
    cout << "\nПрограмма завершена." << endl;
    return 0;
}
