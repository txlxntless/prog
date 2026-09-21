#include <iostream>
#include <cstring>
using namespace std;

// Домашняя работа
class Movie {
private:
    char* title;      
    int* year;       
    double* rating;   
    bool* is3D;       

public:
    // 1. Конструктор по умолчанию (инициализация базовыми значениями)
    Movie() {
    cout << "[Конструктор] Создание объекта по умолчанию" << endl;
    title = new char[1]; 
    title[0] = '\0';     
    year = new int(0);
    rating = new double(0.0);
    is3D = new bool(false);
    }

    // 2. Параметризованный конструктор (инициализация переданными значениями)
    Movie(const char* newTitle, int newYear, double newRating, bool status) {
        cout << "[Конструктор] Создание объекта с параметрами" << endl;
        title = new char[strlen(newTitle) + 1];
        strcpy(title, newTitle);
        year = new int(newYear);
        rating = new double(newRating);
        is3D = new bool(status);
    }

    // 3. Деструктор 
    ~Movie() {
        cout << "[Деструктор] Освобождение динамической памяти объекта" << endl;
        delete[] title;
        delete year;
        delete rating;
        delete is3D;
    }

    // Сеттеры, Геттеры
    void SetTitle(const char* newTitle) {
        cout << "Применен SetTitle -> \"" << newTitle << "\"" << endl;
        delete[] title; 
        title = new char[strlen(newTitle) + 1];
        strcpy(title, newTitle);
    }
    const char* GetTitle() {
        cout << "Применен GetTitle" << endl;
        return title;
    }

    void SetYear(int newYear) {
        cout << "Применен SetYear -> " << newYear << endl;
        *year = newYear; 
    }
    int GetYear() {
        cout << "Применен GetYear" << endl;
        return *year; 
    }

    void SetRating(double newRating) {
        cout << "Применен SetRating -> " << newRating << endl;
        *rating = newRating;
    }
    double GetRating() {
        cout << "Применен GetRating" << endl;
        return *rating;
    }

    void SetIs3D(bool status) {
        cout << "Применен SetIs3D -> " << (status ? "Да" : "Нет") << endl;
        *is3D = status;
    }
    bool GetIs3D() {
        cout << "Применен GetIs3D" << endl;
        return *is3D;
    }

    // Специфичный метод
    void GetRecommendation() {
        cout << "Применен метод GetRecommendation" << endl;
        if (*rating >= 8.0) {
            cout << "Рекомендация: Шедевр! Обязательно к просмотру." << endl;
        } else if (*rating >= 6.0) {
            cout << "Рекомендация: Хороший фильм на вечер." << endl;
        } else {
            cout << "Рекомендация: Лучше пропустить, слишком низкий рейтинг." << endl;
        }
    }
};

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    // Создание динамического объекта через параметризованный конструктор
    cout << "Инициализация динамического объекта" << endl;
    Movie* myMovie = new Movie("Интерстеллар", 2014, 8.6, true);

    // Демонстрация методов Set
    cout << "\nДемонстрация методов Set" << endl;
    myMovie->SetTitle("Матрица");
    myMovie->SetYear(1999);
    myMovie->SetRating(8.5);
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
    cout << "\nУдаление динамического объекта " << endl;
    delete myMovie;

    return 0;
}
