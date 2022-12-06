CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -O3

all: day-n

day-n: ex-1/aoc-n.cpp ex-2/aoc-n.cpp
	$(CXX) $(CXXFLAGS) ex-1/aoc-n.cpp -o ex-1/aoc-n
	$(CXX) $(CXXFLAGS) ex-2/aoc-n.cpp -o ex-2/aoc-n

run-ex-1: ex-1/aoc-n
	./ex-1/aoc-n

run-ex-2: ex-2/aoc-n
	./ex-2/aoc-n

clean:
	rm -f ex-1/aoc-n ex-2/aoc-n