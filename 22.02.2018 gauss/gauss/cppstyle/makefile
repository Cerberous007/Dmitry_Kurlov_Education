OPT=-std=gnu++11 -O0 -Wall -Wextra 

all: main.o parse_opt.o read.o write_ans.o
	g++ $(OPT) main.o parse_opt.o read.o write_ans.o calc.o -o main.exe
main.o: main.cpp gauss.h parse_opt.h
	g++ -c $(OPT) main.cpp -o main.o
parse_opt.o: parse_opt.cpp
	g++ -c $(OPT) parse_opt.cpp -o parse_opt.o
read.o: read.cpp gauss.h
	g++ -c $(OPT) read.cpp -o read.o	
write_ans.o: write_ans.cpp calc.o gauss.h
	g++ -c $(OPT) write_ans.cpp -o write_ans.o
calc.o: calc.cpp gauss.h const.h
	g++ -c $(OPT) calc.cpp -o calc.o
clean:
	rm -f *.o