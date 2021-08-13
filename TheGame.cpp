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

void displayText(std::string line, int textSpeed, boolean newLine, boolean skipSpace) {

    for (int i = 0; i < line.length(); i++) {
        if (line.at(i) == ' ' && skipSpace) {
            cout << line.at(i);
        }
        else {
            cout << line.at(i);
            Sleep(textSpeed);
        }
    }
    if (newLine) {
        cout << "\n";
    }
    else {
        // Do Nothing
    }
}

void startScreen() {
    int speed = 20;
    displayText("                                        .............      .....   .....      ..............", speed, true, true);
    displayText("                                        .............      .....   .....      ..............", speed, true, true);
    displayText("                                            .....          .....   .....      .....         ", speed, true, true);
    displayText("                                            .....          .............      ..............", speed, true, true);
    displayText("                                            .....          .............      ..............", speed, true, true);
    displayText("                                            .....          .....   .....      .....         ", speed, true, true);
    displayText("                                            .....          .....   .....      ..............", speed, true, true);
    displayText("                                            .....          .....   .....      ..............", speed, true, true);
    displayText("                                                                                            ", speed, true, true);
    displayText("                                                                                            ", speed, true, true);
    displayText("   .............                 ....               .......      .......      ..............", speed, true, true);
    displayText(" ...............                ......              ..... ..    .. .....      ..............", speed, true, true);
    displayText(".....                          ...  ...             .....   .. ..  .....      .....         ", speed, true, true);
    displayText(".....                         ...     ...           .....    ...   .....      ..............", speed, true, true);
    displayText(".....     ..........         ...       ...          .....          .....      ..............", speed, true, true);
    displayText(".....       ........        ...............         .....          .....      .....         ", speed, true, true);
    displayText(".................          ..................       .....          .....      ..............", speed, true, true);
    displayText("  ............            ...              ...      .....          .....      ..............", speed, true, true);
}

int main() {    // START of Code

    std::string start;
    boolean begin = false;

    while (!begin) {
        displayText("Would You Like To Play TheGame? ", 50, true, false);
        cin >> start;
        if (start == "yes") {
            displayText("Downloading\n", 50, false, false);
            startScreen();
            cout << "\n";
            displayText("Download Complete", 50, true, false);
        }
        else if (start == "no") {
            displayText("Very Well", 50, false, false);
            Sleep(2000);
            exit(0);
        }
        else if (start == "maybe") {
            displayText("Don't Be A Smartass!", 50, true, false);
        }
    }
}
