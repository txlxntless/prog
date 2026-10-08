#include <iostream>
#include <cstring>
#include "movie.h"
using namespace std;

// Уровень 1 (Movie) 
Movie::Movie() {
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
    cout << "[Базовый метод] Рекомендация для \"" << title << "\": ";
    if (*rating >= 8.0) cout << "Шедевр! Обязательно к просмотру." << endl;
    else cout << "Обычный фильм на вечер." << endl;
}
void Movie::ShowSciFiTech() {
    cout << "[Базовый метод] У фильма \"" << title << "\" нет выраженных фантастических технологий." << endl;
}
void Movie::PrintScreamWarning() {
    cout << "[Базовый метод] Фильм \"" << title << "\" безопасен, скримеров не обнаружено." << endl;
}


// Уровень вложеннсоти 2 (SciFiMovie)
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
    delete[] technology;
    technology = new char[strlen(newTech) + 1];
    strcpy(technology, newTech);
}
const char* SciFiMovie::GetTechnology() { return technology; }

void SciFiMovie::GetRecommendation() {
    cout << "[SciFi особый метод] Рекомендация любителям фантастики для \"" << title << "\": ";
    if (*rating >= 7.5) cout << "Потрясающий визуальный и научный опыт!" << endl;
    else cout << "Можно глянуть ради спецэффектов." << endl;
}
void SciFiMovie::ShowSciFiTech() {
    cout << "[SciFi особый метод] В фантастическом фильме \"" << title << "\" ключевая фишка — это " << technology << endl;
}


// Уровень вложенности 3 (HorrorMovie)
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
    delete[] monsterType;
    monsterType = new char[strlen(newMonster) + 1];
    strcpy(monsterType, newMonster);
}
const char* HorrorMovie::GetMonsterType() { return monsterType; }

void HorrorMovie::GetRecommendation() {
    cout << "[Horror особый метод] Смотреть строго ночью! Фильм: \"" << title << "\"." << endl;
}
void HorrorMovie::ShowSciFiTech() {
    cout << "[Horror особый метод] Хоррор-сайфай \"" << title << "\" сочетает технологии (" << technology << ") и ужас!" << endl;
}
void HorrorMovie::PrintScreamWarning() {
    cout << "[Horror особый метод] Внимание! Фильм \"" << title << "\" содержит скримеры! Главная угроза: " << monsterType << "!" << endl;
}
