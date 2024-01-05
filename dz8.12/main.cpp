#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string fileName1 = "file1.txt";
    string fileName2 = "file2.txt";

    ifstream file1(fileName1);
    ifstream file2(fileName2);

    if (!file1.is_open() || !file2.is_open()) {
        cout << "Не вдалося відкрити один з файлів." << endl;
        return 1;
    }

    string line1, line2;
    int lineNumber = 0;

    while (getline(file1, line1) && getline(file2, line2)) {
        lineNumber++;

        if (line1 != line2) {
            cout << "Рядок " << lineNumber << " не збігається:" << endl;
            cout << "З файлу " << fileName1 << ": " << line1 << endl;
            cout << "З файлу " << fileName2 << ": " << line2 << endl;
            break; 
        }
    }

    if (file1.eof() && file2.eof()) {
        cout << "Файли ідентичні." << endl;
    }

    file1.close();
    file2.close();

    return 0;
}