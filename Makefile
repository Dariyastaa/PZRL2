CC = gcc
TARGET = calc
FILES = main.o op.o todec.o tobase.o
.PHONY: all clean run 

all: $(FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(FILES)

main.o: main.c op.h todec.h tobase.h
	$(CC) $(CFLAGS) -c main.c

todec.o: todec.h
	$(CC) $(CFLAGS) -c todec.c

tobase.o: tobase.h
	$(CC) $(CFLAGS) -c tobase.c

op.o: op.h
	$(CC) $(CFLAGS) -c op.c

clean:
	rm -f $(FILES)

run: $(TARGET)
	./$(TARGET)
