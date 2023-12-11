SRC=$(wildcard src/*.cpp)
OBJ_FILE=obj/debug.o
TARGET=bin/debug.exe

LFLAGS=-lmingw32 -Llib -Iinclude -lSDL2main -lSDL2 
FLAGS=-m64
CFLAGS=-Wall

# $^ -> dependencies/src
# $@ -> target

$(TARGET): $(SRC)
	g++ $(CFLAGS) $(FLAGS) $(LFLAGS) -c $^ -o $(OBJ_FILE)
	g++ $(OBJ_FILE) $(CFLAGS) $(FLAGS) $(LFLAGS) -o $@