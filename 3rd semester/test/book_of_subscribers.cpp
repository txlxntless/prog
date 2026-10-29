#include "book_of_subscribers.h"

int Subscriber::objectCount = 0;

Subscriber::Subscriber() { 
    phoneNumber = new std::string(""); 
    fullName = new std::string(""); 
    tariffName = new std::string(""); 
    monthlyFee = new double(0.0); 
    objectCount++;
} 

Subscriber::Subscriber(const std::string& phone, const std::string& name, const std::string& tariff, double fee) { 
    phoneNumber = new std::string(phone); 
    fullName = new std::string(name); 
    tariffName = new std::string(tariff); 
    monthlyFee = new double(fee);
    objectCount++; 
}  

Subscriber::Subscriber(const Subscriber& other) {
    phoneNumber = new std::string(*other.phoneNumber);
    fullName = new std::string(*other.fullName);
    tariffName = new std::string(*other.tariffName);
    monthlyFee = new double(*other.monthlyFee);
}

Subscriber& Subscriber::operator=(const Subscriber& other) {
    if (this != &other) {
        *phoneNumber = *other.phoneNumber;
        *fullName = *other.fullName;
        *tariffName = *other.tariffName;
        *monthlyFee = *other.monthlyFee;
    }
    return *this;
}

Subscriber::~Subscriber() { 
    delete phoneNumber; 
    delete fullName; 
    delete tariffName; 
    delete monthlyFee;
    objectCount--; 
} 

void Subscriber::printInfo() const { 
    std::cout << "Номер телефона: " << *phoneNumber  
    << " ФИО: " << *fullName  
    << " Тариф: " << *tariffName  
    << " Абонентская плата: " << *monthlyFee << " руб.\n"; 
} 

std::string Subscriber::getFullName() const { 
    return *fullName; 
} 

std::string Subscriber::getPhoneNumber() const { 
    return *phoneNumber; 
} 
