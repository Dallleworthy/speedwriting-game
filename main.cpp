#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;
using namespace std::chrono;

void CreateFile();
void GameLogic();

int main() {
    cout << "Введи 1 чтобы начать, 2 чтобы создать словарь со своими словами, 3 - выйти." << endl;
    int way;
    cin >> way;
    switch (way) {
        case 1:
            GameLogic();
            break;
        case 2:
            CreateFile();
            break;
        default:
            return 0;
    }
}

void CreateFile() {
     ofstream MyFile("file");
     string newords;
     cout << "Введите новые строки ('END', чтобы завершить):" << endl;
     cin.ignore();
     while (true) {
         getline(cin, newords);
         if (newords == "END") {
             break;
         }
         MyFile << newords << endl;
     }
     cout << "Данные успешно записаны в 'file'" << endl;
     MyFile.close();
}

void GameLogic() {
    vector<string> wordsVector;
    string words;

    ifstream MyReadFile("file");
    while (getline (MyReadFile, words)) {
        wordsVector.push_back(words);
    }

    auto start = high_resolution_clock::now();
    int score = 0;

    for (const auto& programInput : wordsVector) {
        string userInput;

        cout << "Введи: " << programInput << endl;
        cin >> userInput;

        if (userInput == programInput) {
            score++;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Ты справился за: " << duration.count() << " мс" <<  endl << "Твой счет: " << score << endl;

    MyReadFile.close();
    main();
}
