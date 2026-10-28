#ifndef MOVIE_H
#define MOVIE_H

class Movie { // 1 уровень вложенности (абстрактный класс)
protected:
    char* title;
    int* year;
    double* rating;
    bool* is3D;
public:
    Movie();
    Movie(const char* newTitle, int newYear, double newRating, bool status);
    virtual ~Movie();
    void SetTitle(const char* newTitle);
    const char* GetTitle();
    void SetYear(int newYear);
    int GetYear();
    void SetRating(double newRating);
    double GetRating();
    void SetIs3D(bool status);
    bool GetIs3D();
    
    // Полиморфные методы
    virtual void GetRecommendation() = 0; 
    virtual void ShowSciFiTech();
    virtual void PrintScreamWarning();
};

class SciFiMovie : public Movie { // Уровень вложенности 2
protected:
    char* technology;
public:
    SciFiMovie();
    SciFiMovie(const char* newTitle, int newYear, double newRating, bool status, const char* newTech);
    virtual ~SciFiMovie();
    void SetTechnology(const char* newTech);
    const char* GetTechnology();
    void GetRecommendation() override;
    void ShowSciFiTech() override;
};

// Новый класс для домашнего задания 9
class MovieSession {
private:
    char* hallName;       // Название зала
    int* ticketPrice;     // Цена билета
    Movie* currentMovie;  // Указатель на базовый класс
public:
    MovieSession();
    MovieSession(const char* newHallName, int newPrice, Movie* moviePtr);
    ~MovieSession();

    // Геттеры и сеттеры
    void SetHallName(const char* newHallName);
    const char* GetHallName();
    void SetTicketPrice(int newPrice);
    int GetTicketPrice();
    void SetMovie(Movie* moviePtr);
    Movie* GetMovie();

    // Методы демонстрации
    void ShowSessionInfo();
    void StartPreShowAds();
};

class HorrorMovie : public SciFiMovie { // Уровень вложения 3
private:
    char* monsterType;
public:
    HorrorMovie();
    HorrorMovie(const char* newTitle, int newYear, double newRating, bool status, const char* newTech, const char* newMonster);
    ~HorrorMovie() override;
    void SetMonsterType(const char* newMonster);
    const char* GetMonsterType();
    void GetRecommendation() override;
    void ShowSciFiTech() override;
    void PrintScreamWarning() override;
};

#endif
