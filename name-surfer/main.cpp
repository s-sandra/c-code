/*
@author Sandra Shtabnaya

assignment: name surfer
purpose: creates a NameSurferDataBase and prompts the user for data extraction.
*/

#include "NameSurferDataBase.h"
#include "NameSurferEntry.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

void printMenu();
char getChoice();

int main () {
    NameSurferDataBase names("NamesData.txt");
    printMenu();
    char choice = getChoice();
    
    while (choice != '3') {
        if (choice == '1') { // search by name
            cout << "Enter a name: ";
            string name;
            cin >> name;
            
            NameSurferEntry result = names.findEntry(name);
            if (!result.empty()) { // if the name exists
                cout << result;
            }
            else {
                cout << "Name not found";
            }
        }
        else if (choice == '2') { // search by year
            cout << "Enter a year: ";
            string temp;
            cin >> temp;
            int year;
            year = stoi(temp, nullptr, 0); // converts input to integer
            
            cout << "Enter how many names you want to compare: ";
            cin >> temp;
            int quantity;
            quantity = stoi(temp, nullptr, 0); // converts input to integer
            
            stringstream ss;
            ss << "You selected the decade " << (year / 10) * 10 << endl; 
            for (int i = 1; i <= quantity; i++) {
                cout << "Enter name " << i << ": ";
                string name;
                cin >> name;
                
                if (i == quantity) { // if last name to prompt
                    cout << endl;
                }
                
                NameSurferEntry result = names.findEntry(name);
                ss << left << setw(15) << name;
                if (!result.empty()) { // if the name exists
                    ss << result.getVisualRank(year);
                }
                else {
                    ss << "Name not found" << endl;
                }
            }
            
            string searchResult(ss.str());
            cout << searchResult;
        }
        else {
            cout << "Invalid choice" << endl;
        }
        printMenu();
        choice = getChoice();
    }
    return 0;
}

/*
Prints the menu of choices to the terminal.
*/
void printMenu() {
    cout << endl;
    cout << "1: Enter a name" << endl;
    cout << "2: Enter a year" << endl;
    cout << "3: Exit" << endl;
}

/*
Prompts the user for a choice (1-3) from the menu.

@return the user's choice.
*/
char getChoice() {
    char choice;
    cout << "Enter a choice: ";
    cin >> choice;
    return choice;
}
