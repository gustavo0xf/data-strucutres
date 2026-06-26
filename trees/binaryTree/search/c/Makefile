CC     = gcc
CFLAGS = -Wall -Wextra -I.

SRC = main.c \
      utils/utils.c \
      utils/print/print.c \
      utils/count/count.c \
      utils/elements/elements.c \
      operations/insert/insert.c \
      operations/search/search.c \
      operations/delete/delete.c

OBJ = $(SRC:.c=.o)
TARGET = bst_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)