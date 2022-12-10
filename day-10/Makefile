CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -O3

all: day-10

day-10: ex-1/aoc-10.cpp ex-2/aoc-10.cpp
	$(CXX) $(CXXFLAGS) ex-1/aoc-10.cpp -o ex-1/aoc-10
	$(CXX) $(CXXFLAGS) ex-2/aoc-10.cpp -o ex-2/aoc-10

run-ex-1: ex-1/aoc-10
	./ex-1/aoc-10

run-ex-2: ex-2/aoc-10
	./ex-2/aoc-10

clean:
	rm -f ex-1/aoc-10 ex-2/aoc-10