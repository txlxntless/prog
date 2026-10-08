#include "figures.h"
#include <cmath>

// ==================== Базовый класс Figure ====================
Figure::Figure(const std::string& figName) {
    std::cout << "Вызов конструктора Figure для " << figName << std::endl;
    name = new std::string(figName);
}

Figure::~Figure() {
    std::cout << "Вызов деструктора Figure для " << *name << " (Освобождение памяти)" << std::endl;
    delete name;
}

std::string Figure::GetName() const { return *name; }

void Figure::PrintInfo() const {
    std::cout << "Фигура: " << *name << std::endl;
}

// Класс Circle 
Circle::Circle(double r) : Figure("Круг") {
    std::cout << "Вызов конструктора Circle с радиусом " << r << std::endl;
    radius = new double(r);
}

Circle::~Circle() {
    std::cout << "Вызов деструктора Circle" << std::endl;
    delete radius;
}

double Circle::CalcArea() const {
    std::cout << "Вызов CalcArea() для Круга" << std::endl;
    return 3.1415926535 * (*radius) * (*radius);
}

void Circle::PrintInfo() const {
    Figure::PrintInfo();
    std::cout << "-> Радиус: " << *radius << ", Площадь: " << CalcArea() << std::endl;
}

// Класс Rectangle 
Rectangle::Rectangle(double w, double h) : Figure("Прямоугольник") {
    std::cout << "Вызов конструктора Rectangle со сторонами " << w << "x" << h << std::endl;
    width = new double(w);
    height = new double(h);
}

Rectangle::~Rectangle() {
    std::cout << "Вызов деструктора Rectangle" << std::endl;
    delete width;
    delete height;
}

double Rectangle::CalcArea() const {
    std::cout << "Вызов CalcArea() для Прямоугольника" << std::endl;
    return (*width) * (*height);
}

void Rectangle::PrintInfo() const {
    Figure::PrintInfo();
    std::cout << "-> Ширина: " << *width << ", Высота: " << *height << ", Площадь: " << CalcArea() << std::endl;
}

// Класс Hexagon 
Hexagon::Hexagon(double s) : Figure("Шестиугольник") {
    std::cout << "Вызов конструктора Hexagon со стороной " << s << std::endl;
    side = new double(s);
}

Hexagon::~Hexagon() {
    std::cout << "Вызов деструктора Hexagon (Освобождение памяти)" << std::endl;
    delete side;
}

double Hexagon::CalcArea() const {
    std::cout << "Вызов CalcArea() для Шестиугольника" << std::endl;
    // Формула площади правильного шестиугольника: (3 * sqrt(3) / 2) * side^2
    return (3.0 * std::sqrt(3.0) / 2.0) * (*side) * (*side);
}

void Hexagon::PrintInfo() const {
    Figure::PrintInfo();
    std::cout << "-> Сторона: " << *side << ", Площадь: " << CalcArea() << std::endl;
}
