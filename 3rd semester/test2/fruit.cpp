#include "fruit.h"
#include <iostream>
using namespace std;

// Инициализация статического поля
int Fruit::objectCount = 0;

// Реализация базового класса
Fruit::Fruit(const string& name, double weight) : name(name), weight(weight) {
    objectCount++;
}

Fruit::~Fruit() {
    objectCount--;
}

int Fruit::getObjectCount() {
    return objectCount;
}

// Реализация класса Apple
Apple::Apple(const string& name, double weight, const string& variety) : Fruit(name, weight), variety(variety) {}

void Apple::showInfo() const {
    cout << "[Яблоко] Название: " << name << ", Вес: " << weight << " г" << ", Сорт: " << variety << endl;
}

void Apple::peel() const {
    cout << name << ": тонкую кожуру можно срезать ножом или съесть плод вместе с ней." << endl;
}

// Реализация класса Citrus

Citrus::Citrus(const string& name, double weight, int segmentsCount, bool hasSeeds) : Fruit(name, weight), segmentsCount(segmentsCount), hasSeeds(hasSeeds) {}

void Citrus::showInfo() const {
    cout << "[Цитрус] Название: " << name << ", Вес: " << weight << " г" << ", Колиечество долек: " << segmentsCount << " шт" << ", Наличие косточек: " << (hasSeeds ? "Да" : "Нет") << endl;
}

void Citrus::peel() const {
    cout << name << ": ароматная цедра легко очищается руками." << endl;
}
