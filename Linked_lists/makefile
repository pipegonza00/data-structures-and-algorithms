CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -pedantic -std=c11

SRC = src/main.c src/linked_list.c
OBJ = $(SRC: .c = .o)

TARGET = Linked_lists
INCLUDE = include

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%o: %c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o Linked_lists