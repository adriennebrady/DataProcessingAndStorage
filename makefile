CC = g++
all: main
main: main.o InMemoryDB.o
main.o: main.cpp InMemoryDB.h
InMemoryDB.o: InMemoryDB.cpp InMemoryDB.h
	${CC} -c $< -o $@