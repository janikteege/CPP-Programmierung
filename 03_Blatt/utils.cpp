#include "utils.hpp"
#include <iostream>


bool isPermutation(int* perm, int count)
{
    // for 1-n , dann lineare suche
    for (int i = 0; i < count; ++i) {
        bool found = false;
        for (int j = 0; j < count; ++j) {
            if (perm[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

bool isSorted(double* data, int dataCount, int* perm)
{
    // for 1-n , dann lineare suche
    for (int i = 1; i < dataCount; ++i) {
        int lesser = 0;
        int bigger = 0;
        for (int j = 0; j < dataCount; ++j) {
            if (perm[j] == i) {
                bigger = data[j];
            }
            if (perm[j] == i-1) {
                lesser = data[j];
            }
        }
        if (lesser>bigger) {
            return false;
        }
    }
    return true;
}
