CFLAGS=-Wall -Wextra -g

DIJKSTRA=../dijkstra/dijkstra.c

all: init delete clara michjuliette

init: init.c $(DIJKSTRA)
	gcc $^ -o $@ $(LIBS)$(CFLAGS)

delete: delete.c $(DIJKSTRA)
	gcc $^ -o $@ $(LIBS)$(CFLAGS)

clara: clara.c $(DIJKSTRA)
	gcc $^ -o $@ $(LIBS)$(CFLAGS)

michjuliette: michjuliette.c $(DIJKSTRA)
	gcc $^ -o $@ $(LIBS)$(CFLAGS)