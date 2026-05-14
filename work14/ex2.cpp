#include <iostream>
#include <string>
#include <sstream>   
#include <algorithm>  
using namespace std;

int main() {
    string s = "Do you like programming?";
    // очищаем строку от знаков препинания (заменяем их на пустоту)
    s.erase(remove_if(s.begin(), s.end(), ::ispunct), s.end());
    // используем поток строк, который автоматически режет текст по пробелам
    stringstream ss(s);
    string word = "";
    string maxWord = "";
    while (ss >> word) {
        if (word.length() > maxWord.length()) {
            maxWord = word;
        }
    }
    cout << "Самое длинное слово: " << maxWord << endl;
    return 0;
}
