CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -pedantic -std=c11

SRC = src/main.c src/stack.c
OBJ = $(SRC:.c=.o)

TARGET = stacks

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)