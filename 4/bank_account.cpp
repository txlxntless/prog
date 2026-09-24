#include "bank_account.h"
#include <iostream>
#include <cstring>

using namespace std;

void BankAccount::Clear() {
    delete[] ownerName;
    delete accountNumber;
    delete balance;
    delete isSavings;
    ownerName = nullptr;
    accountNumber = nullptr;
    balance = nullptr;
    isSavings = nullptr;
}

BankAccount::BankAccount() {
    cout << "Конструктор: Создание объекта по умолчанию" << endl;
    ownerName = new char[1]; 
    ownerName[0] = '\0';     
    accountNumber = new int(0);
    balance = new double(0.0);
    isSavings = new bool(false);
}

BankAccount::BankAccount(const char* newOwner, int newNumber, double newBalance, bool status) {
    cout << "Конструктор: Попытка создания объекта с параметрами..." << endl;
    
    ownerName = nullptr;
    accountNumber = nullptr;
    balance = nullptr;
    isSavings = nullptr;

    if (!Init(newOwner, newNumber, newBalance, status)) {
        cout << "[Внимание] Конструктор создал безопасный объект по умолчанию из-за ошибки в параметрах!" << endl;
        ownerName = new char[1]; 
        ownerName[0] = '\0';     
        accountNumber = new int(0);
        balance = new double(0.0);
        isSavings = new bool(false);
    }
}

BankAccount::~BankAccount() {
    cout << "Деструктор: Освобождение динамической памяти объекта" << endl;
    Clear();
}

bool BankAccount::Init(const char* newOwner, int newNumber, double newBalance, bool status) {
    if (newOwner == nullptr || strlen(newOwner) == 0) {
        cout << " Имя владельца не может быть пустым!" << endl;
        return false;
    }
    if (newNumber <= 0) {
        cout << " Номер счета должен быть положительным числом! Указано: " << newNumber << endl;
        return false;
    }
    if (newBalance < 0.0) {
        cout << " Баланс не может быть отрицательным! Указано: " << newBalance << endl;
        return false;
    }

    Clear();

    ownerName = new char[strlen(newOwner) + 1];
    strcpy(ownerName, newOwner);
    
    accountNumber = new int(newNumber);
    balance = new double(newBalance);
    isSavings = new bool(status);

    return true;
}

bool BankAccount::SetOwnerName(const char* newOwner) {
    cout << "Попытка SetOwnerName -> \"" << (newOwner ? newOwner : "NULL") << "\"" << endl;
    return Init(newOwner, *accountNumber, *balance, *isSavings);
}

const char* BankAccount::GetOwnerName() {
    cout << "Применен GetOwnerName" << endl;
    return ownerName;
}

bool BankAccount::SetAccountNumber(int newNumber) {
    cout << "Попытка SetAccountNumber -> " << newNumber << endl;
    return Init(ownerName, newNumber, *balance, *isSavings);
}

int BankAccount::GetAccountNumber() {
    cout << "Применен GetAccountNumber" << endl;
    return *accountNumber; 
}

bool BankAccount::SetBalance(double newBalance) {
    cout << "Попытка SetBalance -> " << newBalance << " руб." << endl;
    return Init(ownerName, *accountNumber, newBalance, *isSavings);
}

double BankAccount::GetBalance() {
    cout << "Применен GetBalance" << endl;
    return *balance;
}

void BankAccount::SetIsSavings(bool status) {
    cout << "Применен SetIsSavings -> " << (status ? "Да" : "Нет") << endl;
    *isSavings = status; 
}

bool BankAccount::GetIsSavings() {
    cout << "Применен GetIsSavings" << endl;
    return *isSavings;
}

void BankAccount::GetFinancialStatus() {
    cout << "Применен метод GetFinancialStatus" << endl;
    if (*balance >= 100000.0) {
        cout << "Финансовый статус: Отличный баланс! Деньги работают на вас." << endl;
    } else if (*balance >= 10000.0) {
        cout << "Финансовый статус: Стабильное положение. Есть базовая подушка безопасности." << endl;
    } else {
        cout << "Финансовый статус: Баланс критически мал. Рекомендуется пополнить счет." << endl;
    }
}
