OPT=g++ -c -std=gnu++11 -O0 -Wall -Wextra
all: main.o RBset.o operators.o
	g++ main.o RBset.o operators.o -o main.exe
main.o: main.cpp RBset.h operators.h
	$(OPT) main.cpp -o main.o
RBset.o: RBset.cpp RBset.h
	$(OPT) RBset.cpp -o RBset.o
operators.o: operators.cpp operators.h
	$(OPT) operators.cpp -o operators.o
clean:
	rm -f *.o