#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>
#include <cstdint>
#include <stdlib.h>
#include <ctime>

void swap2(std::vector<int32_t>& array, int a, int b);
void quickSort(std::vector<int32_t>& array, int p, int r);
int partition(std::vector<int32_t>& array, int p, int r);

void randomizedQuickSort(std::vector<int32_t>& array, int p, int r);
int randomizedPartition(std::vector<int32_t>& array, int p, int r);

#endif
