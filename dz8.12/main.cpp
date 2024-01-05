#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;


string encryptCaesarCipher(const string& text, int key) {
    string result = "";

    for (char ch : text) {
        if (isalpha(ch)) {
            char base = (isupper(ch)) ? 'A' : 'a';
            result += static_cast<char>((ch - base + key) % 26 + base);
        }
        else {
            result += ch;
        }
    }

    return result;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string inputFileName = "input.txt";
    string outputFileName = "output.txt";
    int key = 3;  

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

    string line;
    while (getline(inputFile, line)) {
        string encryptedLine = encryptCaesarCipher(line, key);
        outputFile << encryptedLine << endl;
    }

    cout << "Текст зашифровано і записано у файл " << outputFileName << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}