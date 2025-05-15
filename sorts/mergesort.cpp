#include <cstdint>

#include "mergesort.h"

void optimizedMerge(std::vector<int32_t>& array, std::vector<int32_t>& temp, int left, int mid, int right)
{
    if (array[mid] <= array[mid + 1])
    {
        return; 
    }

    for (int i = left; i <= right; i++)
    {
        temp[i] = array[i];
    }

    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (temp[i] <= temp[j]) {
            array[k++] = temp[i++];
        } else {
            array[k++] = temp[j++];
        }
    }

    while (i <= mid) 
    {
        array[k++] = temp[i++];
    }

}

void merge(std::vector<int32_t>& array, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // -> Esto se puede optimizar
    int32_t *L = new int32_t[n1];
    int32_t *R = new int32_t[n2];

    for(int i = 0; i < n1; i++)
    {
        L[i] = array[left + i];
    }

    for(int j = 0; j < n2; j++)
    {
        R[j] = array[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;

}


void mergeSortHelper(std::vector<int32_t>& array, std::vector<int32_t> &temp, int left, int right)
{
    if(left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSortHelper(array, temp, left, mid);
    mergeSortHelper(array, temp, mid + 1, right);
    optimizedMerge(array, temp, left, mid, right);
}

void mergeSort(std::vector<int32_t>& array, int left, int right)
{
    std::vector<int32_t> temp(array.size()); // -> alocación de memoria ocurre una sola vez y no en cada llamada recursiva
    mergeSortHelper(array, temp, left, right);
}



