bool isPermutation(int* perm, int count)
{
    // check if each number from 0 to count-1 is in perm[]
    for (int permutationIndex = 0; permutationIndex < count; ++permutationIndex) {
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (perm[i] == permutationIndex) {
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
    for (int permutationIndex = 1; permutationIndex < dataCount; ++permutationIndex) {
        double lesser = 0;
        double bigger = 0;
        // find which numbers should be at position permutationIndex and permutationIndex-1 in sorted data
        for (int i = 0; i < dataCount; ++i) {
            if (perm[i] == permutationIndex) {
                bigger = data[i]; // number expected to be bigger or equal based on permutation
            }
            if (perm[i] == permutationIndex-1) {
                lesser = data[i]; // number expected to be less or equal based on permutation
            }
        }
        // check if n1 <= n2 <= n3 <= ...
        if (lesser > bigger) {
            return false;
        }
    }
    return true;
}
