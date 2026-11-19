#include <iostream>
#include "fruit.h"
using namespace std;

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    cout << "Начальное количество объектов: " << Fruit::getObjectCount() << "\n\n";

    // Создаем по одному объекту каждого неабстрактного класса
    cout << "Демонстрация раннего связывания" << endl;
    Apple greenApple("Зеленое яблоко", 180.5, "Гренни");
    Citrus orange("Мандарин", 220.0, 9, false);

    // Работа методов для яблока
    greenApple.showInfo();
    greenApple.peel();

    // Работа методов для цитруса
    orange.showInfo();
    orange.peel();

    cout << "\nТекущее количество объектов: " << Fruit::getObjectCount() << "\n\n";

    // Тип объекта выбирает пользователь во время работы программы
    cout << "Демонстрация позднего связывания" << endl;
    Fruit* dynamicFruit = nullptr;
    int choice;

    cout << "Выберите фрукт для создания:\n1 - Яблоко\n2 - Цитрус\nВаш выбор: ";
    cin >> choice;

    if (choice == 1) {
        dynamicFruit = new Apple("Красное яблоко", 165.0, "Фуджи");
    } else {
        dynamicFruit = new Citrus("Лимон", 110.0, 12, true);
    }

    cout << "\nВызов полиморфных методов через указатель базового класса:" << endl;
    dynamicFruit->showInfo();
    dynamicFruit->peel();

    cout << "\nВсего активных объектов в программе: " << Fruit::getObjectCount() << endl;

    delete dynamicFruit;
    cout << "Количество объектов после удаления динамического объекта: " << Fruit::getObjectCount() << endl;

    return 0;
}
