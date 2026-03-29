#include <iostream>
#include <ctime>
#include "1.cpp"
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int sizes[] = {10, 100, 1000};
    // проверка пузырька
    cout << "Метод пузырька (худший случай)" << endl;
    for (int n : sizes) {
        int* A = new int[n];
        fillReverse(A, n);
        bubbleSort(A, n);
        long long theoryC = (n * n - n) / 2;
        long long theoryM = 1.5 * (n * n - n);
        cout << "n=" << n << "\t Факт: C=" << C << ", M=" << M 
             << "\t Теор: C=" << theoryC << ", M=" << theoryM << endl;
        delete[] A;
    }
    // проверка выборки
    cout << "\nМетод выбора (худший случай)" << endl;
    for (int n : sizes) {
        int* A = new int[n];
        fillReverse(A, n);
        selectSort(A, n);
        long long theoryC = (n * n - n) / 2;
        long long theoryM = 3 * (n - 1); // упрощенная теория для выбора
        cout << "n=" << n << "\t Факт: C=" << C << ", M=" << M 
             << "\t Теор: C=" << theoryC << ", M=" << theoryM << endl;
        delete[] A;
    }
    // проверка вставки
    cout << "\nМетод вставки (худший случай)" << endl;
    for (int n : sizes) {
        int* A = new int[n];
        fillReverse(A, n);
        insertSort(A, n);
        // формулы по заданию
        long long theoryC = (n * n + n - 4) / 4;
        long long theoryM = (n * n + 3 * n - 4) / 2;
cout << "n=" << n << "\t Факт: C=" << C << ", M=" << M 
             << "\t Теор: C=" << theoryC << ", M=" << theoryM << endl;
        delete[] A;
    }

    // проверка случайных чисел
    cout << "\nСлучайные числа на примере пузырька" << endl;
    for (int n : sizes) {
        int* A = new int[n];
        fillRandom(A, n);
        bubbleSort(A, n);
        cout << "n=" << n << "\t Сравнений: " << C << "\t Перестановок: " << M << endl;
        delete[] A;
    }
    return 0;
}
