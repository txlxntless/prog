#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

bool compareByLength(const string& a, const string& b) {
    return a.length() < b.length();
}

int main() {
    string s[3];
    s[0] = "Do you like programming?";
    s[1] = "I love programming!";
    s[2] = "But sometimes I lose my head from love.";
    sort(s, s + 3, compareByLength);
    cout << "Предложения по возрастанию длины:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << s[i] << " (Длина: " << s[i].length() << ")" << endl;
    }
    return 0;
}
