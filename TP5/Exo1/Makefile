CFLAGS=-Wall -Wextra -g

all: init first second

init: init.c ../dijkstra/dijkstra.c
	gcc $^ -o $@ $(LIBS)$(CFLAGS)

first: first.c ../dijkstra/dijkstra.c
	gcc $^ -o $@ $(LIBS)$(CFLAGS)

second: second.c ../dijkstra/dijkstra.c
	gcc $^ -o $@ $(LIBS)$(CFLAGS)
