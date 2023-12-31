#pragma once
#include <iostream>
// Is the given array a valid permutation?
// This means that every number in [0,count-1] appears exactly once.
bool isPermutation(const int* perm, int count);

// Checks whether data reordered using perm as indicies would be in ascending order.
// Does not change any of the input arrays.
bool isSorted(const double* data, int dataCount, const int* perm);
