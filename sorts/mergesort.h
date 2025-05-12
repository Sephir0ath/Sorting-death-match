#ifndef MERGESORT_H
#define MERGESORT_H

#include <cstdint>
#include <iostream>
#include <vector>

void mergeSort(std::vector<int32_t>& array, int left, int right);

void merge(std::vector<int32_t>& array, int left, int mid, int right);

#endif
