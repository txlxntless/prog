#include <iostream>
#include "movie.cpp"
using namespace std;

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    SciFiMovie avatar("Аватар", 2009, 7.9, true, "Планета Пандора");
    HorrorMovie alien("Чужой", 1979, 8.1, false, "Корабль Ностромо", "Ксеноморфы");

    // Демонстрация статического метода
    cout << "\n>>> Тест статического метода создания объекта" << endl;
    // Вызываем статический метод напрямую через имя класса, без создания нового объекта 
    MovieSession session1 = MovieSession::CreateSessionInteractively(&avatar);
    
    cout << "\nПроверяем созданный статическим методом сеанс:" << endl;
    session1.ShowSessionInfo();


    // 2. Демонстрация нисходящего приведения типов
    cout << "\n>>> Тест нисходящего приведения типов" << endl;
    // Создаем обычный сеанс для фильма ужасов "Чужой"
    MovieSession session2("VIP-Зал", 600, &alien);
    cout << "\nИсходные данные фильма в сеансе до изменения:" << endl;
    session2.ShowSessionInfo();

    // Вызываем метод изменения параметров встроенного поля, передаем новые технологию и монстра (внутри отработает dynamic_cast)
    session2.ModifyEmbeddedMovieFeatures("Модернизированный челнок", "Королева Ксеноморфов");

    cout << "\nДанные сеанса после применения Downcasting и изменения полей:" << endl;
    session2.ShowSessionInfo();

    cout << ">>> Завершение программы и работа деструкторов" << endl;
    
    return 0;
}
