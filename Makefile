CC = gcc
TARGET = calc
FILES = main.o op.o todec.o tobase.o
.PHONY: all clean run 

all: $(FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(FILES)

main.o: main.c op.c todec.c tobase.c
	$(CC) $(CFLAGS) -c main.c

todec.o: todec.c
	$(CC) $(CFLAGS) -c todec.c

tobase.o: tobase.c
	$(CC) $(CFLAGS) -c tobase.c

op.o: op.c
	$(CC) $(CFLAGS) -c op.c

clean:
	rm -f $(FILES)

run: $(TARGET)
	./$(TARGET)
