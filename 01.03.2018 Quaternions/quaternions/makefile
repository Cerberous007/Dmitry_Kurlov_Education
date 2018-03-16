OPT=g++ -c -std=gnu++11 -O0 -Wall -Wextra

all:main.o quaternions.o func.o
	g++ main.o quaternions.o func.o -o main.exe
main.o:main.cpp func.h quaternions.h
	$(OPT) main.cpp -o main.o
quaternions.o:quaternions.cpp quaternions.h func.h
	$(OPT) quaternions.cpp -o quaternions.o
func.o:func.cpp quaternions.h func.h
	$(OPT) func.cpp -o func.o
clean:
	rm -f *.o
