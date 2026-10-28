//... void HorrorMovie::PrintScreamWarning() {
//    cout << "[Horror особый метод] Внимание! Фильм \"" << title << "\" содержит скримеры! Главная угроза: " << monsterType << "!" << endl;
//}

// Реализация методов нового класса из дз 9

MovieSession::MovieSession() {
    cout << "[MovieSession] Конструктор по умолчанию" << endl;
    hallName = new char[1];
    hallName[0] = '\0';
    ticketPrice = new int(0);
    currentMovie = nullptr; // Фильм не назначен
}

MovieSession::MovieSession(const char* newHallName, int newPrice, Movie* moviePtr) {
    cout << "[MovieSession] Конструктор с параметрами" << endl;
    hallName = new char[strlen(newHallName) + 1];
    strcpy(hallName, newHallName);
    ticketPrice = new int(newPrice);
    currentMovie = moviePtr; // Связываем сеанс с объектом фильма
}

MovieSession::~MovieSession() {
    cout << "[MovieSession] Деструктор (Освобождение памяти сеанса)" << endl;
    delete[] hallName;
    delete ticketPrice;
    // Сам фильм currentMovie здесь не удаляем, т.к. сеанс им только пользуется, создается же он в main.
}

void MovieSession::SetHallName(const char* newHallName) {
    delete[] hallName;
    hallName = new char[strlen(newHallName) + 1];
    strcpy(hallName, newHallName);
}

const char* MovieSession::GetHallName() { return hallName; }

void MovieSession::SetTicketPrice(int newPrice) { *ticketPrice = newPrice; }

int MovieSession::GetTicketPrice() { return *ticketPrice; }

void MovieSession::SetMovie(Movie* moviePtr) { currentMovie = moviePtr; }

Movie* MovieSession::GetMovie() { return currentMovie; }

void MovieSession::ShowSessionInfo() {
    cout << "\n!!!Информация о сеансе!!!" << endl;
    cout << "Зал кинотеатра: " << hallName << endl;
    cout << "Стоимость билета: " << *ticketPrice << " руб." << endl;
    
    if (currentMovie != nullptr) {
        cout << "Транслируется фильм: \"" << currentMovie->GetTitle() << "\" (" << currentMovie->GetYear() << ")" << endl;
        cout << "Рейтинг фильма: " << currentMovie->GetRating() << endl;
        cout << "Показ в 3D: " << (currentMovie->GetIs3D() ? "Да" : "Нет") << endl;
        
        // Полиморфные методы встроенного объекта
        cout << "-> Проверка спец-свойств фильма внутри сеанса:" << endl;
        currentMovie->GetRecommendation();
        currentMovie->ShowSciFiTech();
        currentMovie->PrintScreamWarning();
    } else {
        cout << "Фильм на данный сеанс не назначен!" << endl;
    }
}

void MovieSession::StartPreShowAds() {
    cout << "[Сеанс в зале " << hallName << "] Поторопитесь, начинается реклама и трейлеры перед фильмом." << endl;
}
