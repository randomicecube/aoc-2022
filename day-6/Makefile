CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -O3

all: day-6

day-6: ex-1/aoc-6.cpp ex-2/aoc-6.cpp
	$(CXX) $(CXXFLAGS) ex-1/aoc-6.cpp -o ex-1/aoc-6
	$(CXX) $(CXXFLAGS) ex-2/aoc-6.cpp -o ex-2/aoc-6

run-ex-1: ex-1/aoc-6
	./ex-1/aoc-6

run-ex-2: ex-2/aoc-6
	./ex-2/aoc-6

clean:
	rm -f ex-1/aoc-6 ex-2/aoc-6