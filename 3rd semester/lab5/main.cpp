#include <iostream>
#include "movie.cpp"

using namespace std;

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    cout << "*** Создание объекта 1 уровня (Movie) ***" << endl;
    Movie* baseMovie = new Movie("Интерстеллар", 2014, 8.6, true);
    cout << "Фильм: " << baseMovie->GetTitle() << ", Год: " << baseMovie->GetYear() << endl;
    baseMovie->GetRecommendation();
    cout << "Удаление объекта 1 уровня:" << endl;
    delete baseMovie;

    cout << "\n*** Создание объекта 2 уровня (SciFiMovie) ***" << endl;
    SciFiMovie* sciFi = new SciFiMovie("Аватар", 2009, 7.9, true, "Планета Пандора и экзокостюмы");
    cout << "Фильм: " << sciFi->GetTitle() << ", Технологии: " << sciFi->GetTechnology() << endl;
    sciFi->ShowSciFiTech(); 
    cout << "Удаление объекта 2 уровня:" << endl;
    delete sciFi;

    cout << "\n*** Создание объекта 3 уровня (HorrorMovie) ***" << endl;
    HorrorMovie* horror = new HorrorMovie("Чужой", 1979, 8.1, false, "Космический корабль Ностромо", "Ксеноморфы");
    cout << "Фильм: " << horror->GetTitle() << ", Монстр: " << horror->GetMonsterType() << endl;
    
    cout << "\nВызов специфичных методов объекта 3 уровня:" << endl;
    horror->ShowSciFiTech();      
    horror->PrintScreamWarning(); 
    horror->GetRecommendation();  

    cout << "\nУдаление объекта 3 уровня:" << endl;
    delete horror;

    return 0;
}
