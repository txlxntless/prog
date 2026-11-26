#include "Complex.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

Complex::Complex(const Complex& other) : Complex(other.real, other.imag) {}

Complex::~Complex() = default;

void Complex::Show() const {
    std::cout << *this << '\n';
}

Complex& Complex::operator=(const Complex& other) {
    real = other.real;
    imag = other.imag;
    return *this;
}

Complex& Complex::operator+=(const Complex& other) {
    real += other.real;
    imag += other.imag;
    return *this;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    // i * i = -1, поэтому произведение мнимых частей вычитается.
    return Complex(real * other.real - imag * other.imag,
                   real * other.imag + imag * other.real);
}

Complex Complex::operator/(const Complex& other) const {
    if (other.real == 0 && other.imag == 0) {
        throw std::domain_error("Деление на ноль.");
    }

    // Умножаем числитель и знаменатель на сопряжённое число.
    double denominator = other.real * other.real + other.imag * other.imag;
    return Complex((real * other.real + imag * other.imag) / denominator,
                   (imag * other.real - real * other.imag) / denominator);
}

Complex& Complex::operator++() {
    ++real;
    return *this;
}

Complex Complex::operator++(int) {
    // Постфиксная форма возвращает копию до изменения.
    Complex old(*this);
    ++(*this);
    return old;
}

Complex& Complex::operator--() {
    --real;
    return *this;
}

Complex Complex::operator--(int) {
    Complex old(*this);
    --(*this);
    return old;
}

double Complex::Abs() const {
    return std::hypot(real, imag);
}

bool Complex::operator>(const Complex& other) const {
    return Abs() > other.Abs();
}

bool Complex::operator<(const Complex& other) const {
    return Abs() < other.Abs();
}

bool Complex::operator==(const Complex& other) const {
    return Abs() == other.Abs();
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

std::istream& operator>>(std::istream& in, Complex& number) {
    double real, imag;
    if (in >> real >> imag) {
        number = Complex(real, imag);
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Complex& number) {
    return out << number.real << (std::signbit(number.imag) ? "-" : "+")
               << std::abs(number.imag) << "*i";
}
