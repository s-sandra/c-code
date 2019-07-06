a.out: linked_list.o single_node.o main.o NameSurferDataBase.o NameSurferEntry.o
	g++ -std=c++11 main.o linked_list.o single_node.o NameSurferDataBase.o NameSurferEntry.o
main.o: main.cpp NameSurferDataBase.o
	g++ -std=c++11 -c main.cpp
NameSurferDataBase.o: NameSurferDataBase.h NameSurferDataBase.cpp NameSurferEntry.o linked_list.o
	g++ -c NameSurferDataBase.cpp
NameSurferEntry.o: NameSurferEntry.h NameSurferEntry.cpp
	g++ -c NameSurferEntry.cpp
linked_list.o: single_node.o linked_list.cpp linked_list.h
	g++ -c linked_list.cpp
single_node.o: single_node.h single_node.cpp
	g++ -c single_node.cpp
clean:
	rm *.o a.out