PREFIX?=/usr/local
CXXFLAGS=-O3 -march=native -std=c++17 -Wall -Wextra -Werror
binary-sort: binary-sort.cc
clean:
	rm binary-sort
install:
	@echo :: installing 'binary-sort' to $(PREFIX)/bin/
	install -m 755 binary-sort $(PREFIX)/bin/binary-sort

