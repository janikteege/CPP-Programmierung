#include "utils.hpp"
#include <iostream>


bool isPermutation(int* perm, int count)
{   
    // TODO: nicht kopieren
    int* isPresent = new int[count];
    for (int i = 0; i < count; i++)
    {
        isPresent[i] = 0;
    }
    
    for (int i = 0; i < count; i++)
    {
        isPresent[perm[i]]++;
    }
    for (int i = 0; i < count; i++) {
        if (isPresent[i] != 1) {
            delete[] isPresent;
            return false;
        }
    }
    delete[] isPresent;
    return true;
}

bool isSorted(double* data, int dataCount, int* perm)
{
    // TODO: nicht kopieren
    // not allowed to copy array.
    double* maybeSorted = new double[dataCount];
    for (int i = 0; i < dataCount; i++)
    {
        maybeSorted[i] = 0.0;
    }
    
    for (int i = 0; i < dataCount; i++) {
        maybeSorted[perm[i]] = data[i];
    }
    for (int i = 1; i < dataCount; i++)
    {
        if (maybeSorted[i-1] > maybeSorted[i]) {
            delete[] maybeSorted;
            return false;
        }
    }
    delete[] maybeSorted;
    return true;
}
