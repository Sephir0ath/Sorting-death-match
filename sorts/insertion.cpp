#include "insertion.h"

void insertionSort(std::vector<int32_t>& array) {
    for (int j = 1; j < (int)array.size(); j++) {
        int32_t key = array[j];
        int i = j - 1;
        
        while (i >= 0 && array[i] > key) {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }
}