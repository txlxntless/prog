#pragma once 
#include <iostream> 
#include <string> 

class Subscriber { 
private: 
    std::string* phoneNumber; 
    std::string* fullName; 
    std::string* tariffName; 
    double* monthlyFee; 
    static int objectCount;
public: 
    Subscriber(); 
    Subscriber(const std::string& phone, const std::string& name, const std::string& tariff, double fee);  
    Subscriber(const Subscriber& other);
    Subscriber& operator=(const Subscriber& other);
    ~Subscriber(); 

    void printInfo() const; 
    std::string getFullName() const; 
    std::string getPhoneNumber() const; 

    static int getObjectCount() { return objectCount; }
}; 
