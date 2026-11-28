#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Vector {
private:
    size_t size_;
    size_t capacity_;
    T* data_;

public:
    Vector();
    ~Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);

    void reserve(int capacity);
    void push_back(const T& value);

    T front() const;
    T back() const;
    T at(int index) const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void clear();
    size_t size() const;
    size_t capacity() const;

    // Перегрузка математических операторов
    Vector<T> operator+(const Vector<T>& other) const;
    Vector<T> operator-(const Vector<T>& other) const;
    T operator*(const Vector<T>& other) const;

    // Перегрузка потоков ввода-вывода
    template <typename U>
    friend ostream& operator<<(ostream& os, const Vector<U>& vec);

    template <typename U>
    friend istream& operator>>(istream& is, Vector<U>& vec);
};

// Объявления специализаций для string
template <>
Vector<string> Vector<string>::operator+(const Vector<string>& other) const;

template <>
Vector<string> Vector<string>::operator-(const Vector<string>& other) const;

template <>
string Vector<string>::operator*(const Vector<string>& other) const;

#include "Vector.cpp"

#endif 
