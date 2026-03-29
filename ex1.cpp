#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

//функции для работы с массивом
void inputFromScreen(int* arr, int n) { //ввод с экрана
    cout << "Введите " << n << " элементов массива:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}
void inputFromFile(int* arr, int n) { //ввод из файла (файл должен называться data.txt)
    ifstream fin("data.txt");
    if (!fin) {
        cout << "Ошибка: файл data.txt не найден! Заполняю нулями." << endl;
        for (int i = 0; i < n; i++) arr[i] = 0;
        return;
        }
    for (int i = 0; i < n; i++) {
        fin >> arr[i];
        }
    fin.close();
    cout << "Данные успешно прочитаны из файла." << endl;
}
void printArray(int* arr, int n) { //вывод на экран
    cout << "Текущий массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void saveToFile(int* arr, int n) { //запись результатов в файл
    ofstream fout("result.txt");
    for (int i = 0; i < n; i++) {
        fout << arr[i] << " ";
    }
    fout.close();
    cout << "Результат сохранен в файл result.txt" << endl;
}
// заполнение числами [-10, 10]
void fillRandomRange(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        // формула для диапазона между [min, max]: rand() % (max - min + 1) + min
        arr[i] = rand() % 21 - 10; 
    }
    cout << "Массив заполнен случайными числами от -10 до 10." << endl;
}
// задание 1: сортировка методом выбора
void selectSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_ind = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_ind]) {
                min_ind = j;
            }
        }
        // смена элементов
        int temp = arr[min_ind];
        arr[min_ind] = arr[i];
        arr[i] = temp;
    }
    cout << "Массив упорядочен методом выбора." << endl;
}
// задание 2: сортировка методом вставки
void insertSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int the = arr[i];
        int j = i - 1;
        // сдвигаем элементы, которые больше, на позицию вперед
        while (j >= 0 && arr[j] > the) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = the;
    }
    cout << "Массив упорядочен методом вставки." << endl;
}