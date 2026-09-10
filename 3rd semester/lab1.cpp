#include <iostream>
#include <fstream>   
#include <cstring>   
using namespace std;

struct Table {
    int* Size;       
    char color[20];  
};

void Show(Table t) {
    cout << "Размер стороны: " << *t.Size << ", Цвет: " << t.color << endl;
}

int main() {
    system("chcp 65001 > nul"); 
    setlocale(LC_ALL, ".UTF8");

    // Лабораторная работа
    Table staticTable;
    staticTable.Size = new int; 
    *staticTable.Size = 5;  // Тут 5 потому что в лабораторной не было уточнения сколько делать
    strcpy(staticTable.color, "Коричневый");

    Table* dynamicTable = new Table;
    dynamicTable->Size = new int; 
    *dynamicTable->Size = 12;
    strcpy(dynamicTable->color, "Белый");

    cout << "Одиночные столы из лабораторной работы" << endl;
    Show(staticTable);
    Show(*dynamicTable); 

    delete staticTable.Size;
    delete dynamicTable->Size;
    delete dynamicTable;
    
    // Домашнее задание
    ifstream fileOfTables("tables.txt");
    if (!fileOfTables.is_open()) {
        cout << "\nНе удалось открыть файл tables.txt!" << endl;
        return 1; 
    }

    int count = 0;
    int tempSize;
    char tempColor[20];
    while (fileOfTables >> tempSize >> tempColor) {
        count++;
    }

    cout << "\nСтрок в файле: " << count << endl;

    if (count == 0) {
        cout << "Файл пуст!" << endl;
        fileOfTables.close();
        return 0;
    }

    // Сбрасываем указатель чтения файла в начало
    fileOfTables.clear();                
    fileOfTables.seekg(0, ios::beg);      

    Table* arr = new Table[count];

    for (int i = 0; i < count; i++) {
        arr[i].Size = new int; 
        fileOfTables >> *arr[i].Size >> arr[i].color; 
    }
    fileOfTables.close(); 

    cout << "\nСтолы, объем которых меньше 100" << endl;
    for (int i = 0; i < count; i++) {
        int volume = (*arr[i].Size) * (*arr[i].Size) * (*arr[i].Size);
        if (volume < 100) {
            Show(arr[i]);
        }
    }

    for (int i = 0; i < count; i++) {
        delete arr[i].Size;
    }
    delete[] arr;           
    return 0;
}
