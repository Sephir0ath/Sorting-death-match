SRC_FILES = $(wildcard sorts/*.cpp main.cpp)  

default:
	@g++ -o a $(SRC_FILES) -O3 -fopenmp

