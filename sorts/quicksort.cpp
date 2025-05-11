#include "quicksort.h"



void swap2(std::vector<int32_t>& array, int a, int b){
	int aux = array[a];
	array[a] = array[b];
	array[b] = aux;
}

void quickSort(std::vector<int32_t>& array, int p, int r){
	if (p < r){
		int q = partition(array, p, r);
		quickSort(array, p, q - 1);
		quickSort(array, q + 1, r);
	}
}

int partition(std::vector<int32_t>& array, int p, int r){
	int x = array[r];
	int i = p - 1;
	for (int j = p; j < r; j++){
		if (array[j] <= x){
			i++;
			swap2(array, i, j);
		}
	}

	swap2(array, i+1, r);
	return i+1;	
}

// Capítulo 8.3 CLRS
void randomizedQuickSort(std::vector<int32_t>& array, int p, int r){
	if (p < r){
		int q = randomizedPartition(array, p, r);
		randomizedQuickSort(array, p, q - 1);
		randomizedQuickSort(array, q + 1, r);		
	} 
}
int randomizedPartition(std::vector<int32_t>& array, int p, int r){
	srand(time(0));
	int i = rand() % (r - p + 1) + p;
	swap2(array, p, i);
	return partition(array, p, r);
}

