/*
@author Sandra Shtabnaya

assignment: name surfer
purpose: defines methods for NameSurferEntry, a name entry in database
*/

#ifndef ENTRY_CPP
#define ENTRY_CPP
#include "NameSurferEntry.h"
#include <iostream>
using namespace std;

/*
Creates an empty NameSurferEntry.
*/
NameSurferEntry::NameSurferEntry() {
}

/*
Creates a NameSurferEntry using name data, separated by spaces.

@param line a line for a name from SSA name data text file.
*/
NameSurferEntry::NameSurferEntry(string line) {
    trim(line); // removes excess whitespace
    int spaceIndex = line.find(' ');
    name = line.substr(0, spaceIndex);
    line.erase(0, spaceIndex + 1); // removes name from line
    int rank;
    
    while (line.size() != 0) {
        spaceIndex = line.find(' '); // finds index of next space
        if (spaceIndex != string::npos) { // if space found
            string sRank = line.substr(0, spaceIndex); // extracts name rank
            rank = stoi(sRank, nullptr, 0); // converts rank to base 10 integer
            line.erase(0, spaceIndex + 1); // removes rank from line
        }
        else { // only one rank left
            rank = stoi(line, nullptr, 0);
            line = "";
        }
        this->rank.push_back(rank);
   }
}


/*
Helper function for name data parsing. Updates usrStr in 
place, replacing any sequence of two or more spaces with one space.

@param usrStr the line from SSA name data text file.
*/
void NameSurferEntry::trim(string& usrStr){
    int strLen = usrStr.length();
    int findLoc = usrStr.find("  ");
    while (findLoc != string::npos){
        if(findLoc != strLen - 1){
            usrStr.erase(findLoc, 1);
        }
        findLoc = usrStr.find("  ");
    }
}

/*
Overloads the < operator for NameSurferEntry, comparing by name.

@param the NameSurferEntry to compare with this.
@return whether this is less than parameter.
*/
bool NameSurferEntry::operator< (NameSurferEntry left) {
    return name < left.name;
}

/*
Overloads the > operator for NameSurferEntry, comparing by name.

@param the NameSurferEntry to compare with this.
@return whether this is greater than parameter.
*/
bool NameSurferEntry::operator> (NameSurferEntry left) {
    return name > left.name;
}

/*
Overloads the <= operator for NameSurferEntry, comparing by name.

@param the NameSurferEntry to compare with this.
@return whether this is less than or equal to parameter.
*/
bool NameSurferEntry::operator<= (NameSurferEntry left) {
    return name <= left.name;
}

/*
Overloads the >= operator for NameSurferEntry, comparing by name.

@param the NameSurferEntry to compare with this.
@return whether this is greater than or equal to parameter.
*/
bool NameSurferEntry::operator>= (NameSurferEntry left) {
    return name >= left.name;
}

/*
Overloads the != operator for NameSurferEntry, comparing by name.

@param the NameSurferEntry to compare with this.
@return whether this is not equal to parameter.
*/
bool NameSurferEntry::operator!= (NameSurferEntry left) {
    return left.name != name;
}

/*
Overloads the == operator for NameSurferEntry, comparing by name.

@param the NameSurferEntry to compare with this.
@return whether this is equal to parameter.
*/
bool NameSurferEntry::operator== (NameSurferEntry left) {
    return left.name == name;
}

/*
Outputs to the terminal the ranks of all the decades listed for this 
NameSurferEntry.
*/
void NameSurferEntry::printRanks() {
    for (int year = 1900; year <= 2010; year+=10) {
        cout << year;
        cout << getVisualRank(year);
    }
}

/*
Generates a visual representation of a name's rank
from a given year. Each star represents 1/10 of a rank.

@param year the year of this name's rank.
@return a visual representation of the rank.
*/
string NameSurferEntry::getVisualRank(int year) {
    string result = "";
    int rank = getRank(year);
    for (int stars = rank / 10; stars > 0; stars--) {
        result += "*";
    }
    result += "-";
    if (rank != -1) {
        result += to_string(rank);
    }
    else {
        result += "No data for year ";
        result += to_string(year);
    }
    result += "\n";
    return result;
}


/*
Overloads << operator, allowing a NameSurferEntry to be printed.

@param temp the NameSurferEntry to print
@param out the ostream to print to
@return the ostream pointer
*/
ostream & operator<<(ostream &out, NameSurferEntry temp) {
    out << temp.getName() << endl;
    temp.printRanks();
    out << endl;
    return out;
}

/*
Sets this NameSurferEntry name to the given name.

@param name the name to set
*/
void NameSurferEntry::setName(string name) {
    this->name = name;
}

/*
Gets the name of this NameSurferEntry

@return the name of this NameSurferEntry
*/
string NameSurferEntry::getName() {
    return name;
}

/*
Accesses the rank of the NameSurferEntry's name given the year.

@param the year of the name's rank
@return the rank of the name during that decade. If data for year
has not been gathered, returns -1.
*/
int NameSurferEntry::getRank(int year) {
    if (year >= 2020) {
        return -1;
    }
    return rank.at((year / 10) - 190);
}

/*
Determines whether this NameSurferEntry has any ranks.

@return whether the entry has any ranks.
*/
bool NameSurferEntry::empty() {
    return rank.empty();
}

#endif /* ENTRY_CPP */