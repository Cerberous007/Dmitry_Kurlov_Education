all: main.o
	g++ -std=gnu++11 -O0 -Wall -Wextra main.o -o main.exe
main.o: main.cpp pair_vectors.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra main.cpp -o main.o
clean:
	rm -f *.o	 