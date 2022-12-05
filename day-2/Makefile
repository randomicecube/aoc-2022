CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -O3

all: day-2

day-2: ex-1/aoc-2.cpp ex-2/aoc-2.cpp
	$(CXX) $(CXXFLAGS) ex-1/aoc-2.cpp -o ex-1/aoc-2
	$(CXX) $(CXXFLAGS) ex-2/aoc-2.cpp -o ex-2/aoc-2

run-ex-1: ex-1/aoc-2
	./ex-1/aoc-2

run-ex-2: ex-2/aoc-2
	./ex-2/aoc-2

clean:
	rm -f ex-1/aoc-2 ex-2/aoc-2