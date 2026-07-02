CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -pedantic -std=c11

SRC = src/main.c src/queue.c
OBJ = $(SRC: .c = .o)

TARGET = Queues
INCLUDE = include

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%o: %c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)