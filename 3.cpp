#include <iostream>
#include <cstring>
using namespace std;

class BankAccount {
private:
    char* ownerName;      
    int* accountNumber;   
    double* balance;     
    bool* isSavings;      

public:
    
    BankAccount() {
        cout << "Конструктор: Создание объекта по умолчанию" << endl;
        ownerName = new char[1]; 
        ownerName[0] = '\0';     
        accountNumber = new int(0);
        balance = new double(0.0);
        isSavings = new bool(false);
    }

    BankAccount(const char* newOwner, int newNumber, double newBalance, bool status) {
        cout << "Конструктор: Создание объекта с параметрами" << endl;
        ownerName = new char[strlen(newOwner) + 1];
        strcpy(ownerName, newOwner);
        accountNumber = new int(newNumber);
        balance = new double(newBalance);
        isSavings = new bool(status);
    }
 
    ~BankAccount() {
        cout << "Деструктор: Освобождение динамической памяти объекта" << endl;
        delete[] ownerName;
        delete accountNumber;
        delete balance;
        delete isSavings;
    }

    void SetOwnerName(const char* newOwner) {
        cout << "Применен SetOwnerName -> \"" << newOwner << "\"" << endl;
        delete[] ownerName; 
        ownerName = new char[strlen(newOwner) + 1];
        strcpy(ownerName, newOwner);
    }
    const char* GetOwnerName() {
        cout << "Применен GetOwnerName" << endl;
        return ownerName;
    }

    void SetAccountNumber(int newNumber) {
        cout << "Применен SetAccountNumber -> " << newNumber << endl;
        *accountNumber = newNumber; 
    }
    int GetAccountNumber() {
        cout << "Применен GetAccountNumber" << endl;
        return *accountNumber; 
    }

    void SetBalance(double newBalance) {
        cout << "Применен SetBalance -> " << newBalance << " руб." << endl;
        *balance = newBalance;
    }
    double GetBalance() {
        cout << "Применен GetBalance" << endl;
        return *balance;
    }

    void SetIsSavings(bool status) {
        cout << "Применен SetIsSavings -> " << (status ? "Да" : "Нет") << endl;
        *isSavings = status;
    }
    bool GetIsSavings() {
        cout << "Применен GetIsSavings" << endl;
        return *isSavings;
    }

    // Специфичный метод
    void GetFinancialStatus() {
        cout << "Применен метод GetFinancialStatus" << endl;
        if (*balance >= 100000.0) {
            cout << "Финансовый статус: Отличный баланс! Деньги работают на вас." << endl;
        } else if (*balance >= 10000.0) {
            cout << "Финансовый статус: Стабильное положение. Есть базовая подушка безопасности." << endl;
        } else {
            cout << "Финансовый статус: Баланс критически мал. Рекомендуется пополнить счет." << endl;
        }
    }
};

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    cout << "Инициализация динамического объекта" << endl;
    BankAccount* myAccount = new BankAccount("Александр Пушкин", 12345678, 250000.50, true);

    cout << "\nДемонстрация методов Set" << endl;
    myAccount->SetOwnerName("Иван Иванов");
    myAccount->SetAccountNumber(98765432);
    myAccount->SetBalance(15000.75);
    myAccount->SetIsSavings(false);

    cout << "\nИнформация о счете через методы Get" << endl;
    cout << "Владелец: " << myAccount->GetOwnerName() << endl;
    cout << "Номер счета: " << myAccount->GetAccountNumber() << endl;
    cout << "Текущий баланс: " << myAccount->GetBalance() << " руб." << endl;
    cout << "Сберегательный тариф: " << (myAccount->GetIsSavings() ? "Да" : "Нет") << endl;

    cout << "\nВызов специфичного метода" << endl;
    myAccount->GetFinancialStatus();

    cout << "\nУдаление динамического объекта " << endl;
    delete myAccount;

    return 0;
}
