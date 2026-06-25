CC     = gcc
CFLAGS = -Wall -Wextra -I.
SRC    = main.c utils/utils.c operations/insert/insert.c operations/delete/delete.c operations/search/search.c
OBJ    = $(SRC:.c=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) *.exe