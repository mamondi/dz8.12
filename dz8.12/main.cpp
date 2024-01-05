#include <iostream>
#include <fstream>
#include <cctype>
#include <Windows.h>

using namespace std;

int main() {
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

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    char ch;

    while (inputFile.get(ch)) {
        charCount++;

        if (ch == '\n') {
            lineCount++;
        }
        else if (isalpha(ch)) {
            ch = tolower(ch);

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            }
            else {
                consonantCount++;
            }
        }
        else if (isdigit(ch)) {
            digitCount++;
        }
    }

    
    outputFile << "Кількість символів: " << charCount << endl;
    outputFile << "Кількість рядків: " << lineCount << endl;
    outputFile << "Кількість голосних букв: " << vowelCount << endl;
    outputFile << "Кількість приголосних букв: " << consonantCount << endl;
    outputFile << "Кількість цифр: " << digitCount << endl;

    cout << "Статистика записана у файл " << outputFileName << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}