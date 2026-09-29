#include <iostream>
#include <cstring>
#include "movie.h"
using namespace std;

Movie::Movie() { // Уровень 1
    cout << "[Movie] Конструктор по умолчанию" << endl;
    title = new char[1]; title[0] = '\0';     
    year = new int(0);
    rating = new double(0.0);
    is3D = new bool(false);
}

Movie::Movie(const char* newTitle, int newYear, double newRating, bool status) {
    cout << "[Movie] Конструктор с параметрами" << endl;
    title = new char[strlen(newTitle) + 1];
    strcpy(title, newTitle);
    year = new int(newYear);
    rating = new double(newRating);
    is3D = new bool(status);
}

Movie::~Movie() {
    cout << "[Movie] Деструктор (Освобождение памяти)" << endl;
    delete[] title;
    delete year;
    delete rating;
    delete is3D;
}

void Movie::SetTitle(const char* newTitle) {
    cout << "Movie: Применен SetTitle -> \"" << newTitle << "\"" << endl;
    delete[] title; 
    title = new char[strlen(newTitle) + 1];
    strcpy(title, newTitle);
}
const char* Movie::GetTitle() { return title; }

void Movie::SetYear(int newYear) { *year = newYear; }
int Movie::GetYear() { return *year; }

void Movie::SetRating(double newRating) { *rating = newRating; }
double Movie::GetRating() { return *rating; }

void Movie::SetIs3D(bool status) { *is3D = status; }
bool Movie::GetIs3D() { return *is3D; }

void Movie::GetRecommendation() {
    cout << "Применен метод GetRecommendation для \"" << title << "\"" << endl;
    if (*rating >= 8.0) {
        cout << "Рекомендация: Шедевр! Обязательно к просмотру." << endl;
    } else {
        cout << "Рекомендация: Обычный фильм на вечер." << endl;
    }
}


// Уровень 2
SciFiMovie::SciFiMovie() : Movie() { 
    cout << "[SciFiMovie] Конструктор по умолчанию" << endl;
    technology = new char[1]; technology[0] = '\0';
}

SciFiMovie::SciFiMovie(const char* newTitle, int newYear, double newRating, bool status, const char* newTech) 
    : Movie(newTitle, newYear, newRating, status) { 
    cout << "[SciFiMovie] Конструктор с параметрами" << endl;
    technology = new char[strlen(newTech) + 1];
    strcpy(technology, newTech);
}

SciFiMovie::~SciFiMovie() {
    cout << "[SciFiMovie] Деструктор (Освобождение памяти)" << endl;
    delete[] technology;
}

void SciFiMovie::SetTechnology(const char* newTech) {
    cout << "SciFiMovie: Применен SetTechnology -> \"" << newTech << "\"" << endl;
    delete[] technology;
    technology = new char[strlen(newTech) + 1];
    strcpy(technology, newTech);
}
const char* SciFiMovie::GetTechnology() { return technology; }

void SciFiMovie::ShowSciFiTech() {
    cout << "В фантастическом фильме \"" << title << "\" ключевая фишка — это " << technology << endl;
}

// Уровень 3
HorrorMovie::HorrorMovie() : SciFiMovie() { 
    cout << "[HorrorMovie] Конструктор по умолчанию" << endl;
    monsterType = new char[1]; monsterType[0] = '\0';
}

HorrorMovie::HorrorMovie(const char* newTitle, int newYear, double newRating, bool status, const char* newTech, const char* newMonster)
    : SciFiMovie(newTitle, newYear, newRating, status, newTech) { 
    cout << "[HorrorMovie] Конструктор с параметрами" << endl;
    monsterType = new char[strlen(newMonster) + 1];
    strcpy(monsterType, newMonster);
}

HorrorMovie::~HorrorMovie() {
    cout << "[HorrorMovie] Деструктор (Освобождение памяти)" << endl;
    delete[] monsterType;
}

void HorrorMovie::SetMonsterType(const char* newMonster) {
    cout << "HorrorMovie: Применен SetMonsterType -> \"" << newMonster << "\"" << endl;
    delete[] monsterType;
    monsterType = new char[strlen(newMonster) + 1];
    strcpy(monsterType, newMonster);
}
const char* HorrorMovie::GetMonsterType() { return monsterType; }

void HorrorMovie::PrintScreamWarning() {
    cout << "Карамба! Фильм \"" << title << "\" содержит скримеры!" << monsterType << "!" << endl;
}
