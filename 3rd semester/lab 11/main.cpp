#include "movie.h"

#include <clocale>
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    HorrorMovie alien("Чужой", 1979, 8.1, false,
                      "Корабль Ностромо", "Ксеноморф");

    cout << "Обычная работа программы\n";
    // Создаем объект напрямую через конструктор, чтобы избежать ошибки копирования памяти
    MovieSession session("VIP-зал", 600, &alien);
    session.ModifyEmbeddedMovieFeatures("Спасательный челнок",
                                          "Королева ксеноморфов");
    session.ShowSessionInfo();

    cout << "\n1. Проверка invalid_argument\n";
    try {
        session.SetHallName("");
    } catch (const invalid_argument& error) {
        cout << "Исключение обработано: " << error.what() << '\n';
    }

    cout << "\n2. Проверка out_of_range\n";
    try {
        session.SetTicketPrice(-100);
    } catch (const out_of_range& error) {
        cout << "Исключение обработано: " << error.what() << '\n';
    }

    cout << "\n3. Проверка собственного класса исключения\n";
    try {
        MovieSession emptySession;
        emptySession.ShowSessionInfo();
    } catch (const MovieNotAssignedException& error) {
        cout << "Исключение обработано: " << error.what() << '\n';
    }

    return 0;
}
