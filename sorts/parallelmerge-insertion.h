#ifndef PARALLEL_MERGE_INSERTION_H
#define PARALLEL_MERGE_INSERTION_H

#include <cstdint>
#include <vector>


// -> insertion sort basado en rangos
void rangeBasedInsertionSorta(std::vector<int32_t>& array, int left, int right);

// -> algoritmo de ordenamiento hibrido que combina MergeSort e InsertionSort
void mergeInsertionSortParallel(std::vector<int32_t>& array, int left, int right);


#endif

