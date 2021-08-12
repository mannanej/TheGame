// This is TheGame. Yes, that's the title. No, I will not explain. This is my first attempt at building a video game in 
// C++. I have made a few in Java, but I wanted to make a text based adventure. Maybe even make it scary? Who knows.
// So, you shouldn't be reading this! If you are, thanks for reading and maybe playing; how did you get here!?
// Coding and concept created by Eddie Mannan August 2021.

// Just some general imports to make my life easier
#include <windows.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
int textSpeed;

void displayText(std::string line) {

    for (int i = 0; i < line.length(); i++) {
        cout << line.at(i);
        Sleep(textSpeed);
    }
    cout << "\n";
}

int main() {    // START of Code

    textSpeed = 50;
    std::string start;
    boolean begin = false;

    while (!begin) {
        displayText("Would You Like To Play TheGame? ");
        cin >> start;
        if (start == "yes") {

        }
        else if (start == "no") {
            displayText("Very Well");
            Sleep(2000);
            exit(0);
        }
        else if (start == "maybe") {
            displayText("Don't Be A Smartass!");
        }
    }
}
