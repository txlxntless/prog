#include <iostream>
#include <cstring>
using namespace std;

// Лабораторная работа

class Table {
private:
    int length;       
    int width;        
    int height;
    char color[20];

public:
    void SetLength(int newLength) {
        cout << "Применен метод SetLength для изменения длины на " << newLength << endl;
        length = newLength;
    }
    int GetLength() {
        cout << "Применен метод GetLength" << endl;
        return length;
    }

    // Методы Set и Get для ШИРИНЫ
    void SetWidth(int newWidth) {
        cout << "Применен метод SetWidth для изменения ширины на " << newWidth << endl;
        width = newWidth;
    }
    int GetWidth() {
        cout << "Применен метод GetWidth" << endl;
        return width;
    }

    // Методы Set и Get для ВЫСОТЫ
    void SetHeight(int newHeight) {
        cout << "Применен метод SetHeight для изменения высоты на " << newHeight << endl;
        height = newHeight;
    }
    int GetHeight() {
        cout << "Применен метод GetHeight" << endl;
        return height;
    }

    void SetColor(const char* newColor) {
        cout << "Применен метод SetColor для изменения цвета на \"" << newColor << "\"" << endl;
        strcpy(color, newColor);
    }

    const char* GetColor() {
        cout << "Прменен метод GetColor" << endl;
        return color;
    }

    int CalcVolume() {
        cout << "Прменен метод CalcVolume (т.е. вычисление объема стола)" << endl;
        return length * width * height;
    }
};

// Домашняя работа: Свой класс "Кинофильм"
class Movie {
private:
    char title[50];    // Название фильма 
    int year;          // Год выпуска 
    double rating;     // Рейтинг фильма 
    bool is3D;         // Доступен ли в 3D?

public:
    void SetTitle(const char* newTitle) {
        cout << "Прменен SetTitle -> \"" << newTitle << "\"" << endl;
        strcpy(title, newTitle);
    }
    const char* GetTitle() {
        cout << "Прменен GetTitle" << endl;
        return title;
    }

    void SetYear(int newYear) {
        cout << "Прменен SetYear -> " << newYear << endl;
        year = newYear;
    }
    int GetYear() {
        cout << "Прменен GetYear" << endl;
        return year;
    }

    void SetRating(double newRating) {
        cout << "Прменен SetRating -> " << newRating << endl;
        rating = newRating;
    }
    double GetRating() {
        cout << "Прменен GetRating" << endl;
        return rating;
    }

    void SetIs3D(bool status) {
        cout << "Прменен SetIs3D -> " << (status ? "Да" : "Нет") << endl;
        is3D = status;
    }
    bool GetIs3D() {
        cout << "Прменен GetIs3D" << endl;
        return is3D;
    }

    void GetRecommendation() {
    cout << "Применен метод GetRecommendation" << endl;
    if (rating >= 8.0) {
        cout << "Рекомендация: Шедевр! Обязательно к просмотру." << endl;
    } else if (rating >= 6.0) {
        cout << "Рекомендация: Хороший фильм на вечер." << endl;
    } else {
        cout << "Рекомендация: Лучше пропустить, слишком низкий рейтинг." << endl;
    }
}
};

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    Table myTable;

    myTable.SetLength(5);   
    myTable.SetWidth(3);    
    myTable.SetHeight(2);
    myTable.SetColor("Черный");

    // Демонстрация методов Get
    cout << "\nИнформация о столе через методы Get:" << endl;
    cout << "Длина: " << myTable.GetLength() << endl;
    cout << "Ширина: " << myTable.GetWidth() << endl;
    cout << "Высота: " << myTable.GetHeight() << endl;
    cout << "Цвет: " << myTable.GetColor() << endl;

    // Демонстрация метод CalcVolume
    cout << "\nРасчет объема:" << endl;
    cout << "Объем стола равен: " << myTable.CalcVolume() << " куб. ед." << endl;

    Movie myMovie;

    // Демонстрация методов Set
    myMovie.SetTitle("Матрица");
    myMovie.SetYear(1999);
    myMovie.SetRating(8.5);
    myMovie.SetIs3D(false);

    // Демонстрация методов Get
    cout << "\nИнформация о фильме через методы Get:" << endl;
    cout << "Название: " << myMovie.GetTitle() << endl;
    cout << "Год выпуска: " << myMovie.GetYear() << endl;
    cout << "Рейтинг IMDb: " << myMovie.GetRating() << endl;
    cout << "Поддержка 3D: " << (myMovie.GetIs3D() ? "Есть" : "Нет") << endl;

    // Демонстрация надеюсь работы специфичного метода
    cout << "\nВызов специфичного метода:" << endl;
    myMovie.GetRecommendation();

    return 0;
}
