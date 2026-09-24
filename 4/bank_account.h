#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

class BankAccount {
private:
    char* ownerName;      
    int* accountNumber;   
    double* balance;      
    bool* isSavings;      

    void Clear();

public:
    BankAccount();
    BankAccount(const char* newOwner, int newNumber, double newBalance, bool status);
    ~BankAccount();

    bool Init(const char* newOwner, int newNumber, double newBalance, bool status);

    bool SetOwnerName(const char* newOwner);
    const char* GetOwnerName();

    bool SetAccountNumber(int newNumber);
    int GetAccountNumber();

    bool SetBalance(double newBalance);
    double GetBalance();

    void SetIsSavings(bool status);
    bool GetIsSavings();

    void GetFinancialStatus();
};

#endif // BANK_ACCOUNT_H
