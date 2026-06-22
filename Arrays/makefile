CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -pedantic -std=c11

SRC = src/main.c src/sorting.c src/searching.c src/statistics.c src/dynamic.c src/menu.c
OBJ = $(SRC: .c = .o)

TARGET = array_tools
INCLUDE = include

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%o: %c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o array_tools