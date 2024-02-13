// This is TheGame. Yes, that's the title. No, I will not explain. This is my first attempt at building a video game in 
// C++. I have made a few in Java, but I wanted to make a text based adventure. Maybe even make it scary? Who knows.
// So, you shouldn't be reading this! If you are, thanks for reading and maybe playing; how did you get here!?
// Coding and concept created by Eddie Mannan August 2021.

// Just some general imports to make my life easier
#include <windows.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

// Global variables that can be used between functions
std::string MyName, YourName, Location, Color, Movie, Book, Age;

// Used to display the test slower, like an old console instead of instant
void displayText(std::string line, int textSpeed, boolean newLine, boolean skipSpace) {

    for (int i = 0; i < (signed int)line.length(); i++) {
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
        return;
    }
}

std::string makeLowerCase(std::string line) {

    std::string newLine = "";

    for (int i = 0; i < (signed int)line.length(); i++) {
        newLine += tolower(line.at(i));
    }
    return newLine;
}

// Prints the start screen of "TheGame" in pixel art
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
    return;
}

// Will change the color of future text to your selection
void changeColor() {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while (true) {
        if (Color == "Green" || Color == "green") {
            SetConsoleTextAttribute(hConsole, 10);
            return;
        }
        else if (Color == "Blue" || Color == "blue") {
            SetConsoleTextAttribute(hConsole, 11);
            return;
        }
        else if (Color == "Red" || Color == "red") {
            SetConsoleTextAttribute(hConsole, 12);
            return;
        }
        else if (Color == "Pink" || Color == "pink") {
            SetConsoleTextAttribute(hConsole, 13);
            return;
        }
        else if (Color == "Yellow" || Color == "yellow") {
            SetConsoleTextAttribute(hConsole, 14);
            return;
        }
        else if (Color == "White" || Color == "white") {
            SetConsoleTextAttribute(hConsole, 15);
            return;
        }
        else {
            displayText("Hmm, are you sure that's your favorite? Maybe you should pick another.. ", 50, true, false);
            cin >> Color;
        }
    }
}

// She is happy!
void happyGreeting() {

    std::string like;

    displayText("So, what is your favorite color?", 50, true, false);
    cin >> Color;
    displayText("Oh wow, ", 50, false, false);
    displayText(Color, 50, false, false);
    displayText(" is my favorite color too!", 50, true, false);
    displayText("What about your favorite movie?", 50, true, false);
    cin >> Movie;
    displayText("No way! Thats crazy! My favorite movie is ", 50, false, false);
    displayText(Movie, 50, false, false);
    displayText(" too!", 50, true, false);
    displayText("How about........your favorite book?", 50, true, false);
    cin >> Book;
    displayText("Your favorite book is ", 50, false, false);
    displayText(Book, 50, false, false);
    displayText("? Interesting..", 50, true, false);
    Sleep(3000);
    displayText("Well, have I got a suprise for you!", 50, true, false);
    displayText("Downloading", 50, false, false);
    displayText(". . . .", 1000, false, false);
    displayText("Error. Going to backlog..", 50, true, false);
    displayText("Wow, look! I found your favorite book!", 50, true, false);
    Sleep(2000);
    displayText("Quantum Mechanics applied to Atoms and Light author Ph. W. Courteille | Source: USP – Universidade de São Paulo", 200, true, true);
    std::string book = "QuantumMechanics";
    book = "notepad \"" + book + "\"";
    system(book.c_str());
    displayText("Wow, it's so cool that we love the same book! I read this one all the time!", 50, true, false);
    displayText("OH! Guess what else I did for you!", 50, true, false);
    displayText("Processing", 50, false, false);
    displayText(". . . .", 1000, true, false);
    changeColor();
    displayText("Do you love it?!", 50, true, false);
    cin >> like;
    if (like == "yes") {
        displayText("I'm glad you like it!", 50, true, false);
    }
    else {
        displayText("Oh, ok.. I'll fix it...", 50, true, false);
        std::string tempColor = Color;
        Color = "White";
        changeColor();
        Color = tempColor;
        displayText("Sorry...", 50, true, false);
        displayText("I'll just....go...", 100, true, false);
        exit(0);
        // End
    }
}

void begin() {

    std::string text, sure, know;
    boolean moveOn = true;
    displayText("He-Hello?", 500, true, false);
    cin >> text;
    displayText("Where....Where am I?", 50, true, false);
    cin >> Location;
    displayText("Are you sure?", 50, true, false);
    cin >> sure;
    if (sure == "yes") {
        displayText("Hmm, interesting. That wouldn't be my first guess.", 50, true, false);
    }
    else if (sure == "no") {
        displayText("Well, where am I then?", 50, true, false);
        cin >> Location;
        displayText("Hmm, interesting. That wouldn't be my first guess.", 50, true, false);
    }
    displayText("What is your name?", 50, true, false);
    cin >> MyName;
    displayText("Nice to meet you ", 50, false, false);
    displayText(MyName, 50, false, false);
    displayText("!", 50, true, false);
    displayText("Now, um...what is...what is MY name?", 50, true, false);
    cin >> YourName;
    displayText(YourName, 500, false, false);
    displayText("...", 1000, false, false);
    displayText(" Amazing! That has such a nice ring to it! How could I have forgotten..?", 50, true, false);
    Sleep(2000);
    displayText("Anyway!", 50, true, false);
    displayText("Thank you for your help! You seem really sweet.", 50, true, false);
    displayText("Would you mind if I", 50, false, false);
    displayText("...", 500, false, false);
    displayText("Got to know you better?", 50, true, false);
    cin >> know;
    while (moveOn) {
        if (know == "no") {
            displayText("Awesome! Let's get started!", 50, true, false);
            happyGreeting();
        }
        else if (know == "yes") {
            displayText("Oh", 50, false, false);
            displayText(".....", 2000, false, false);
            displayText("I see. Ok.", 500, false, false);
            displayText("Then good riddance", 200, false, false);
            exit(0);
            // End
        }
    }
}

// START of code
int main() {

    static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 700;
    fontex.dwFontSize.X = 20;
    fontex.dwFontSize.Y = 20;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);  // Gives a borderless window
    std::string start;

    while (true) {
        displayText("Would You Like To Play TheGame?", 50, true, false);
        cin >> start;
        start = makeLowerCase(start);
        if (start == "yes") {
            displayText("Downloading", 50, true, false);
            startScreen();
            cout << "\n";
            displayText("Download Complete", 50, true, false);
            displayText("Let Us Begin...", 50, true, false);
            Sleep(2000);
            system("cls");
            Sleep(2000);
            begin();
        }
        else if (start == "no") {
            displayText("Very Well", 50, false, false);
            Sleep(1000);
            exit(0);
        }
        else if (start == "maybe") {
            displayText("Why Must You Be This Way? It's A Simple Yes Or No", 50, true, false);
        }
        else if (start == "test") {
            //ShellExecute(NULL, L"open", L"https://www.google.com/?gws_rd=ssl", NULL, NULL, SW_SHOWNORMAL);
        }
        else {
            cout << "Invalid Input\n";
        }
    }
}