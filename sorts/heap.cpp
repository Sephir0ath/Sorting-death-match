#include "heap.h"
// Implementación basada en el libro Introduction to Algorithms de Thomas H. Cormen


int left(int i){
	return 2*i+1;
}

int right(int i){
	return 2*i+2;
}

int parent(int i){
	return (i-1)/2;
}

void swap1(std::vector<int32_t>& array, int a, int b){
	int aux = array[a];
	array[a] = array[b];
	array[b] = aux;
}

void heapify(std::vector<int32_t>& array, int i, int heapSize){
	int l = left(i);
	int r = right(i);
	int largest = i;
	
	if (l < (int)heapSize && array[l] > array[i]) largest = l;
	
	if (r < (int)heapSize && array[r] > array[largest]) largest = r;

	if (largest != i){
		swap1(array, i, largest);
		heapify(array, largest, heapSize);		
	}
}

void buildMaxHeap(std::vector<int32_t>& array, int heapSize){
	for (int i = (int)array.size()/2 - 1; i >= 0; i--) heapify(array, i, heapSize);	
}

void heapSort(std::vector<int32_t>&array, int heapSize){
	buildMaxHeap(array, heapSize);
	for (int i = (int)heapSize - 1; i > 0; i--){
		swap1(array, 0, i);
		heapSize--;
		heapify(array, 0, heapSize);
	}
}
