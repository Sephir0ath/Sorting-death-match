SRC_FILES = $(wildcard sorts/*.cpp main.cpp)  

default:
	@g++ -o main $(SRC_FILES) -O3 -fopenmp

