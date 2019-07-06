/*
@author Sandra Shtabnaya

assignment: name surfer
purpose: declares NameSurferEntry, a name entry in database
*/

#ifndef ENTRY_H
#define ENTRY_H
#include <string>
#include <vector>
using namespace std;

class NameSurferEntry {
    friend ostream& operator<<(ostream& out, NameSurferEntry temp);
    public:
        bool operator< (NameSurferEntry left);
        bool operator> (NameSurferEntry left);
        bool operator<= (NameSurferEntry left);
        bool operator>= (NameSurferEntry left);
        bool operator!= (NameSurferEntry left);
        bool operator== (NameSurferEntry left);
        NameSurferEntry();
        NameSurferEntry(string line);
        void setName(string name);
        string getName();
        int getRank(int year);
        bool empty();
        void printRanks();
        string getVisualRank(int year);
       
    private:
        void trim(string& usrStr);
        vector<int> rank;
        string name;
};
#endif /* ENTRY_H */
