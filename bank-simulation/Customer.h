/*
@author Sandra Shtabnaya

assignment: bank simulator
purpose: declares a customer in a bank.
*/

#ifndef CUST_H
#define CUST_H
#include <string>
using namespace std;

class Customer {
    public:
        Customer();
        Customer(string line);
        bool operator== (Customer other);
        int getWaitTime();
        string getName();
        int getArrival();
        int getTimeNeeded();
        void decTimeNeeded();
        int getProcessing();
        
    private:
        void trim(string& usrStr);
        int arrival; // when customer arrived, in military time
        int processing; // the total amount of time customer needs with the teller, in minutes
        int timeNeeded; // how much time customer has left to spend with teller, in minutes
        string name;
};

#endif /* CUST_H */