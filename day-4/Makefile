CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -O3

all: day-4

day-4: ex-1/aoc-4.cpp ex-2/aoc-4.cpp
	$(CXX) $(CXXFLAGS) ex-1/aoc-4.cpp -o ex-1/aoc-4
	$(CXX) $(CXXFLAGS) ex-2/aoc-4.cpp -o ex-2/aoc-4

run-ex-1: ex-1/aoc-4
	./ex-1/aoc-4

run-ex-2: ex-2/aoc-4
	./ex-2/aoc-4

clean:
	rm -f ex-1/aoc-4 ex-2/aoc-4