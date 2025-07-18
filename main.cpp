#include <chrono>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdint>

#include "sorts/heap.h"
#include "sorts/quicksort.h"
#include "sorts/insertion.h"
#include "sorts/mergesort.h"
#include "sorts/merge-insertion.h"

bool checkArrayIsSorted(std::vector<int>& array){
	int prev = array[0];
	for (int i = 1; i < (int)array.size(); i++){
		if (prev > array[i]){
			return false;
		}
		else prev = array[i];
	}
	return true;
}

std::string doSort(int sortValue, std::vector<int32_t>& array){
	switch(sortValue){
		case 0:
			heapSort(array, (int)array.size());
			return "heapSort";
			break;
			
		case 1:
			quickSort(array, 0, (int)array.size() - 1);
			return "quickSort";
			break;
			
		case 2:
			std::sort(array.begin(), array.end());
			return "STL sort";
			break;

		case 3:
			randomizedQuickSort(array, 0, (int)array.size() - 1);
			return "random QuickSort";
            break;

	    case 4:
            mergeInsertionSort(array, 0, (int) array.size() - 1);
			return "MergeInsertion";
            break;

        case 5:
            mergeSort(array, 0, (int) array.size() - 1);
			return "MergeSort";
            break;
    
        case 6:
        	insertionSort(array);
			return "Insertion";            
            break;
		default:
			return "Invalid sort option";
	
    }
}


int main(int argc, char* argv[]){
	srand(time(0));	
	if (argc < 1){
		exit(0);
	}

	std::string filename = argv[1];
	std::ifstream input(filename, std::ios::binary);


	int arraySize = 0;
	if (argc > 3){
		arraySize = atoi(argv[3]);
	}

	// Leer todo el archivo como un solo arreglo
	if (arraySize == 0){
		std::vector<int32_t> array;
		int32_t value;
        while (input.read(reinterpret_cast<char*>(&value), sizeof(value))) {
			array.push_back(value);
		}

		auto start = std::chrono::steady_clock::now();
		
		doSort(atoi(argv[2]), array);
		
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> duration = end - start;
		std::cout << "Tiempo transcurrido: " << duration.count() << " ms" << std::endl;
		
	}

	// Leer todo el archivo como arreglos de tamaño arraySize
	else{
		std::string algo;
		std::vector<int32_t> array(arraySize);
		double sumTime = 0;
		int counter = 0;
		while (input.read(reinterpret_cast<char*>(array.data()), arraySize * sizeof(int32_t))) {
			counter++;
		
			auto start = std::chrono::steady_clock::now();

			algo = doSort(atoi(argv[2]), array);
		
			auto end = std::chrono::steady_clock::now(); 
			std::chrono::duration<double, std::milli> duration = end - start;
			std::cout << "Arreglo " << counter << " - Tiempo transcurrido: " << duration.count() << " ms" << std::endl;		
			sumTime+= duration.count();	
				
		}

		std::cout << "Tiempo promedio: "<< sumTime/counter << std::endl;
		
				
	}
	
	


	srand(time(0));
	


	return 1;
}
