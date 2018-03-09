OPT=-std=gnu++11 -O0 -Wall -Wextra 

all: main.o parse_opt.o read.o print_ans.o abs.o
	g++ $(OPT) main.o parse_opt.o read.o print_ans.o abs.o -o main.exe
main.o: main.cpp func.h
	g++ -c $(OPT) main.cpp -o main.o
parse_opt.o: parse_opt.cpp
	g++ -c $(OPT) parse_opt.cpp -o parse_opt.o
reading.o: read.cpp func.h
	g++ -c $(OPT) read.cpp -o read.o	
print_ans.o: print_ans.cpp
	g++ -c $(OPT) print_ans.cpp -o print_ans.o
abs.o: abs.cpp
	g++ -c $(OPT) abs.cpp -o abs.o
clean:
	rm -f *.o