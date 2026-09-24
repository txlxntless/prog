#include <iostream>
#include "movie.cpp"

using namespace std;

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    // Проверяем защиту в конструкторе (нереальный 1200 год)
    cout << "Попытка создать плохой объект" << endl;
    Movie* badMovie = new Movie("Карамба", 1200, 8.5, true);
    cout << "Имя в объекте: " << badMovie->GetTitle() << ", Год: " << badMovie->GetYear() << endl;
    delete badMovie;

    cout << "\nОбычная работа программы" << endl;
    // Создание динамического объекта через параметризованный конструктор
    Movie* myMovie = new Movie("Интерстеллар", 2014, 8.6, true);

    // Демонстрация методов Set
    cout << "\nДемонстрация методов Set" << endl;
    myMovie->SetTitle("Матрица");
    myMovie->SetYear(1999);
    
    // Пробуем передать несуществующий рейтинг (15.0) в метод Set
    if (myMovie->SetRating(15.0) == false) {
        cout << "Внимание: Рейтинг 15.0 — несуществующий!" << endl;
    }
    
    myMovie->SetIs3D(false);

    // Демонстрация методов Get
    cout << "\nИнформация о фильме через методы Get" << endl;
    cout << "Название: " << myMovie->GetTitle() << endl;
    cout << "Год выпуска: " << myMovie->GetYear() << endl;
    cout << "Рейтинг IMDb: " << myMovie->GetRating() << endl;
    cout << "Поддержка 3D: " << (myMovie->GetIs3D() ? "Есть" : "Нет") << endl;

    // Демонстрация работы специфичного метода
    cout << "\nВызов специфичного метода" << endl;
    myMovie->GetRecommendation();

    // Удаление динамического объекта и вызов деструктора
    cout << "\nУдаление динамического объекта (вызов деструкторов)" << endl;
    delete myMovie;

    return 0;
}
