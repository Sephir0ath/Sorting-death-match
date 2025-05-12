#include <cstdint>

#include "mergesort.h"

void mergeSort(std::vector<int32_t>& array, int left, int right)
{
    if(left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

void merge(std::vector<int32_t>& array, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

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
