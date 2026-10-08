#include <iostream>
#include "movie.cpp"

using namespace std;

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    // П.4: Раннее связывание 
    cout << ">>> П.4: Реализация раннего связывания (объекты на стеке)" << endl;

    cout << "\n*** Объект 1 уровня" << endl;
    Movie earlyMovie("Интерстеллар", 2014, 8.6, true);
    earlyMovie.GetRecommendation();

    cout << "\n*** Объект 2 уровня" << endl;
    SciFiMovie earlySciFi("Аватар", 2009, 7.9, true, "Планета Пандора");
    earlySciFi.GetRecommendation();
    earlySciFi.ShowSciFiTech();

    cout << "\n*** Объект 3 уровня" << endl;
    HorrorMovie earlyHorror("Чужой", 1979, 8.1, false, "Корабль Ностромо", "Ксеноморфы");
    earlyHorror.GetRecommendation();
    earlyHorror.ShowSciFiTech();
    earlyHorror.PrintScreamWarning();


    cout << ">>> П.2 и 3: Позднее связывание (выбор пользователя, т.е. через указатель базового класса)" << endl;

    cout << "Какой объект иерархии вы хотите создать?" << endl;
    cout << "1. Movie (1 уровень)" << endl;
    cout << "2. SciFiMovie (2 уровень)" << endl;
    cout << "3. HorrorMovie (3 уровень)" << endl;
    cout << "Ваш выбор: ";
    
    int choice;
    cin >> choice;
    cout << endl;

    // Объявляем указатель на базовый класс (уже в полиморфизме)
    Movie* polyObject = nullptr;

    switch (choice) {
        case 1:
            polyObject = new Movie("Начало", 2010, 8.5, false);
            break;
        case 2:
            polyObject = new SciFiMovie("Матрица", 1999, 8.7, false, "Симуляция реальности");
            break;
        case 3:
            polyObject = new HorrorMovie("Нечто", 1982, 8.0, false, "Антарктическая станция", "Инопланетный паразит");
            break;
        default:
            cout << "Неверный выбор! Создаем базовый Movie по умолчанию." << endl;
            polyObject = new Movie("Фильм-Заглушка", 2026, 5.0, false);
            break;
    }

    cout << "\n*** Объект успешно создан!" << endl;
    cout << "Вызов всех полиморфных методов для созданного объекта через указатель Movie*:" << endl;
    
    // П.3: Вызываем  виртуальные методы
    polyObject->GetRecommendation();
    polyObject->ShowSciFiTech();
    polyObject->PrintScreamWarning();

    cout << "\n*** Удаление динамического объекта" << endl;
    // Виртуальный деструктор чистит память верно для любого дочернего класса
    delete polyObject; 

    return 0;
}
