.PHONY: build rebuild clean

rebuild: clean build

clean: 
	rm -f *.o a.out

build: a.out

a.out: main.cpp database.o employee.o
	g++ main.cpp database.o employee.o

database.o: database.cpp database.hpp
	g++ -c database.cpp 

employee.o: employee.cpp employee.hpp
	g++ -c employee.cpp
