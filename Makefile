INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := customErrorClass.o UnionFind.o main.o
DEPS 		 := ${INCLUDE_DIRS}/customErrorClass.h UnionFind.h

.PHONY: clean all

all: union customErrorClass.o UnionFind.o main.o

clean:
	rm $(OBJS) union

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

UnionFind.o: UnionFind.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

main.o: main.cpp
	$(CC) -c -o $@ $(CFLAGS) $<

union: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)