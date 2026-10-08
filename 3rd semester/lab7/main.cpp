#include <iostream>
#include "figures.cpp"

using namespace std;

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    cout << "*** Программа выбора фигур (через позднее связывание)" << endl;
    cout << "1. Создать Круг" << endl;
    cout << "2. Создать Прямоугольник" << endl;
    cout << "3. Создать Шестиугольник (Гексагон)" << endl; // Добавили меню
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;
    cout << endl;

    Figure* myFigure = nullptr;

    switch (choice) {
        case 1: {
            double r;
            cout << "Введите радиус круга: ";
            cin >> r;
            myFigure = new Circle(r);
            break;
        }
        case 2: {
            double w, h;
            cout << "Введите ширину и высоту прямоугольника: ";
            cin >> w >> h;
            myFigure = new Rectangle(w, h);
            break;
        }
        case 3: { 
            double s;
            cout << "Введите длину стороны правильного шестиугольника: ";
            cin >> s;
            myFigure = new Hexagon(s); 
            break;
        }
        default:
            cout << "Неверный выбор! Программа завершена." << endl;
            return 0;
    }

    cout << "\n*** Вывод информации об объекте через полиморфные методы" << endl;
    myFigure->PrintInfo(); 

    cout << "\n*** Удаление объекта из памяти" << endl;
    delete myFigure; 

    return 0;
}
