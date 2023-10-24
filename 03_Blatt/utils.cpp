#include "utils.hpp"
#include <iostream>


bool isPermutation(const int* perm, int count)
{   
    // TODO: nicht kopieren
    // for 1-n , dann lineare suche
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

bool isSorted(const double* data, int dataCount, const int* perm)
{
    // TODO: nicht kopieren
    // not allowed to copy array.
    auto* maybeSorted = new double[dataCount];
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
