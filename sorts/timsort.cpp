#include <vector>
#include <cstdint>
#include <algorithm>

#include "timsort.h"
#include "mergesort.h"
#include "merge-insertion.h"

void timSort(std::vector<int32_t>& array, int n)
{
    const int min_run = 32; // -> tamaño minimo de un run
    
    // -> se ordenan subarrays individuales de tamaño run
    for(int i = 0; i < n; i += min_run)
    {
        rangeBasedInsertionSort(array, i, std::min((i + min_run - 1), (n - 1)));
    }

    // -> se empieza a hacer merge desde size run
    for(int size = min_run; size < n; size = 2 * size)
    {
        for(int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));

            if(mid < right)
            {
                merge(array, left, mid, right);
            }
        }
    }

}

