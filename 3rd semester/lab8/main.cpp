#include <iostream>
#include "movie.cpp"

using namespace std;

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    cout << ">>> Реализация раннего связывания (объекты на стеке)" << endl;

    // Объект 1 уровня (Movie) больше нельзя создать, так как класс абстрактный.
  
    cout << "\n*** Объект 2 уровня" << endl;
    SciFiMovie earlySciFi("Аватар", 2009, 7.9, true, "Планета Пандора");
    earlySciFi.GetRecommendation();
    earlySciFi.ShowSciFiTech();

    cout << "\n*** Объект 3 уровня" << endl;
    HorrorMovie earlyHorror("Чужой", 1979, 8.1, false, "Корабль Ностромо", "Ксеноморфы");
    earlyHorror.GetRecommendation();
    earlyHorror.ShowSciFiTech();
    earlyHorror.PrintScreamWarning();


    cout << "\n>>> Позднее связывание (выбор пользователя, т.е. через указатель базового класса)" << endl;

    cout << "Какой объект иерархии вы хотите создать?" << endl;
    cout << "1. SciFiMovie (2 уровень)" << endl; // Убран пункт создания Movie
    cout << "2. HorrorMovie (3 уровень)" << endl;
    cout << "Ваш выбор: ";
    
    int choice;
    cin >> choice;
    cout << endl;

    Movie* polyObject = nullptr;    // Объявляем указатель на базовый класс (для полиморфизма)

    switch (choice) {
        // Кейсы перенастроены, чтобы избежать выделения памяти под ныне абстрактный класс Movie
        case 1:
            polyObject = new SciFiMovie("Матрица", 1999, 8.7, false, "Симуляция реальности");
            break;
        case 2:
            polyObject = new HorrorMovie("Нечто", 1982, 8.0, false, "Антарктическая станция", "Инопланетный паразит");
            break;
        default:
            cout << "Неверный выбор! Создаем SciFiMovie по умолчанию." << endl;
            polyObject = new SciFiMovie("Фильм-Заглушка", 2026, 5.0, false, "Нет технологий");
            break;
    }

    cout << "\n*** Объект успешно создан!" << endl;
    cout << "Вызов всех полиморфных методов для созданного объекта через указатель Movie*:" << endl;
    
    // П.3: Вызываем виртуальные методы через указатель абстрактного класса
    polyObject->GetRecommendation();
    polyObject->ShowSciFiTech();
    polyObject->PrintScreamWarning();

    cout << "\n*** Удаление динамического объекта" << endl;
    // Виртуальный деструктор по-прежнему корректно чистит память
    delete polyObject; 

    return 0;
}
