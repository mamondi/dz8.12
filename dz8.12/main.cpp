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

    const int maxSize = 1000;  
    string lines[maxSize];     

    int lineCount = 0; 

    string line;
    while (getline(inputFile, line) && lineCount < maxSize) {
        lines[lineCount++] = line;
    }

    inputFile.close();

    ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        cout << "Не вдалося відкрити вихідний файл " << outputFileName << endl;
        return 1;
    }

    for (int i = lineCount - 1; i >= 0; --i) {
        outputFile << lines[i] << endl;
    }

    cout << "Результати записані у файл " << outputFileName << endl;

    outputFile.close();

    return 0;
}