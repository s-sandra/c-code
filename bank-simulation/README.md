# Bank Simulation

## Description
This exercise uses queues to simulate a line at a bank by reading customer information from a file. It outputs a list of activities 
conducted at the bank in the order they occurred, including when a specific customer got in line and when they left. If a customer 
enters the bank before or after it closes, then the simulation indicates that the customer was turned away. Otherwise, all customers 
that remain in line after the closing time are served. Once the simulation is finished, the program calculates the average time spent waiting 
in line for that day.

## File Format
Each line in the file contains the customer’s name, when they arrived (in military time), and how much time they need with the teller (in minutes). 
The lines are listed in order, by arrival time. In this simulation, no two customers can arrive at the same time. Using this information, 
the program then calculates when each customer left the bank. 

## Sample Input
```
Bob 900 1 
Alice 905 2 
James 1656 11 
Jennifer 1705 5
```

## Sample Output
```
Bob got in line at 900
Bob is done at 901
Alice got in line at 905
Alice is done at 907
James got in line at 1650
Jennifer is turned away at 1705
James is done at 1707
Average wait time is 0 minutes
```
