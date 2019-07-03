a.out: bankSimulation.o BankSimulator.o Bank.o Customer.o
	g++ -std=c++11 bankSimulation.o Customer.o Bank.o BankSimulator.o
bankSimulation.o: bankSimulation.cpp BankSimulator.o
	g++ -std=c++11 -c bankSimulation.cpp
BankSimulator.o: Bank.o Customer.o BankSimulator.h BankSimulator.cpp
	g++ -c BankSimulator.cpp
Bank.o: Customer.o Bank.h Bank.cpp
	g++ -c Bank.cpp
Customer.o: Customer.h Customer.cpp
	g++ -c Customer.cpp
clean:
	rm *.o a.out