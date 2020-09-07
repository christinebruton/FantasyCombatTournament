
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

tourney: main.o Queue.o Stack.o Utilities.o Barbarian.o BlueMen.o HarryPotter.o Medusa.o Vampire.o Character.o
	$(CXX) $(CXXFLAGS) -o tourney main.o Queue.o Stack.o Utilities.o Barbarian.o BlueMen.o HarryPotter.o Medusa.o Vampire.o Character.o 

main.o: main.cpp Queue.h Stack.h Utilities.h Barbarian.h BlueMen.h HarryPotter.h Medusa.h Vampire.h Character.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Queue.o: Queue.h
	$(CXX) $(CXXFLAGS) -c Queue.cpp

Stack.o: Stack.h
	$(CXX) $(CXXFLAGS) -c Stack.cpp

Utilities.o: Utilities.h
	$(CXX) $(CXXFLAGS) -c Utilities.cpp

Barbarian.o: Barbarian.h
	$(CXX) $(CXXFLAGS) -c Barbarian.cpp

BlueMen.o: BlueMen.h
	$(CXX) $(CXXFLAGS) -c BlueMen.cpp

HarryPotter.o: HarryPotter.h
	$(CXX) $(CXXFLAGS) -c HarryPotter.cpp

Medusa.o: Medusa.h
	$(CXX) $(CXXFLAGS) -c Medusa.cpp

Vampire.o: Vampire.h
	$(CXX) $(CXXFLAGS) -c Vampire.cpp

Character.o: Character.h
	$(CXX) $(CXXFLAGS) -c Character.cpp

clean:
	rm -f *o tourney