/*
@author Sandra Shtabnaya

assignment: name surfer
purpose: declares NameSurferDataBase, which contains a linked list of 
NameSurferEntry.
*/
#ifndef DATABASE_H
#define DATABASE_H
#include "NameSurferEntry.h"
#include "linked_list.h"
using namespace std;

class NameSurferDataBase {
    public:
        NameSurferDataBase(string filename);
        NameSurferEntry findEntry(string name);
    private:
        linked_list<NameSurferEntry> database;
        void titlecase(string& name);
};
#endif /* DATABASE_H */
