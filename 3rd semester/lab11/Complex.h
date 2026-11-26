#pragma once
#include <iosfwd>

class Complex {
private:
    double real;
    double imag;

    double Abs() const;

public:
    Complex();
    Complex(double real, double imag);
    Complex(const Complex& other);
    ~Complex();

    void Show() const;

    Complex& operator=(const Complex& other);
    Complex& operator+=(const Complex& other);
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);

    bool operator>(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    friend std::istream& operator>>(std::istream& in, Complex& number);
    friend std::ostream& operator<<(std::ostream& out, const Complex& number);
};
