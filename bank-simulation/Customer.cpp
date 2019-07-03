/*
@author Sandra Shtabnaya

assignment: bank simulator
purpose: defines a customer in a bank.
*/

#ifndef CUST_CPP
#define CUST_CPP
#include "Customer.h"
#include <iostream>
using namespace std;


/*
Creates a customer using a line from input file.

@param line the line containing the customer's name, arrival time,
and time required with the teller.
*/
Customer::Customer(string line) {
    trim(line); // removes excess whitespace
    int spaceIndex = line.find(' ');
    name = line.substr(0, spaceIndex);
    line.erase(0, spaceIndex + 1); // removes name from line
    
    while (line.size() != 0) {
        spaceIndex = line.find(' '); // finds index of next space
        if (spaceIndex != string::npos) { // if space found
            string sArr = line.substr(0, spaceIndex); // extracts arrival time
            arrival = stoi(sArr, nullptr, 0); // converts time to base 10 integer
            line.erase(0, spaceIndex + 1); // removes arrival time from line
        }
        else { // only processing time left
            processing = stoi(line, nullptr, 0);
            timeNeeded = processing;
            line = "";
        }
   }
}

/*
Defines how customers are to be compared on equality.

@param other the customer to compare to this customer.
@return whether the other customer is equivalent to this
customer.
*/
bool Customer::operator == (Customer other) {
	return name == other.getName() && 
	       arrival == other.getArrival() && 
	       processing == other.getProcessing();
}

/*
Helper function for customer parsing. Updates usrStr in 
place, replacing any sequence of two or more spaces with one space.

@param usrStr the line from bank simulation file.
*/
void Customer::trim(string& usrStr){
    int strLen = usrStr.length();
    int findLoc = usrStr.find("  ");
    while (findLoc != string::npos){
        if(findLoc != strLen - 1){
            usrStr.erase(findLoc, 1);
        }
        findLoc = usrStr.find("  ");
    }
    
    strLen = usrStr.length();
    
    // removes trailing whitespace
    if (strLen > 1) {
        if(usrStr.at(strLen - 1) == ' ') {
            usrStr.pop_back();
        }
    }
    
}

string Customer::getName() {
    return name;
}

int Customer::getArrival() {
    return arrival;
}

/*
@return the total amount of time (in minutes) the customer needs with the teller.
*/
int Customer::getProcessing() {
    return processing;
}

/* 
Returns how much time (in minutes) the customer has left with the teller. This 
amount changes throughout the bank simulation.

@return the current amount of time the customer needs with the teller.
*/
int Customer::getTimeNeeded() {
    return timeNeeded;
}


/*
Decrements the amount of time the customer needs with the teller,
by one minute.
*/
void Customer::decTimeNeeded() {
    timeNeeded--;
}

#endif /* CUST_CPP */