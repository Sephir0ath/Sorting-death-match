SRC_FILES = $(wildcard sorts/*.cpp main2.cpp)  

default:
	g++ -o b $(SRC_FILES) -O3 -fopenmp

