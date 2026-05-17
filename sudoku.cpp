#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

const int N = 9;

void drawBoard(int board[N][N]) {  // выводит красивую сетку с разделителями для блоков
    cout << "\n    1 2 3   4 5 6   7 8 9" << endl;
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0) cout << "  -----------------------" << endl;
        cout << i + 1 << " | ";
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) cout << ". ";
            else cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) cout << "| ";
        }
        cout << endl;
    }
    cout << "  -----------------------" << endl;
}

bool isSafe(int board[N][N], int row, int col, int num) {  // проверяет три правила судоку (строка, столбец, квадрат)
    for (int x = 0; x < N; x++)
        if (board[row][x] == num || board[x][col] == num) return false;
    int sR = row - row % 3, sC = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + sR][j + sC] == num) return false;

    return true;
}

// Проверка: заполнено ли поле полностью и правильно
bool isSolved(int board[N][N]) {  // сканирует поле, если пустых клеток нет и правила не нарушены — игра заканчивается
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) return false;
            // Проверяем текущее число на соответствие правилам
            int temp = board[i][j];
            board[i][j] = 0; // Временно убираем для проверки
            bool safe = isSafe(board, i, j, temp);
            board[i][j] = temp; // Возвращаем
            if (!safe) return false;
        }
    }
    return true;
}

bool fillBoard(int board[N][N]) {  // использует рекурсию: находит пустую клетку, ставит туда случайное число и пытается заполнить остальное поле, если зашел в тупик — возвращается назад (отменяет ход) и пробует другое число
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                vector<int> nums = {1,2,3,4,5,6,7,8,9};
                static mt19937 g(static_cast<uint32_t>(time(0))); // mt19937 использован для качественного перемешивания чисел при генерации
                shuffle(nums.begin(), nums.end(), g);  // чтобы каждая новая игра была уникальной, список чисел перед проверкой перемешивается
                for (int num : nums) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (fillBoard(board)) return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void removeDigits(int board[N][N], int count) {  // после того как поле полностью заполнено, стираем случайные ячейки
    while (count > 0) {
        int cellId = rand() % 81;
        int r = cellId / 9, c = cellId % 9;
        if (board[r][c] != 0) {
            board[r][c] = 0;
            count--;
        }
    }
}

int main() {  // содержит игровой цикл, принимает координаты и обновляет поле
    srand(time(0));
    int board[N][N] = {0};

    cout << "Генерация новой игры..." << endl;
    fillBoard(board);
    removeDigits(board, 40); // 40 — уровень сложности

    int r, c, val;
    while (true) {
        drawBoard(board);
    
        if (isSolved(board)) {
            cout << "\nПОБЕДА! Вы полностью решили Судоку!" << endl; // при условии, что заполнили последнюю клетку правильно, программа выведет поздравление
            break;
        }
        cout << "Ввод (строка столбец число) или 0 0 0 для выхода: ";
        if (!(cin >> r >> c >> val)) break;
        if (r == 0) break;
        r--; c--;
        if (r >= 0 && r < N && c >= 0 && c < N && val >= 1 && val <= 9) {
            if (isSafe(board, r, c, val)) board[r][c] = val;
            else cout << "!! Ошибка: это число здесь ставить нельзя!" << endl;
        } else {
            cout << "!! Некорректные координаты или значение!" << endl;
        }
    }
    return 0;
}
