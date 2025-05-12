#ifndef MERGE_INSERTION_H
#define MERGE_INSERTION_H

#include <cstdint>
#include <vector>


// -> insertion sort basado en rangos
void rangeBasedInsertionSort(std::vector<int32_t>& array, int left, int right);

// -> algoritmo de ordenamiento hibrido que combina MergeSort e InsertionSort
void mergeInsertionSort(std::vector<int32_t>& array, int left, int right);


#endif
