#ifndef FRUIT_H
#define FRUIT_H

#include <string>

// Базовый абстрактный класс
class Fruit {
protected:
    std::string name;
    double weight; // Вес в граммах
    static int objectCount; // Поле для подсчета объектов
public:
    Fruit(const std::string& name, double weight);
    virtual ~Fruit();

    // Два полиморфных метода
    virtual void showInfo() const = 0;
    virtual void peel() const = 0;

    // Метод для получения количества объектов
    static int getObjectCount();
};

// Класс-потомок: Яблоко
class Apple : public Fruit {
private:
    std::string variety; // Сорт
public:
    Apple(const std::string& name, double weight, const std::string& variety);

    void showInfo() const override;
    void peel() const override;
};

// Класс-потомок: Цитрус
class Citrus : public Fruit {
private:
    int segmentsCount; // Количество долек
    bool hasSeeds; // Наличие косточек
public:
    Citrus(const std::string& name, double weight, int segmentsCount, bool hasSeeds);

    void showInfo() const override;
    void peel() const override;
};

#endif
