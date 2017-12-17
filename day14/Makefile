all: main.o knoth.o
	@g++ -std=c++11 main.o knoth.o -o exe

main.o: main.cpp
	@g++ -std=c++11 -c -o $@ $<

knoth.o: knoth.cpp knoth.h
	@g++ -std=c++11 -c -o $@ $<

clean:
	@rm -f exe *.o
