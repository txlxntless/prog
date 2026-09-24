#include <iostream>
#include "bank_account.cpp"

using namespace std;

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, ".UTF8");

    cout << "Создание некорректного объекта" << endl;
    BankAccount* badAccount = new BankAccount("Нелегал", -555, -100.0, false);
    cout << "Баланс созданного badAccount: " << badAccount->GetBalance() << " руб.\n" << endl;
    delete badAccount;

    cout << "Создание корректного объекта" << endl;
    BankAccount* myAccount = new BankAccount("Себастьян", 12345678, 250000.50, true);

    cout << "\nПроверка методов Set с валидацией" << endl;
    
    if (myAccount->SetBalance(50000.0)) {
        cout << "Успешно: Баланс изменен." << endl;
    } else {
        cout << "Ошибка: Изменить баланс не удалось." << endl;
    }

    if (myAccount->SetAccountNumber(-777)) {
        cout << "Успешно: Номер счета изменен." << endl;
    } else {
        cout << "Ошибка: Номер счета отклонен системой валидации." << endl;
    }

    cout << "\nИтоговая информация о счете" << endl;
    cout << "Владелец: " << myAccount->GetOwnerName() << endl;
    cout << "Номер счета: " << myAccount->GetAccountNumber() << endl;
    cout << "Текущий баланс: " << myAccount->GetBalance() << " руб." << endl;
    
    myAccount->GetFinancialStatus();

    delete myAccount;
    return 0;
}
