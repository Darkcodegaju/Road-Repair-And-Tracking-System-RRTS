all: administrator.o  clerk.o  mayor.o  resident.o  rrts.o  supervisor.o
	g++ -std=c++11 administrator.o  clerk.o  mayor.o  resident.o  rrts.o  supervisor.o -o rrts
	@echo "Run ./rrts to execute program."
rrts.o: rrts.cpp rrts.h constants.hc
	g++ -std=c++11 -c rrts.cpp -o rrts.o
mayor.o: mayor.cpp mayor.h constants.h
	g++ -std=c++11 -c mayor.cpp -o mayor.o
administrator.o: administrator.cpp administrator.h constants.h supervisor.h supervisor.cpp
	g++ -std=c++11 -c administrator.cpp -o administrator.o
supervisor.o: supervisor.cpp supervisor.h constants.h
	g++ -std=c++11 -c supervisor.cpp -o supervisor.o
resident.o: resident.cpp resident.h constants.h
	g++ -std=c++11 -c resident.cpp -o resident.o
clerk.o: clerk.cpp clerk.h resident.h resident.cpp constants.h
	g++ -std=c++11 -c clerk.cpp -o clerk.o
clean:
	rm -f *.o rrts
