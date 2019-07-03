/*
@author Sandra Shtabnaya

assignment: bank simulator
purpose: defines a simulator, which conducts simulation of bank transations 
using a queue.
*/

#ifndef SIM_H
#define SIM_H
#include "Bank.h"
#include "Customer.h"
#include <queue>
using namespace std;

class Simulator {
    
    public:
        Simulator();
        void simulate(Bank bank);
        
    private:
        queue<Customer> line;
};

#endif /*BANK_H*/