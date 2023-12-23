CC = gcc
FILES = main.o op.o todec.o tobase.o
.PHONY: all clean run 
all: calc

calc: $(FILES)
	$(CC) -o calc $(FILES)

main.o: main.c
	$(CC) -c main.c

todec.o: todec.c
	$(CC) -c todec.c

tobase.o: tobase.c
	$(CC) -c tobase.c

op.o: op.c
	$(CC) -c op.c

clean:
	rm -f $(FILES) calc

run: calc
	./calc
