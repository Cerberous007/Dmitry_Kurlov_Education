all: main.o pw.o prime.o leg_symb.o 
	g++ -g -std=gnu++11 -O0 -Wall -Wextra main.o pw.o prime.o leg_symb.o -o main.exe
main.o: main.cpp func.h
	g++ -g -c -std=gnu++11 -O0 -Wall -Wextra main.cpp -o main.o
pw.o: pw.cpp
	g++ -g -c -std=gnu++11 -O0 -Wall -Wextra pw.cpp -o pw.o
prime.o: prime.cpp
	g++ -g -c -std=gnu++11 -O0 -Wall -Wextra prime.cpp -o prime.o
leg_symb.o: leg_symb.cpp func.h
	g++ -g -c -std=gnu++11 -O0 -Wall -Wextra leg_symb.cpp -o leg_symb.o
clean:
	rm -f *.o