#include "Complex.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    Complex a;      // Конструктор по умолчанию
    const Complex b(1, -2);     // Конструктор с параметрами
    std::cout << "Начальное a: ";
    a.Show();

    std::cout << "Введите действительную и мнимую части a через пробел: ";
    if (!(std::cin >> a)) {
        std::cout << "Ошибка: нужно ввести два числа.\n";
        return 1;
    }

    Complex copy(a);    // Конструктор копирования
    Complex assigned;
    assigned = b;   // Оператор присваивания
    std::cout << "a = " << a << "\nb = " << b
              << "\nКопия a: " << copy << "\nПосле присваивания b: "
              << assigned << '\n';

    std::cout << "\na + b = " << (a + b)
              << "\na - b = " << (a - b)
              << "\na * b = " << (a * b)
              << "\na / b = " << (a / b) << '\n';
    copy += b;
    std::cout << "Копия a после += b: " << copy << '\n';

    try {
        std::cout << (a / Complex()) << '\n';
    } catch (const std::domain_error& error) {
        std::cout << error.what() << '\n';
    }

    // Для проверки ++ и -- берём отдельную копию a.
    Complex number(a);
    std::cout << "\n++number: " << ++number << '\n';
    std::cout << "number++: " << number++ << '\n';
    std::cout << "После number++: " << number << '\n';
    std::cout << "--number: " << --number << '\n';
    std::cout << "number--: " << number-- << '\n';
    std::cout << "После number--: " << number << '\n';

    std::cout << "\nСравнение по модулю:\n" << std::boolalpha
              << "a > b: " << (a > b) << '\n'
              << "a < b: " << (a < b) << '\n'
              << "a == b: " << (a == b) << '\n'
              << "a != b: " << (a != b) << '\n';
}
