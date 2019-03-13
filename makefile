#simple makefile

CC=g++

SRC=$(wildcard src/*.cpp)
INC= -I include/
OBJ=$(SRC:.cpp=.o)
BUILD= build/

TEST= $(tests.cpp=tests.o)

LDFLAGS=

CCFLAGS =  -g -Wall

interpreter: $(OBJ)
	@echo('elo')
	$(CC) $(CCFLAGS) $(INC)  -o $(BUILD)$@ $^ $(LDFLAGS)

tests: #$(TEST)
	#@echo($(CC) $(CCFLAGS) $(INC) -o $(BUILD)$@ $^ $(LDFLAGS))
	$(CC) $(CCFLAGS) $(INC) -o $(BUILD) $(TEST) $(LDFLAGS)

.PHONY: clean

#clean:
#	rm -f $(obj) myprog












#Tell make to make one .out file for each .cpp file found in the current directory
#all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

#Rule how to create arbitary .out files. 
#First state what is needed for them e.g. additional headers, .cpp files in an include folder...
#Then the command to create the .out file, probably you want to add further options to the g++ call.
#%.out: %.cpp Makefile
#	    g++ $< -o $@ -std=c++11
