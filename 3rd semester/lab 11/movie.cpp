#include "movie.h"

#include <cstring>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace {
char* CopyText(const char* text) {
    char* copy = new char[strlen(text) + 1];
    strcpy(copy, text);
    return copy;
}
}

const char* MovieNotAssignedException::what() const noexcept {
    return "Фильм не назначен на сеанс";
}

Movie::Movie(const char* newTitle, int newYear, double newRating, bool status) {
    title = CopyText(newTitle);
    year = new int(newYear);
    rating = new double(newRating);
    is3D = new bool(status);
}

Movie::~Movie() {
    delete[] title;
    delete year;
    delete rating;
    delete is3D;
}

const char* Movie::GetTitle() const { return title; }
int Movie::GetYear() const { return *year; }
double Movie::GetRating() const { return *rating; }
bool Movie::GetIs3D() const { return *is3D; }

SciFiMovie::SciFiMovie(const char* newTitle, int newYear, double newRating,
                       bool status, const char* newTechnology)
    : Movie(newTitle, newYear, newRating, status) {
    technology = CopyText(newTechnology);
}

SciFiMovie::~SciFiMovie() {
    delete[] technology;
}

void SciFiMovie::SetTechnology(const char* newTechnology) {
    char* newValue = CopyText(newTechnology);
    delete[] technology;
    technology = newValue;
}

void SciFiMovie::GetRecommendation() const {
    cout << "Рекомендация: фантастический фильм \"" << title << "\"";
    cout << (*rating >= 7.5 ? " стоит посмотреть.\n" : " можно посмотреть ради эффектов.\n");
}

void SciFiMovie::ShowFeatures() const {
    cout << "Технология: " << technology << '\n';
}

HorrorMovie::HorrorMovie(const char* newTitle, int newYear, double newRating,
                         bool status, const char* newTechnology,
                         const char* newMonsterType)
    : SciFiMovie(newTitle, newYear, newRating, status, newTechnology) {
    monsterType = CopyText(newMonsterType);
}

HorrorMovie::~HorrorMovie() {
    delete[] monsterType;
}

void HorrorMovie::SetMonsterType(const char* newMonsterType) {
    char* newValue = CopyText(newMonsterType);
    delete[] monsterType;
    monsterType = newValue;
}

void HorrorMovie::GetRecommendation() const {
    cout << "Рекомендация: хоррор \"" << title << "\" лучше смотреть ночью.\n";
}

void HorrorMovie::ShowFeatures() const {
    cout << "Технология: " << technology << '\n';
    cout << "Главная угроза: " << monsterType << '\n';
}

MovieSession::MovieSession() {
    hallName = CopyText("Не указан");
    ticketPrice = new int(0);
    currentMovie = nullptr;
}

MovieSession::MovieSession(const char* newHallName, int newPrice,
                           Movie* moviePtr)
    : MovieSession() {
    SetHallName(newHallName);
    SetTicketPrice(newPrice);
    SetMovie(moviePtr);
}

MovieSession::~MovieSession() {
    delete[] hallName;
    delete ticketPrice;
}

void MovieSession::SetHallName(const char* newHallName) {
    if (newHallName == nullptr || strlen(newHallName) == 0) {
        throw invalid_argument("Название зала не может быть пустым");
    }

    char* newValue = CopyText(newHallName);
    delete[] hallName;
    hallName = newValue;
}

void MovieSession::SetTicketPrice(int newPrice) {
    if (newPrice <= 0 || newPrice > 5000) {
        throw out_of_range("Цена билета должна быть от 1 до 5000 рублей");
    }

    *ticketPrice = newPrice;
}

void MovieSession::SetMovie(Movie* moviePtr) {
    currentMovie = moviePtr;
}

void MovieSession::ShowSessionInfo() const {
    if (currentMovie == nullptr) {
        throw MovieNotAssignedException();
    }

    cout << "Зал: " << hallName << '\n';
    cout << "Цена билета: " << *ticketPrice << " руб.\n";
    cout << "Фильм: " << currentMovie->GetTitle()
         << " (" << currentMovie->GetYear() << ")\n";
    cout << "Рейтинг: " << currentMovie->GetRating() << '\n';
    cout << "Формат 3D: " << (currentMovie->GetIs3D() ? "да" : "нет") << '\n';
    currentMovie->GetRecommendation();
    currentMovie->ShowFeatures();
}

void MovieSession::ModifyEmbeddedMovieFeatures(const char* newTechnology,
                                               const char* newMonsterType) {
    if (currentMovie == nullptr) {
        throw MovieNotAssignedException();
    }

    HorrorMovie* horror = dynamic_cast<HorrorMovie*>(currentMovie);
    if (horror != nullptr) {
        horror->SetTechnology(newTechnology);
        if (newMonsterType != nullptr) {
            horror->SetMonsterType(newMonsterType);
        }
        return;
    }

    SciFiMovie* scienceFiction = dynamic_cast<SciFiMovie*>(currentMovie);
    if (scienceFiction != nullptr) {
        scienceFiction->SetTechnology(newTechnology);
    }
}

MovieSession MovieSession::CreateSession(const char* hallName, int price,
                                         Movie* moviePtr) {
    return MovieSession(hallName, price, moviePtr);
}
