CFLAGS=-Wall -Wextra -g

DIJKSTRA=../dijkstra/dijkstra.c

all: init clean main

init: init.c $(DIJKSTRA)
	gcc $^ -o $@ $(LIBS)$(CFLAGS)

clean: clean.c $(DIJKSTRA)
	gcc $^ -o $@ $(LIBS)$(CFLAGS)

main: main.c $(DIJKSTRA)
	gcc $^ -o $@ $(LIBS)$(CFLAGS)
