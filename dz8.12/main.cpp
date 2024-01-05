#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        cout << "Не вдалося відкрити вхідний файл " << inputFileName << endl;
        return 1;
    }

    ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        cout << "Не вдалося відкрити вихідний файл " << outputFileName << endl;
        return 1;
    }

    string word;
    while (inputFile >> word) {
        while (!word.empty() && ispunct(word.back())) {
            word.pop_back();
        }

        if (word.length() >= 7) {
            outputFile << word << " ";
        }
    }

    cout << "Операція завершена успішно. Результати записані у файл " << outputFileName << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}