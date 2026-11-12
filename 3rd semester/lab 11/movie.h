#ifndef MOVIE_H
#define MOVIE_H

#include <exception>

// Собственный класс исключения
class MovieNotAssignedException : public std::exception {
public:
    const char* what() const noexcept override;
};

class Movie {
protected:
    char* title;
    int* year;
    double* rating;
    bool* is3D;

public:
    Movie(const char* newTitle, int newYear, double newRating, bool status);
    virtual ~Movie();

    const char* GetTitle() const;
    int GetYear() const;
    double GetRating() const;
    bool GetIs3D() const;

    virtual void GetRecommendation() const = 0;
    virtual void ShowFeatures() const = 0;
};

class SciFiMovie : public Movie {
protected:
    char* technology;

public:
    SciFiMovie(const char* newTitle, int newYear, double newRating,
               bool status, const char* newTechnology);
    ~SciFiMovie() override;

    void SetTechnology(const char* newTechnology);
    void GetRecommendation() const override;
    void ShowFeatures() const override;
};

class HorrorMovie : public SciFiMovie {
private:
    char* monsterType;

public:
    HorrorMovie(const char* newTitle, int newYear, double newRating,
                bool status, const char* newTechnology,
                const char* newMonsterType);
    ~HorrorMovie() override;

    void SetMonsterType(const char* newMonsterType);
    void GetRecommendation() const override;
    void ShowFeatures() const override;
};

class MovieSession {
private:
    char* hallName;
    int* ticketPrice;
    Movie* currentMovie;

public:
    MovieSession();
    MovieSession(const char* newHallName, int newPrice, Movie* moviePtr);
    ~MovieSession();

    void SetHallName(const char* newHallName);
    void SetTicketPrice(int newPrice);
    void SetMovie(Movie* moviePtr);

    void ShowSessionInfo() const;
    void ModifyEmbeddedMovieFeatures(const char* newTechnology,
                                     const char* newMonsterType = nullptr);

    static MovieSession CreateSession(const char* hallName, int price,
                                      Movie* moviePtr);
};

#endif
