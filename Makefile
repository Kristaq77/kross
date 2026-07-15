CC = clang
CFLAGS = -Wall -Wextra -O2 -std=c99
LDFLAGS = -lGL -lglfw -lm
TARGET = build/kross
SRC = main.c

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC) build
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

build:
	mkdir -p build

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build
