CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -I sorting 

# The final executable
TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.c sorting/bubble.h
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
