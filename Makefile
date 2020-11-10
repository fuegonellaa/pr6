auto: 
	g++ -o pattern_search automaton.cc set.cc main_automaton.cc

doc:
	doxygen

all: auto doc

.PHONY: clean

clean:
	rm -f pattern_search *.o
	rm -rf html latex