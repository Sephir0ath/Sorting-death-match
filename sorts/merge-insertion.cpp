#include <iostream>
#include <cstdint>
#include <vector>

#include "merge-insertion.h"
#include "mergesort.h"


void rangeBasedInsertionSort(std::vector<int32_t>& array, int left, int right)
{
    for(int j = left + 1; j <= right; j++)
    {
        int32_t key = array[j];
        int i = j - 1;

        // -> se utiliza el rango [left, right] para la comparación
        while(i >= left && array[i] > key)
        {
            array[i + 1] = array[i];
            i--;
        }

        array[i + 1] = key;


    }

}

void mergeInsertionSort(std::vector<int32_t>& array, int left, int right)
{
    // -> 32 es un tamaño arbitrario a partir del cual se utiliza insertion sort (usualmente entre 16 y 64)
    if(right - left + 1 <= 32)
    {
        // -> si tamaño del array es igual o menor a 32, se utiliza insertion sort
        rangeBasedInsertionSort(array, left, right);
        return;
    }

    // -> si tamaño del array es mayor a 32, se utiliza merge sort
    int mid = (left + right) / 2;
    mergeInsertionSort(array, left, mid);
    mergeInsertionSort(array, mid + 1, right);
    merge(array, left, mid, right);
    
}

