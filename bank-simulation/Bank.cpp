/*
@author Sandra Shtabnaya

assignment: bank simulator
purpose: defines a bank, which contains a queue of customers.
*/

#ifndef BANK_CPP
#define BANK_CPP
#include "Bank.h"
#include <fstream>
#include <iostream>
using namespace std;

/*Creates a bank using customer input from a file. It assumes that the
customers in the file are listed in order, with earliest first.

@param filename the file to read customer information. Outputs file does not exit
if file cannot be found.
*/
Bank::Bank(string filename) {
    ifstream input;
    input.open(filename);
    string line;
    
    if (!input.is_open()) {
        cout << filename << " does not exist." << endl;
        exit(0);
    }
    
    // while there are still lines to be read
    while (!input.eof()) {
        getline(input, line);
        
        if (!line.empty()) {
            Customer person(line);
            customers.push_back(person); // adds customer to vector of bank customers
        }
    }
    
    input.close();
}

/* 
Removes the first customer in the bank's list of customers.
*/
void Bank::removeCustomer() {
    customers.erase(customers.begin());
}

/*
Returns the first customer in the bank's list of customers.
@return the first customer.
*/
Customer Bank::getCustomer() {
    return customers.at(0);
}

/*
Returns whether the bank has any more customers to process.

@return whether the bank's list of customers is empty.
*/
bool Bank::isEmpty() {
    return customers.empty();
}


int Bank::getClosing() {
    return closingTime;
}

int Bank::getOpening() {
    return openingTime;
}

#endif /* BANK_CPP */