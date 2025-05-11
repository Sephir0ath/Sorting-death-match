#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <cstdint>
int left(int i);
int right(int i);
int parent(int i);
void swap1(std::vector<int32_t>& array, int a, int b);

void heapify(std::vector<int32_t>& array, int i, int heapSize);
void buildMaxHeap(std::vector<int32_t>& array, int heapSize);
void heapSort(std::vector<int32_t>& array, int heapSize);

#endif
