all: entrance.o highway.o main.o segment.o toll.o
	g++ entrance.o highway.o main.o segment.o toll.o -o attica

entrance.o: entrance.cc highway.h
	g++ -c entrance.cc

highway.o: highway.cc highway.h
	g++ -c highway.cc

main.o: main.cc highway.h
	g++ -c main.cc

segment.o: segment.cc highway.h
	g++ -c segment.cc

toll.o: toll.cc highway.h
	g++ -c toll.cc

clean:
	rm -rf *.o
	rm -rf attica
