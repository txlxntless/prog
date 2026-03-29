#include <iostream>
#include "file.cpp"
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    // пункт a: обратный порядок
    runAllTests("таблица 1 (обратный порядок: n...1)", true);
    // пункт c: случайные числа
    runAllTests("таблица 2 (случайные числа [-10, 10])", false);
    return 0;
}
