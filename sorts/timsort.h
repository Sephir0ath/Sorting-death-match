#ifndef TIMSORT_H
#define TIMSORT_H

#include <cstdint>
#include <vector>

// timSort es un algoritmo de ordenamiento híbrido que combina mergeSort e InsertionSort
// Obs: La diferncia con mergeInsertionSort es que este considera runs (secuencias ya ordenadas de elementos)
void timSort(std::vector<int32_t>& array, int n);

#endif
