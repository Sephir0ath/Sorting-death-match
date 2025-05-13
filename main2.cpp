#include <chrono>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdint>
#include <omp.h>

#include "sorts/heap.h"
#include "sorts/quicksort.h"
#include "sorts/insertion.h"
#include "sorts/mergesort.h"
#include "sorts/parallelmerge-insertion.h"
#include "sorts/merge-insertion.h"
#include "sorts/timsort.h"


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
		case -1:
			mergeInsertionSortParallel(array, 0, (int) array.size() - 1);
			return "mergeInsertionParallel";
			break;
			
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
			return "QuickSortRandom";
            break;

	    case 4:
            mergeInsertionSort(array, 0, (int) array.size() - 1);
            return "hybridmergeinsertionSort";
            break;

        case 5:
            mergeSort(array, 0, (int) array.size() - 1);
			return "mergesort";
            break;
    
        case 6:
            insertionSort(array);
            return "insertionSort";
            break;

        case 7:
            timSort(array, array.size());
            return "timSort";
            break;

		default:
	       	return "Invalid sort option";

    }
}


int main(int argc, char* argv[]){
	omp_set_num_threads(16);
	if (argc < 1){
		exit(0);
	}

	std::string filename = argv[1];
	std::ifstream input(filename, std::ios::binary);


	int arraySize = 0;
	if (argc > 2){
		arraySize = atoi(argv[2]);
	}

	std::vector<std::vector<int32_t>> array2;
	// Leer todo el archivo como un solo arreglo
	if (arraySize == 0){
		std::vector<int32_t> array;
		int32_t value;
        while (input.read(reinterpret_cast<char*>(&value), sizeof(value))) {
			array.push_back(value);
		}
		// Crear vector con los mismos vectores
		for (int i = -1; i < 6; i++){
			array2.push_back(array);
		}

		// Ejecutar cada sort
		for (int i = -1; i < 7; i++){
			auto start = std::chrono::steady_clock::now();
					
			std::string name = doSort(i, array2[i]);
			
			auto end = std::chrono::steady_clock::now();
			std::chrono::duration<double, std::milli> duration = end - start;
			std::cout << "- " << name <<": " << duration.count() << std::endl;
		}

		
		
	}

	// Leer todo el archivo como arreglos de tama├▒o arraySize
	else{
		#pragma omp parallel for
		for (int i = -1; i < 8; i++){
			std::ifstream input(filename, std::ios::binary);
			std::vector<int32_t> array(arraySize);
			double sumTime = 0;
			int counter = 0;
			std::string name;			
			while (input.read(reinterpret_cast<char*>(array.data()), arraySize * sizeof(int32_t))) {
				counter++;
			
				auto start = std::chrono::steady_clock::now();
	
				name = doSort(i, array);
			
				auto end = std::chrono::steady_clock::now(); 
				std::chrono::duration<double, std::milli> duration = end - start;
				//std::cout << "Arreglo " << counter << " - Tiempo transcurrido: " << duration.count() << " ms" << std::endl;		
				sumTime+= duration.count();	
						
			}
	
			std::cout << "- " << name << ": " << sumTime/counter << std::endl;
		}
		
		
				
	}
	
	


	srand(time(0));
	


	return 1;
}

