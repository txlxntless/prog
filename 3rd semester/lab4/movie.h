#ifndef MOVIE_H
#define MOVIE_H

class Movie {
private:
    char* title;      
    int* year;       
    double* rating;   
    bool* is3D;       

    bool Init(const char* newTitle, int newYear, double newRating, bool status);

public:
    Movie();
    Movie(const char* newTitle, int newYear, double newRating, bool status);
    ~Movie();

    // Сеттеры (возвращают bool, чтоб программа знала об ошибке)
    bool SetTitle(const char* newTitle);
    bool SetYear(int newYear);
    bool SetRating(double newRating);
    bool SetIs3D(bool status);

    // Геттеры
    const char* GetTitle();
    int GetYear();
    double GetRating();
    bool GetIs3D();

    // Специфичный метод
    void GetRecommendation();
};

#endif
