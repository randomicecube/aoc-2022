CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -O3

all: day-9

day-9: ex-1/aoc-9.cpp ex-2/aoc-9.cpp
	$(CXX) $(CXXFLAGS) ex-1/aoc-9.cpp -o ex-1/aoc-9
	$(CXX) $(CXXFLAGS) ex-2/aoc-9.cpp -o ex-2/aoc-9

run-ex-1: ex-1/aoc-9
	./ex-1/aoc-9

run-ex-2: ex-2/aoc-9
	./ex-2/aoc-9

clean:
	rm -f ex-1/aoc-9 ex-2/aoc-9