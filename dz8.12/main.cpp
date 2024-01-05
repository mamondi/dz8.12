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
        cout << "�� ������� ������� ������� ���� " << inputFileName << endl;
        return 1;
    }

    ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        cout << "�� ������� ������� �������� ���� " << outputFileName << endl;
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

    
    outputFile << "ʳ������ �������: " << charCount << endl;
    outputFile << "ʳ������ �����: " << lineCount << endl;
    outputFile << "ʳ������ �������� ����: " << vowelCount << endl;
    outputFile << "ʳ������ ����������� ����: " << consonantCount << endl;
    outputFile << "ʳ������ ����: " << digitCount << endl;

    cout << "���������� �������� � ���� " << outputFileName << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}