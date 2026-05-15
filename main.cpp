// CSCI-40 Final Project
// Author: Lucas Yang

/* 
 * Description:This program will allow the user to be able to track the amount of video games and their titles,
 * how long they have played, the cost of each game, and the rating of the game.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_SIZE = 100;

struct GameLog {
    string title;
    int hoursPlayed;
    int yearPurchased;
    double cost;
    double rating;
};
void printLogs();
void addGame(GameLog games[], int& count);
void saveLog(GameLog games[], int count);
void searchGame(GameLog games[], int count);

void printLogs() {
    // This functions will print the game logs
    ifstream inFile("GameLog.txt");
        if (!inFile) {
            cout << "There was an error opening the file." << endl;
        }
    string line;
    while (getline(inFile, line)) {

        cout << line << endl;
    }
}

void addGame(GameLog games[], int& count) {
    if (count >= MAX_SIZE) {
        cout << "Game log is full. Cannot add more games." << endl;
        return;
    }

    cin.ignore();

    cout << "Enter game title: ";
    getline(cin, games[count].title);

    cout << "Enter year purchased: ";
    cin >> games[count].yearPurchased;

    cout << "Enter the cost: $";
    cin >> games[count].cost;

    cout << "Enter hours played: ";
    cin >> games[count].hoursPlayed;

    cout << "What do you rate this game out of ten?" << endl;
    cin >> games[count].rating;
    
    count++;
    
    saveLog(games, count);
}
void saveLog(GameLog games[], int count) {

    fstream outputFile("GameLog.txt");

    if (!outputFile.is_open()) {
        cout << "Error opening game logs." << endl;
    }
    for (int i = 0; i < count; i++) {
        outputFile << "Title: " << games[i].title << endl;
        outputFile << "Year purchased: " << games[i].yearPurchased << endl;
        outputFile << "Cost: $" << games[i].cost << endl;
        outputFile << "Hours played: " << games[i].hoursPlayed << endl;
        outputFile << "Rating: " << games[i].rating << endl;
        outputFile << "--------------------------" << endl;

    }
    outputFile.close();
}

void searchGame(GameLog games[], int count) {

    string searchGame;

    bool gameFound = false;

    cout << "Enter game title: " << endl;
    cin.ignore();

    getline(cin, searchGame);
    for (int i = 0; i < count; i++) {
        if (games[i].title == searchGame) {
            cout << "Title: " << games[i].title << endl;
            cout << "Year purchased: " << games[i].yearPurchased << endl;
            cout << "Cost: $" << games[i].cost << endl;
            cout << "Hours played: " << games[i].hoursPlayed << endl;
            cout << "Rating: " << games[i].rating << endl;
            cout << "--------------------------" << endl;

            gameFound = true;
        }
    }
    if (!gameFound) {
        cout << "game not found" << endl;
    }
}


int main() {
    GameLog game[MAX_SIZE];
    int gameCount = 0;
    char choice = 'q';
    int menuNum;

    cout << "Welcome to your video game log!" << endl;
    // Adding a main menu so that the user can choose to either add a game, print a game log, or seach for a game.
    cout << "Main Menu" << endl << endl;
    cout << "Add game to log (1)" << endl;
    cout << "Search for a game (2)" << endl;
    cout << "Print game logs (3)" << endl;
    cout << "Quit (4)" << endl;
    
    do {
        cin >> menuNum;
    
        switch (menuNum) {
        case 1:
            addGame(game, gameCount);
            break;
        case 2:
            searchGame(game, gameCount);
            break;
        case 3:
            printLogs();
            break;
        case 4:
            cout << "Goodbye!" << endl;
        }
    } while (menuNum != 4);
    
    return 0;
}
