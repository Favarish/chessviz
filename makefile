BUILD_FLDR=build/
BIN_FLDR=bin/
TRPO=binFldr buildFldr
CFLAGS = -Wall -Werror -std=c99
CC = gcc
OBJ = $(CC) -c $< -o $@ $(CFLAGS)
MKDIR_BUILD = mkdir -p build/src 

all: $(TRPO) ./bin/main ./bin/chess_test.exe
	
bin/chess_test.exe: ./build/main_test.o ./build/create.o ./build/moving.o ./build/main.o 
	mkdir -p bin
	$(CC) $^ -o $@ $(CFLAGS) 

build/main_test.o: ./test/main.c ./thirdparty/ctest.h ./src/moving.h ./src/create.h
	$(OBJ) -I thirdparty -I src 
	mkdir -p build/test

bin/main: ./build/create.o ./build/moving.o ./build/main.o
	g++ -Werror ./build/create.o ./build/moving.o ./build/main.o -o ./bin/main

build/create.o: ./src/create.cpp ./src/create.h
	g++ -c ./src/create.cpp -o ./build/create.o

build/moving.o: ./src/moving.cpp ./src/moving.h
	g++ -c ./src/moving.cpp -o ./build/moving.o

build/main.o: ./src/main.cpp
	g++ -c ./src/main.cpp -o ./build/main.o

binFldr:
	[ -d $(BIN_FLDR) ] || mkdir $(BIN_FLDR)

buildFldr:
	[ -d $(BUILD_FLDR) ] || mkdir $(BUILD_FLDR)

.PHONY: clean

clean:
	rm -rf build/*.o