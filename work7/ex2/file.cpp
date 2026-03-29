#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

long long C = 0; // сравнения
long long M = 0; // перестановки
// заполнение массива в порядке: n, n-1, ..., 1 
void fillReverse(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = n - i;
    }
}
// заполнение случайными числами [-10, 10]
void fillRandom(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 21 - 10;
    }
}
// пузырек
void bubbleSort(int A[], int n) {
    C = 0; M = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            C++; 
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                M += 3; // обмен через третью переменную = 3 действия по формуле
            }
        }
    }
}
// выбор
void selectSort(int A[], int n) {
    C = 0; M = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            C++;
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        // обмен найденного минимума с текущим элементом
        int temp = A[min_idx];
        A[min_idx] = A[i];
        A[i] = temp;
        M += 3; 
    }
}
// вставка
void insertSort(int A[], int n) {
    C = 0; M = 0;
    for (int i = 1; i < n; i++) {
        int temp = A[i]; 
        M++; // берем элемент
        int j = i - 1;
        while (j >= 0) {
            C++; // сравнение в условии цикла
            if (A[j] > temp) {
                A[j + 1] = A[j];
                M++; // сдвиг элемента
                j--;
            } else {
                break;
            }
        }
        A[j + 1] = temp;
        M++; // поставили на место
    }
}
