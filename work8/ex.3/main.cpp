#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip> // Для setw(3)
#include "file.cpp"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int n, m;
    do {
        cout << "Введите количество строк (n) и столбцов (m): ";
        cin >> n >> m;
        if (n <= 0 || m <= 0) cout << "Ошибка! Размеры > 0.\n";
    } while (n <= 0 || m <= 0);
    // используем функцию для выделения памяти
    double** M = allocateMatr(n, m);
    cout << "------Меню ввода------" << endl;
    cout << "1. Ввод с экрана\n2. Ввод из файла\n3. Случайные числа" << endl;
    int choice; cin >> choice;
    if (choice == 1) {
        cout << "Введите элементы:" << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> M[i][j];
    } 
    else if (choice == 2) {
        string filename;
        cout << "Имя файла: "; cin >> filename;
        ifstream fin(filename);
        if (!fin) {
            cout << "Файл не найден! Ввод с экрана:" << endl;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) cin >> M[i][j];
        } else {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) fin >> M[i][j];
            fin.close();
        }
    } 
    else if (choice == 3) {
        double A, B;
        cout << "Интервал [a, b]: "; cin >> A >> B;
        RandomMatr(M, n, m, A, B);
    }
    // вывод на экран (3 символа на элемент)
    cout << "\nПолученная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(3) << M[i][j] << " "; 
        }
        cout << endl;
    }
    OutFileMatr(M, n, m); 
    // освобождаем памяти
    freeMem(M, n);
    return 0;
}
