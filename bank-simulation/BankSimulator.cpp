/*
@author Sandra Shtabnaya

assignment: bank simulator
purpose: conducts simulation of bank transations using a queue.
*/

#ifndef SIM_CPP
#define SIM_CPP
#include "BankSimulator.h"
#include <iostream>
#include <iomanip>
using namespace std;

Simulator::Simulator() { }

/*
Outputs activities of bank customers, when they got in line
and when they left.

@param bank the Bank object to simulate.
*/
void Simulator::simulate(Bank bank) {
    int currentTime = bank.getOpening();
    int closingTime = bank.getClosing();
    int totalWait = 0;
    int totalCustomers = 0;
    
    // while it's not the closing time or there are still customers to be serviced,
    while (currentTime <= closingTime || !line.empty()) {
        //cout << "current time: " << currentTime << endl;
        
        // if there are still customers to process
        if (!bank.isEmpty()) {
            Customer person = bank.getCustomer();
            /*cout << person.getName() << " ";
            cout << person.getArrival() << " \n";*/
    
            // checks if earliest customer in bank has arrived
            if (currentTime == bank.getCustomer().getArrival()) {
                
                // checks if customer arrived after closing time
                if (currentTime > closingTime) {
                    cout << person.getName() << " is turned away at " 
                        << currentTime << ".\n";
                }
                else {
                    cout << person.getName() << " got in line at " 
                        << currentTime << ".\n";
                    line.push(person);
                    totalCustomers++;
                }
                bank.removeCustomer();
            }
        }
        
        // checks if first customer in line has left (if line isn't empty)
        if (!line.empty()) {
            
            // if the customer is still at the teller
            if (line.front().getTimeNeeded() != 0) {
                line.front().decTimeNeeded(); // removes one minute from customer process time
            }
            else {
                cout << line.front().getName() << " is done at " << currentTime << ".\n";
                line.pop();
                
                // next person in line gets one minute with teller
                if (!line.empty()) {
                    line.front().decTimeNeeded(); // removes one minute from customer process time
                }
            }
        }
        
        // if last minute in hour
        if ((currentTime + 1) % 100 > 59) {
            currentTime -= 59; // resets minutes
            currentTime += 100; // increment time by one hour
        }
        else {
            currentTime++;
        }
        
        // each person in line counts toward total wait time for all customers,
        // with the exception of the first person in line.
        if (line.size() > 1) {
           totalWait += line.size() - 1; 
        }
    }
    
    cout << setprecision(6);
    cout << "Average wait time is " << (double) totalWait / totalCustomers 
            << " minutes.\n";
}

#endif /* SIM_CPP */