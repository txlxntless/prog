#include <iostream> 
#include <fstream> 
#include <string> 
#include "book_of_subscribers.cpp"

void resizeArray(Subscriber*& arr, int& capacity) { 
    int newCapacity = (capacity == 0) ? 4 : capacity * 2; 
    Subscriber* newArr = new Subscriber[newCapacity]; 
    for (int i = 0; i < capacity; ++i) { 
        newArr[i] = arr[i]; 
    } 
    if (arr != nullptr) {
        delete[] arr; 
    }
    arr = newArr; 
    capacity = newCapacity; 
}
 
int main() { 
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    std::ifstream file("subscribers.txt"); 

    if (!file.is_open()) { 
        std::cout << "Ошибка открытия файла subscribers.txt!\n"; 
        return 1; 
    } 
 
    int capacity = 0; 
    int size = 0; 
    Subscriber* subscribers = nullptr; 
 
    std::string phone, name, tariff; 
    double fee; 
 
    while (file >> phone) {
        file.ignore();
        std::getline(file, name);
        std::getline(file, tariff);
        file >> fee;
        file.ignore();
        
        if (size >= capacity) {
            resizeArray(subscribers, capacity);
        }
        
        subscribers[size] = Subscriber(phone, name, tariff, fee);
        size++;
        
        std::cout << "Текущее кол-во объектов в памяти: " << Subscriber::getObjectCount() << "\n";
    }
    file.close(); 
 
    std::cout << "Список всех абонентов:\n"; 
    for (int i = 0; i < size; ++i) { 
        subscribers[i].printInfo(); 
    } 
 
    std::cout << "\nНомера, закрепленные за Ивановым:\n"; 
    bool found = false; 
    for (int i = 0; i < size; ++i) { 
        if (subscribers[i].getFullName().find("Иванов") == 0) { 
            std::cout << "Абонент " << subscribers[i].getFullName() << 
" | Номер: " << subscribers[i].getPhoneNumber() << "\n"; 
            found = true; 
        } 
    } 
    if (!found) { 
std::cout << "Абоненты с фамилией Иванов не найдены.\n"; 
} 
delete[] subscribers;

std::cout << "\nКол-во объектов после очистки памяти: " << Subscriber::getObjectCount() << "\n";

return 0; 
} 
