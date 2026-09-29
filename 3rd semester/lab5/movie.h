#ifndef MOVIE_H
#define MOVIE_H

class Movie {
protected: 
    char* title;      
    int* year;       
    double* rating;   
    bool* is3D;       

public:
    Movie();
    Movie(const char* newTitle, int newYear, double newRating, bool status);
    ~Movie(); 

    void SetTitle(const char* newTitle);
    const char* GetTitle();
    void SetYear(int newYear);
    int GetYear();
    void SetRating(double newRating);
    double GetRating();
    void SetIs3D(bool status);
    bool GetIs3D();
    void GetRecommendation();
};

class SciFiMovie : public Movie {
protected:
    char* technology; 

public:
    SciFiMovie();
    SciFiMovie(const char* newTitle, int newYear, double newRating, bool status, const char* newTech);
    ~SciFiMovie(); 

    void SetTechnology(const char* newTech);
    const char* GetTechnology();
    void ShowSciFiTech(); 
};

class HorrorMovie : public SciFiMovie {
private:
    char* monsterType; 

public:
    HorrorMovie();
    HorrorMovie(const char* newTitle, int newYear, double newRating, bool status, const char* newTech, const char* newMonster);
    ~HorrorMovie(); 

    void SetMonsterType(const char* newMonster);
    const char* GetMonsterType();
    void PrintScreamWarning(); 
};

#endif
