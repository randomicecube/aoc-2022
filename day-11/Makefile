CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -O3

all: day-11

day-11: ex-1/aoc-11.cpp ex-2/aoc-11.cpp
	$(CXX) $(CXXFLAGS) ex-1/aoc-11.cpp -o ex-1/aoc-11
	$(CXX) $(CXXFLAGS) ex-2/aoc-11.cpp -o ex-2/aoc-11

run-ex-1: ex-1/aoc-11
	./ex-1/aoc-11

run-ex-2: ex-2/aoc-11
	./ex-2/aoc-11

clean:
	rm -f ex-1/aoc-11 ex-2/aoc-11