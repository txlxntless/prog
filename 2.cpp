#include <iostream>
#include <cstring>
using namespace std;

class BankAccount {
private:
    char ownerName[50];   // Имя владельца счета
    int accountNumber;    // Номер счета
    double balance;       // Баланс 
    bool isSavings;       // Является ли счет сберегательным/накопительным

public:
    void SetOwnerName(const char* newOwner) {
        cout << "Применен SetOwnerName -> \"" << newOwner << "\"" << endl;
        strcpy(ownerName, newOwner);
    }
    const char* GetOwnerName() {
        cout << "Применен GetOwnerName" << endl;
        return ownerName;
    }

    void SetAccountNumber(int newNumber) {
        cout << "Применен SetAccountNumber -> " << newNumber << endl;
        accountNumber = newNumber;
    }
    int GetAccountNumber() {
        cout << "Применен GetAccountNumber" << endl;
        return accountNumber;
    }

    void SetBalance(double newBalance) {
        cout << "Применен SetBalance -> " << newBalance << " руб." << endl;
        balance = newBalance;
    }
    double GetBalance() {
        cout << "Применен GetBalance" << endl;
        return balance;
    }

    void SetIsSavings(bool status) {
        cout << "Применен SetIsSavings -> " << (status ? "Да" : "Нет") << endl;
        isSavings = status;
    }
    bool GetIsSavings() {
        cout << "Применен GetIsSavings" << endl;
        return isSavings;
    }

    // Специфичный метод: оценка состояния финансового состояния счета
    void GetFinancialStatus() {
        cout << "Применен метод GetFinancialStatus" << endl;
        if (balance >= 100000.0) {
            cout << "Финансовый статус: Отличный баланс! Деньги работают на вас." << endl;
        } else if (balance >= 10000.0) {
            cout << "Стабильное положение. Есть подушка безопасности." << endl;
        } else {
            cout << "Баланс критически мал. Рекомендуется пополнить счет." << endl;
        }
    }
};

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    BankAccount myAccount;

    // Сеттеры
    myAccount.SetOwnerName("Иван Иванов");
    myAccount.SetAccountNumber(98765432);
    myAccount.SetBalance(150000.75);
    myAccount.SetIsSavings(true);

    // Геттеры
    cout << "\nИнформация о счете через Get:" << endl;
    cout << "Владелец: " << myAccount.GetOwnerName() << endl;
    cout << "Номер счета: " << myAccount.GetAccountNumber() << endl;
    cout << "Текущий баланс: " << myAccount.GetBalance() << " руб." << endl;
    cout << "Сберегательный тариф: " << (myAccount.GetIsSavings() ? "Да" : "Нет") << endl;

    // Специфичный метод
    cout << "\nОтработка специфичного метода:" << endl;
    myAccount.GetFinancialStatus();

    return 0;
}
