#ifndef MERGESORT_H
#define MERGESORT_H

#include <cstdint>
#include <vector>

// -> version optimizada (usando vector temporal) 
void optimizedMerge(std::vector<int32_t>& array, std::vector<int32_t>& temp, int left, int mid, int right);

// -> versión estándar 
void merge(std::vector<int32_t>& array, int left, int mid, int right);

void mergeSortHelper(std::vector<int32_t>& array, std::vector<int32_t>& temp, int left, int right);

void mergeSort(std::vector<int32_t>& array, int left, int right);



#endif
