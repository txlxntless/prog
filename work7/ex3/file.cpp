#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

// счетчики
long long C = 0; // сравнения
long long M = 0; // перестановки
// функции заполнения
// n, n-1, ..., 1 (Худший случай)
void fillReverse(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = n - i;
    }
}
// случайные числа от -10 до 10
void fillRandom(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 21 - 10;
    }
}
// алгоритмы сортировки
void bubbleSort(int A[], int n) {
    C = 0; M = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            C++; 
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                M += 3; 
            }
        }
    }
}
void selectSort(int A[], int n) {
    C = 0; M = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            C++;
            if (A[j] < A[min_idx]) min_idx = j;
        }
        int temp = A[min_idx];
        A[min_idx] = A[i];
        A[i] = temp;
        M += 3; 
    }
}
void insertSort(int A[], int n) {
    C = 0; M = 0;
    for (int i = 1; i < n; i++) {
        int temp = A[i]; M++;
        int j = i - 1;
        while (j >= 0) {
            C++;
            if (A[j] > temp) {
                A[j + 1] = A[j]; M++;
                j--;
            } else break;
        }
        A[j + 1] = temp; M++;
    }
}
// метод Шелла
void shellSort(int A[], int n) {
    C = 0; M = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = A[i]; M++;
            int j;
            for (j = i; j >= gap; j -= gap) {
                C++;
                if (A[j - gap] > temp) {
                    A[j] = A[j - gap]; M++;
                } else break;
            }
            A[j] = temp; M++;
        }
    }
}
// проверка работоспособности
void runAllTests(const char* title, bool isReverse) {
    int sizes[] = {10, 100, 1000};
    cout << "\n=== " << title << " ===\n";
    cout << "метод\t\t n\t сравнения(C)\t перестановки(M)\n";
    cout << "--------------------------------------------------------\n";
    for (int n : sizes) {
        int* data = new int[n];
        if (isReverse) fillReverse(data, n); else fillRandom(data, n);  // Пузырек
        bubbleSort(data, n);
        cout << "пузырек\t\t " << n << "\t " << C << "\t\t " << M << endl;
        if (isReverse) fillReverse(data, n); else fillRandom(data, n);  // Выбор
        selectSort(data, n);
        cout << "выбор\t\t " << n << "\t " << C << "\t\t " << M << endl;
        if (isReverse) fillReverse(data, n); else fillRandom(data, n);  // Вставка
        insertSort(data, n);
        cout << "вставка\t\t " << n << "\t " << C << "\t\t " << M << endl;
        if (isReverse) fillReverse(data, n); else fillRandom(data, n);  // Шелл
        shellSort(data, n);
        cout << "Шелл\t\t " << n << "\t " << C << "\t\t " << M << endl;
        delete[] data;
    }
}
