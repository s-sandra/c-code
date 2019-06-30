/*
@author Sandra Shtabnaya

assignment: racko
purpose: runs racko game.
*/

#include "gameController.h"
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    gameController controller;
    controller.displayMenu();
    string choice;
    
    do {
        cout << endl;
        controller.playGame();
        cout << "Would you like to play again? y or n? ";
        cin >> choice;
        controller.toLower(choice);
        while (choice != "y" && choice != "n") {
            cout << "Invalid choice. Enter y or n: ";
            cin >> choice;
            controller.toLower(choice);
        }
    }
    while (choice != "n");
    
    return 0;
}