#ifndef MOVIE_H
#define MOVIE_H

class Movie { // 1 уровень вложеннсоти
protected:
    char* title;
    int* year;
    double* rating;
    bool* is3D;

public:
    Movie();
    Movie(const char* newTitle, int newYear, double newRating, bool status);
    virtual ~Movie(); // Виртуальный деструктор для позднего связывания (надеюсь верно)

    void SetTitle(const char* newTitle);
    const char* GetTitle();
    void SetYear(int newYear);
    int GetYear();
    void SetRating(double newRating);
    double GetRating();
    void SetIs3D(bool status);
    bool GetIs3D();

    // Полиморфные методы
    virtual void GetRecommendation();
    virtual void ShowSciFiTech();
    virtual void PrintScreamWarning();
};

class SciFiMovie : public Movie { // Уровень вложенности 2
protected:
    char* technology;

public:
    SciFiMovie();
    SciFiMovie(const char* newTitle, int newYear, double newRating, bool status, const char* newTech);
    virtual ~SciFiMovie() override;

    void SetTechnology(const char* newTech);
    const char* GetTechnology();

    // Переопределение метода 1-го уровня вложенности
    void GetRecommendation() override;
    // Переопределение (полиморфизм)
    void ShowSciFiTech() override;
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

    // Переопределение методов для полиморфизма
    void GetRecommendation() override;
    void ShowSciFiTech() override;
    void PrintScreamWarning() override;
};

#endif
