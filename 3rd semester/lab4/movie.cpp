#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

// Метод проверки «плохих» значений и инициализации
bool Movie::Init(const char* newTitle, int newYear, double newRating, bool status) {
    cout << "Вызван метод Init" << endl;
    // Проверяка
    if (strlen(newTitle) == 0 || newYear < 1895 || newRating < 0.0 || newRating > 10.0) {
        cout << "Проблема-проблема!! Переданы некорректные данные!" << endl;
        return false; // Естественно с ошибкой
    }

    // Если все ок, просто выделяем память и записываем
    title = new char[strlen(newTitle) + 1];
    strcpy(title, newTitle);
    year = new int(newYear);
    rating = new double(newRating);
    is3D = new bool(status);
    return true; // Успешно
}

// Конструктор по умолчанию
Movie::Movie() {
    cout << "[Конструктор] Создание объекта по умолчанию" << endl;
    // Просто вызываем Init с безопасными стартовыми значениями
    Init("Без названия", 2000, 0.0, false);
}

// Конструктор с параметрами
Movie::Movie(const char* newTitle, int newYear, double newRating, bool status) {
    cout << "[Конструктор] Создание с параметрами" << endl;
    // Инициализируем тем, что пришло
    bool success = Init(newTitle, newYear, newRating, status);
    // Обеспечиваем невозможность создания некорректного объекта
    if (success == false) {
        cout << "Проблема-проблема!! Данные плохие. Создаем безопасный объект!" << endl;
        Init("Ошибка инициализации", 2000, 0.0, false);
    }
}

// Деструктор
Movie::~Movie() {
    cout << "[Деструктор] Освобождение динамической памяти объекта" << endl;
    delete[] title;
    delete year;
    delete rating;
    delete is3D;
}

// Сеттеры (теперь вызывают Init для изменения полей)
bool Movie::SetTitle(const char* newTitle) {
    cout << "Применен SetTitle -> \"" << newTitle << "\"" << endl;
    delete[] title; 
    return Init(newTitle, *year, *rating, *is3D);
}

bool Movie::SetYear(int newYear) {
    cout << "Применен SetYear -> " << newYear << endl;
    delete year;
    return Init(title, newYear, *rating, *is3D);
}

bool Movie::SetRating(double newRating) {
    cout << "Применен SetRating -> " << newRating << endl;
    delete rating;
    return Init(title, *year, newRating, *is3D);
}

bool Movie::SetIs3D(bool status) {
    cout << "Применен SetIs3D -> " << (status ? "Да" : "Нет") << endl;
    delete is3D;
    return Init(title, *year, *rating, status);
}

// Геттеры 
const char* Movie::GetTitle() {
    cout << "Применен GetTitle" << endl;
    return title;
}
int Movie::GetYear() {
    cout << "Применен GetYear" << endl;
    return *year;
}
double Movie::GetRating() {
    cout << "Применен GetRating" << endl;
    return *rating;
}
bool Movie::GetIs3D() {
    cout << "Применен GetIs3D" << endl;
    return *is3D;
}

// Специфичный метод
void Movie::GetRecommendation() {
    cout << "Применен метод GetRecommendation" << endl;
    if (*rating >= 8.0) {
        cout << "Рекомендация: Шедевр! Обязательно к просмотру." << endl;
    } else if (*rating >= 6.0) {
        cout << "Рекомендация: Хороший фильм на вечер." << endl;
    } else {
        cout << "Рекомендация: Лучше пропустить, слишком низкий рейтинг." << endl;
    }
}
