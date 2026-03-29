#include <iostream>
#include <ctime>
#include "ex1.cpp"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0)); //для случайных чисел
    int n;
    do { //запрос размера массива с проверкой
        cout << "Введите количество элементов массива (положительное число): ";
        cin >> n;
        if (n <= 0) {
            cout << "Ошибка! Число должно быть больше нуля." << endl;
        }
    } while (n <= 0);
    int* myArray = new int[n]; //выделение памяти под динамический массив
    fillRandomRange(myArray, n);    //заполнение массива случайными числами
    printArray(myArray, n);
    cout << "\nВыберите метод сортировки:" << endl;   // выбор сортировки
    cout << "[1] Метод выбора" << endl;
    cout << "[2] Метод вставки" << endl;
    int sortChoice;
    cout <<"Ваш выбор: "; cin >> sortChoice;
    if (sortChoice == 1) {
        selectSort(myArray, n);
    } else if (sortChoice == 2) {
        insertSort(myArray, n);
    } else {
        cout << "Неверный выбор. Сортировка не выполнена." << endl;
    }
    printArray(myArray, n); //вывод полученного массива
    saveToFile(myArray, n); //запись в файл
    delete[] myArray; 
    cout << "\nПамять освобождена. Программа завершена." << endl;
    return 0;
}