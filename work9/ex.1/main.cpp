#include <iostream> 
#include <vector>   // будем использовать вектор для хранения номеров (столбцов/строк)
#include "file.cpp"
using namespace std;

int main() {
    int n;
    cout << "Введите размер квадратной матрицы n: ";
    cin >> n;
    if (n <= 0) {
        cout << "Размер матрицы должен быть положительным числом." << endl;
        return 1; 
    }
    // A1 
    cout << "\n--- Матрица A1 " << endl;
    int** A1 = fillMatrixA1(n); // функция для заполнения
    printMatrix(A1, n); // печать матрицы
    int krowA1;
    cout << "Введите номер строки k для A1 (начиная с 1): ";
    cin >> krowA1;
    if (krowA1 >= 1 && krowA1 <= n) {
        double avgA1 = calculateAverageOfKthRowA1(A1, n, krowA1);
        cout << "Среднее арифметическое " << krowA1 << "-ой строки в A1: " << avgA1 << endl;
    } else {
        cout << "Неверный номер строки. Пожалуйста, введите число от 1 до " << n << endl;
    }
    deleteMatrix(A1, n);
    // A2
    cout << "\n--- Матрица A2" << endl;
    int** A2 = fillMatrixA2(n);
    printMatrix(A2, n);
    int kcolA2;
    cout << "Введите номер столбца k для A2 (начиная с 1): ";
    cin >> kcolA2;
    if (kcolA2 >= 1 && kcolA2 <= n) {
        int zerocountA2 = countZerosInKthColumnA2(A2, n, kcolA2);
        cout << "Количество нулей в " << kcolA2 << "-ом столбце A2: " << zerocountA2 << endl;
    } else {
        cout << "Неверный номер столбца. Пожалуйста, введите число от 1 до " << n << endl;
    }
    deleteMatrix(A2, n); 
    // A3
    cout << "\n--- Матрица A3" << endl;
    int** A3 = fillMatrixA3(n);
    printMatrix(A3, n);
    vector<int> positivecolsA3 = findPositiveColumnsA3(A3, n);
    cout << "Номера столбцов в A3, где все элементы положительные: ";
    if (positivecolsA3.empty()) { // проверяем, не пуст ли вектор
        cout << "Таких столбцов нет.";
    } else {
        for (size_t i = 0; i < positivecolsA3.size(); i++) { // проход по вектору
            cout << positivecolsA3[i] << " ";
        }
    }
    cout << endl;
    deleteMatrix(A3, n);
    // A4 
    cout << "\n--- Матрица A4" << endl;
    int** A4 = fillMatrixA4(n);
    printMatrix(A4, n);
    vector<int> specialrowsA4 = findSpecialRowsA4(A4, n);
    cout << "Номера строк в A4, где все элементы кратны трем и не равны нулю: ";
    if (specialrowsA4.empty()) {
        cout << "Таких строк нет.";
    } else {
        for (size_t i = 0; i < specialrowsA4.size(); i++) {
            cout << specialrowsA4[i] << " ";
        }
    }
    cout << std::endl;
    deleteMatrix(A4, n);
    return 0;
}
