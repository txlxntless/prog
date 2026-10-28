#include <iostream>
#include "movie.cpp"

using namespace std;

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    cout << ">>> Реализация раннего связывания" << endl;
    
    SciFiMovie earlySciFi("Аватар", 2009, 7.9, true, "Планета Пандора");
    HorrorMovie earlyHorror("Чужой", 1979, 8.1, false, "Корабль Ностромо", "Ксеноморфы");

    cout << ">>> Демонстрация нового класса из дз 9" << endl;

    // Создание объекта класса через конструктор по умолчанию
    cout << "\n1. Создаем пустой сеанс (конструктор по умолчанию):" << endl;
    MovieSession emptySession;
    emptySession.ShowSessionInfo(); 

    // Использование сеттеров для нового сеанса
    emptySession.SetHallName("Зал IMAX");
    emptySession.SetTicketPrice(450);
    emptySession.SetMovie(&earlySciFi);

    cout << "\nОбновленный сеанс после заполнения:" << endl;
    emptySession.ShowSessionInfo();

    // Создание объекта через конструктор с параметрами
    cout << "\n2. Создаем сеанс с параметрами (передан HorrorMovie):" << endl;
    MovieSession activeSession("VIPзал", 700, &earlyHorror); 

    // Вызов всех методов нового класса для демонстрации работы
    cout << "\nВызов метода StartPreShowAds()" << endl;
    activeSession.StartPreShowAds();

    cout << "\nВызов метода ShowSessionInfo()" << endl;
    activeSession.ShowSessionInfo();

    cout << "\nТест индивидуальных геттеров сеанса:" << endl;
    cout << "Название зала через: " << activeSession.GetHallName() << endl;
    cout << "Цена билета через: " << activeSession.GetTicketPrice() << " руб." << endl;
    cout << "Название фильма: " << activeSession.GetMovie()->GetTitle() << endl;

    cout << "\n>>> Завершение работы программы и вызов деструкторов" << endl;
    
    return 0;
}
