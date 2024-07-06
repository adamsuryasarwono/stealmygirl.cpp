#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void printLyrics() {
    struct Line {
        string text;
        chrono::milliseconds charDelay;
    };

    Line lines[] = {
        {"She's been my queen", chrono::milliseconds(50)},
        {"Since we were sixteen", chrono::milliseconds(50)},
        {"We want the same things", chrono::milliseconds(50)},
        {"We dream the same dreams", chrono::milliseconds(50)},
        {"Alright", chrono::milliseconds(130)},
        {"Alright", chrono::milliseconds(150)},
        {"I got it all", chrono::milliseconds(50)},
        {"'Cause she is the one", chrono::milliseconds(50)},
        {"Her mum calls me love", chrono::milliseconds(50)},
        {"Her dad calls me son", chrono::milliseconds(50)},
        {"Alright", chrono::milliseconds(130)},
        {"Alright", chrono::milliseconds(150)}
    };

    chrono::milliseconds delays[] = {
        chrono::milliseconds(400), chrono::milliseconds(400), chrono::milliseconds(400), chrono::milliseconds(500),
        chrono::milliseconds(1400), chrono::milliseconds(1550), chrono::milliseconds(400), chrono::milliseconds(400), 
        chrono::milliseconds(400), chrono::milliseconds(500), chrono::milliseconds(1400), chrono::milliseconds(1300)
    };

    for (size_t i = 0; i < sizeof(lines) / sizeof(lines[0]); ++i) {
        for (char c : lines[i].text) {
            cout << c << flush;
            this_thread::sleep_for(lines[i].charDelay);
        }
        this_thread::sleep_for(delays[i]);
        cout << endl;
    }
}

int main() {
    printLyrics();
    return 0;
}
