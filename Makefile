# ALWAYS make sure you use optimization flags, -O2 or -O3 are a must.
# Make sure you have GLFW installed.
CC = clang
CFLAGS = -Wall -Wextra -O2
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
