//... class SciFiMovie : public Movie { ... }

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

// ...
//#endif
