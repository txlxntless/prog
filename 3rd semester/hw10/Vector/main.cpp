#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "1. Тип int" << endl;
    Vector<int> vInt1, vInt2;
    vInt1.push_back(1); vInt1.push_back(2); vInt1.push_back(3);
    vInt2.push_back(4); vInt2.push_back(5); vInt2.push_back(6);

    cout << "v1: " << vInt1 << "\nv2: " << vInt2 << endl;
    cout << "v1 + v2 = " << (vInt1 + vInt2) << endl;
    cout << "v1 - v2 = " << (vInt1 - vInt2) << endl;
    cout << "v1 * v2 (скалярно) = " << (vInt1 * vInt2) << endl;
    cout << "front: " << vInt1.front() << ", back: " << vInt1.back() << ", at(1): " << vInt1.at(1) << "\n\n";

    cout << "2. Тип double" << endl;
    Vector<double> vDouble1, vDouble2;
    vDouble1.push_back(1.5); vDouble1.push_back(2.5);
    vDouble2.push_back(2.0); vDouble2.push_back(4.0);

    cout << "v1: " << vDouble1 << "\nv2: " << vDouble2 << endl;
    cout << "v1 + v2 = " << (vDouble1 + vDouble2) << endl;
    cout << "v1 * v2 = " << (vDouble1 * vDouble2) << "\n\n";

    cout << "3. Тип char" << endl;
    Vector<char> vChar1, vChar2;
    vChar1.push_back('A'); vChar1.push_back('B');
    vChar2.push_back(1);   vChar2.push_back(2);

    cout << "v1: " << vChar1 << endl;
    cout << "v1 + {1, 2} = " << (vChar1 + vChar2) << endl;
    cout << "vChar1 = " << vChar1 << "\n\n";

    cout << "4. Тип string (Специализация)" << endl;
    Vector<string> vStr1, vStr2;
    vStr1.push_back("Hello World"); vStr1.push_back("Good Morning");
    vStr2.push_back("World");       vStr2.push_back("Day");

    cout << "v1: " << vStr1 << "\nv2: " << vStr2 << endl;
    cout << "v1 + v2 = " << (vStr1 + vStr2) << endl;
    cout << "v1 - v2 = " << (vStr1 - vStr2) << endl;
    cout << "v1 * v2 = " << (vStr1 * vStr2) << "\n\n";

    cout << "5. Ввод вектора с клавиатуры" << endl;
    Vector<int> vInput;
    cin >> vInput;
    cout << "Вы ввели: " << vInput << endl;

    return 0;
}
