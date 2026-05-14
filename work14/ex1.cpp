#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // 1: поиск цифр в словах
    cout << "Задание 1" << endl;
    // исходная строка
    string text = "Привет, это тест1 и пример сло2в3о с цифрами, а тут 456цифра.";
    string word = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch != ' ' && ch != ',' && ch != '.' && ch != '!' && ch != '?') {
            word = word + ch;
        } 
        else if (word != "") {
            // проверяем, есть ли в этом слове цифры
            int digitCount = 0;
            string foundDigits = "";
            for (int j = 0; j < word.length(); j++) {
                if (word[j] >= '0' && word[j] <= '9') {
                    digitCount++;
                    foundDigits = foundDigits + word[j] + " "; // запоминаем цифру
                }
            }
            // если нашли хотя бы одну цифру, выводим результат
            if (digitCount > 0) {
                cout << "Слово с ошибкой: " << word << endl;
                cout << "Количество цифр: " << digitCount << endl;
                cout << "Что это за цифры: " << foundDigits << endl;
            }
            // сбрасываем слово для следующего шага
            word = "";
        }
    }
    // 2: замена "me" на "you" из файла
    cout << "\nЗадание 2" << endl;
    string fileText = "Hello, this is me. Are you hear me? Give me your hand please.";
    cout << "Исходный текст: " << fileText << endl;
    string target = "me";
    string replacement = "you";
    int pos = fileText.find(target);
    while (pos != string::npos) {
        fileText.replace(pos, target.length(), replacement);
        pos = fileText.find(target, pos + replacement.length());
    }
    cout << "Текст после замены: " << fileText << endl;
    return 0;
}
