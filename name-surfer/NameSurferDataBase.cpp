/*
@author Sandra Shtabnaya

assignment: name surfer
purpose: defines NameSurferDataBase, which contains a linked list of 
NameSurferEntry.
*/

#ifndef DATABASE_CPP
#define DATABASE_CPP
#include "NameSurferDataBase.h"
#include <fstream>
using namespace std;

/*
Creates a NameSurferDataBase by reading SSA text file of popular names,
creating NameSurferEntry for all names, and adding those entries to 
database.

@param filename the name of the file that contains popular names and their
ranks per decade (from 1900 to 2010).
*/
NameSurferDataBase::NameSurferDataBase(string filename) {
    ifstream input;
    input.open(filename);
    string line;
    
    if (!input.is_open()) {
        exit(0);
    }
    
    // while there are still lines to be read
    while (!input.eof()) {
        getline(input, line);
        
        if (!line.empty()) {
            NameSurferEntry name(line);
            database.InsertInOrder(name);
        }
    }
    
    input.close();
    // database.PrintAll();
}

/*
Searches for a given name in the database.

@param name the name to search for.
@return the entry that corresponds to the given name. If not found,
returns null.
*/
NameSurferEntry NameSurferDataBase::findEntry(string name) {
    NameSurferEntry entry;
    titlecase(name);
    entry.setName(name);
    database.Search(entry);
    return entry;
}


/*
Converts a given string to titlecase, where the first
letter is capitalized and the rest lowercase. Changes the
string in place.

@param name the string to convert to titlecase.
*/
void NameSurferDataBase::titlecase(string& name) {
    for (int i = 0; i < name.length(); i++) {
        char letter = name.at(i);
        if (i == 0) { // if first letter
            name.at(i) = toupper(letter);
        }
        else {
            name.at(i) = tolower(letter);
        }
    }
}

#endif /* DATABASE_CPP */
