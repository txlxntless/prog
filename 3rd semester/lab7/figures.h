#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>

// Базовый класс
class Figure {
protected:
    std::string* name; 

public:
    Figure(const std::string& figName);
    virtual ~Figure(); // Виртуальный деструктор естественно

    std::string GetName() const;

    // Виртуальная функция (класс будет абстрактным, т.к. площади считаются по-разному)
    virtual double CalcArea() const = 0; 
    
    // Полиморфный метод для вывода инфо
    virtual void PrintInfo() const;
};

// Наследник: Круг
class Circle : public Figure {
private:
    double* radius; 

public:
    Circle(double r);
    ~Circle() override;

    double CalcArea() const override;
    void PrintInfo() const override;
};

// Наследник: Прямоугольник
class Rectangle : public Figure {
private:
    double* width;  
    double* height;

public:
    Rectangle(double w, double h);
    ~Rectangle() override;

    double CalcArea() const override;
    void PrintInfo() const override;
};

// Домашнее задание 
class Hexagon : public Figure {
private:
    double* side;

public:
    Hexagon(double s);
    ~Hexagon() override;

    double CalcArea() const override;
    void PrintInfo() const override;
};

#endif
