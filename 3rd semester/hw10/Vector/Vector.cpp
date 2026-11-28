#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "Vector.h"

template <typename T> // Конструктор по умолчанию
Vector<T>::Vector() : size_(0), capacity_(0), data_(nullptr) {}

template <typename T> // Деструктор
Vector<T>::~Vector() {
    delete[] data_;
}

template <typename T> // Конструткор копирования
Vector<T>::Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
    if (capacity_ > 0) {
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    } else {
        data_ = nullptr;
    }
}

template <typename T> // Оператр присваивания
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        if (capacity_ > 0) {
            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        } else {
            data_ = nullptr;
        }
    }
    return *this;
}

template <typename T> // Выделяет память под нужное количество элементов
void Vector<T>::reserve(int capacity) {
    if (capacity <= static_cast<int>(capacity_)) return;

    T* new_data = new T[capacity];
    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = capacity;
}

template <typename T> // Добавляет новый элемент в конец
void Vector<T>::push_back(const T& value) {
    if (size_ == capacity_) {
        reserve(capacity_ == 0 ? 2 : capacity_ * 2);
    }
    data_[size_++] = value;
}

template <typename T> // Возвращает первый элемент
T Vector<T>::front() const {
    if (size_ == 0) throw out_of_range("Vector is empty");
    return data_[0];
}

template <typename T> // Возвращает последний элемент
T Vector<T>::back() const {
    if (size_ == 0) throw out_of_range("Vector is empty");
    return data_[size_ - 1];
}

template <typename T> // Возвращает элемент по индексу
T Vector<T>::at(int index) const {
    if (index < 0 || static_cast<size_t>(index) >= size_) {
        throw out_of_range("Index out of range");
    }
    return data_[index];
}

template <typename T> // Дает обращаться к элементам как в обычном массиве
T& Vector<T>::operator[](size_t index) {
    return data_[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return data_[index];
}

template <typename T> // Очищает вектор, тупо обнуляя счетчик элементов
void Vector<T>::clear() {
    size_ = 0;
}

template <typename T> // Возвращает количество элементов
size_t Vector<T>::size() const {
    return size_;
}

template <typename T> // Возвращает вместимость выделенной памяти
size_t Vector<T>::capacity() const {
    return capacity_;
}

// Математические операторы

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const {
    if (size_ != other.size_) {
        throw invalid_argument("Vectors must have the same size for addition");
    }
    Vector<T> result;
    result.reserve(size_);
    for (size_t i = 0; i < size_; ++i) {
        result.push_back(data_[i] + other.data_[i]);
    }
    return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& other) const {
    if (size_ != other.size_) {
        throw invalid_argument("Vectors must have the same size for subtraction");
    }
    Vector<T> result;
    result.reserve(size_);
    for (size_t i = 0; i < size_; ++i) {
        result.push_back(data_[i] - other.data_[i]);
    }
    return result;
}

template <typename T>
T Vector<T>::operator*(const Vector<T>& other) const {
    if (size_ != other.size_) {
        throw invalid_argument("Vectors must have the same size for dot product");
    }
    T dot_product = T();
    for (size_t i = 0; i < size_; ++i) {
        dot_product += data_[i] * other.data_[i];
    }
    return dot_product;
}

// Операторы ввода и вывода

template <typename U>
ostream& operator<<(ostream& os, const Vector<U>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size_; ++i) {
        os << vec.data_[i] << (i + 1 < vec.size_ ? ", " : "");
    }
    os << "]";
    return os;
}

template <typename U>
istream& operator>>(istream& is, Vector<U>& vec) {
    size_t count;
    cout << "Введите количество элементов: ";
    is >> count;
    vec.clear();
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        U val;
        is >> val;
        vec.push_back(val);
    }
    return is;
}

// Специализация string

template <> // Склеивает строки через пробел
inline Vector<string> Vector<string>::operator+(const Vector<string>& other) const {
    if (size_ != other.size_) {
        throw invalid_argument("Vectors must have the same size");
    }
    Vector<string> result;
    result.reserve(size_);
    for (size_t i = 0; i < size_; ++i) {
        result.push_back(data_[i] + " " + other.data_[i]);
    }
    return result;
}

template <> // Если строка из второго вектора находится в первом, то ее вырезают
inline Vector<string> Vector<string>::operator-(const Vector<string>& other) const {
    if (size_ != other.size_) {
        throw invalid_argument("Vectors must have the same size");
    }
    Vector<string> result;
    result.reserve(size_);
    for (size_t i = 0; i < size_; ++i) {
        string str = data_[i];
        size_t pos = str.find(other.data_[i]);
        if (pos != string::npos) {
            str.erase(pos, other.data_[i].length());
        }
        result.push_back(str);
    }
    return result;
}

template <> // Объединяет векторы в одну строку через слово
inline string Vector<string>::operator*(const Vector<string>& other) const {
    if (size_ != other.size_) {
        throw invalid_argument("Vectors must have the same size");
    }
    string result;
    for (size_t i = 0; i < size_; ++i) {
        result += "(" + data_[i] + ":" + other.data_[i] + ") ";
    }
    return result;
}

#endif 
