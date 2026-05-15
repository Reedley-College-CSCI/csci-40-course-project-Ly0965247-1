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

const int MAX_SIZE = 50;

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
    cout << "Enter game title: ";
    cin.ignore();
    getline(cin, games[count].title);

    cout << "Enter year made: ";
    cin >> games[count].yearPurchased;

    cout << "Enter the cost: $";
    cin >> games[count].cost;

    cout << "Enter hours played: ";
    cin >> games[count].hoursPlayed;

    cout << "What do you rate this game out of ten?" << endl;
    cin >> games[count].rating;

    if (count < MAX_SIZE) {
        count++;
    }
    else {
        cout << "Game catalog is full. Cannot add more games." << endl;
    }
    saveLog(games, count);
}
void saveLog(GameLog games[], int count) {

    fstream outputFile("GameLogog.txt");

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


int main() {
    GameLog game[MAX_SIZE];
    int gameCount = 0;
    char choice;
    int menuNum;

    cout << "Welcome to your video game log!" << endl;
    // Adding a main menu so that the user can choose to either add a game, print a game log, or seach for a game.
    cout << "Main Menu" << endl << endl;
    cout << "Add game to log (1)" << endl;
    cout << "Search for a game (2)" << endl;
    cout << "Print game logs (3)" << endl;


    // input game data from user

    /*
    while (gameCount < MAX_SIZE) {
        cout << "Do you wish to enter a game into your log? (Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            addGame(game, gameCount);
        }
        else {
            break;
        }
    }

    cout << "Do you wish to print your game log? (Y/N): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
       printLogs();
    }
    */
    return 0;
}
