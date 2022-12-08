CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -O3

all: day-8

day-8: ex-1/aoc-8.cpp ex-2/aoc-8.cpp
	$(CXX) $(CXXFLAGS) ex-1/aoc-8.cpp -o ex-1/aoc-8
	$(CXX) $(CXXFLAGS) ex-2/aoc-8.cpp -o ex-2/aoc-8

run-ex-1: ex-1/aoc-8
	./ex-1/aoc-8

run-ex-2: ex-2/aoc-8
	./ex-2/aoc-8

clean:
	rm -f ex-1/aoc-8 ex-2/aoc-8