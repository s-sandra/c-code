/*
@author Sandra Shtabnaya

assignment: bank simulator
purpose: declares a bank, which contains a queue of customers.
*/

#ifndef BANK_H
#define BANK_H
#include "Customer.h"
#include <vector>
using namespace std;

class Bank {
    
    public:
        Bank() {};
        Bank(string filename);
        void removeCustomer();
        Customer getCustomer();
        bool isEmpty();
        int getClosing();
        int getOpening();
        
    private:
        vector<Customer> customers;
        int closingTime = 1700; // in military time
        int openingTime = 900; // in military time
};

#endif /*BANK_H*/