// Я подумала, вам будет удобнее читать только измененную часть, а не искать ее среди кучи строк
// ...

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

    // Новые методы (дз 10) <--- ВОТ ЗДЕСЬ НАЧАЛО
    // Метод изменения параметров вложенного поля через нисходящее приведение типов
    void ModifyEmbeddedMovieFeatures(const char* newTech, const char* newMonster = nullptr);

    // Статический метод для создания объектов класса
    static MovieSession CreateSessionInteractively(Movie* moviePtr);    // <--- ВОТ ЗДЕСЬ КОНЕЦ
};
