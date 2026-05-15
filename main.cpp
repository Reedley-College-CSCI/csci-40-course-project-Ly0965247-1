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
            cout << "There was an error poening the file." << endl;
        }
    string line;
    while (getline(inFile, line)) {

        cout << line << endl;
    }
}

int main() {
    GameLog game[MAX_SIZE];
    int gameCount = 0;
    char choice;

    cout << "Welcome to your video game log!" << endl;

    // input game data from user

    while (gameCount < MAX_SIZE) {
        cout << "Do you wish to enter a game into your log? (Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            // make addGame function
        }
        else {
            break;
        }
    }
    return 0;
}
