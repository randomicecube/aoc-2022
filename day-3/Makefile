CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -O3

all: day-3

day-3: ex-1/aoc-3.cpp ex-2/aoc-3.cpp
	$(CXX) $(CXXFLAGS) ex-1/aoc-3.cpp -o ex-1/aoc-3
	$(CXX) $(CXXFLAGS) ex-2/aoc-3.cpp -o ex-2/aoc-3

run-ex-1: ex-1/aoc-3
	./ex-1/aoc-3

run-ex-2: ex-2/aoc-3
	./ex-2/aoc-3

clean:
	rm -f ex-1/aoc-3 ex-2/aoc-3