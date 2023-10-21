#include <stdio.h>
#include <stdlib.h>
#include "heaplib.h"
int main()
{

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    double freq[] = {0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015626, 0.0078125, 0.0078125};

    int size = sizeof(arr) / sizeof(arr[0]);

    int corr_freq[size];
    for (int i = 0; i < size; i++)
    {
        corr_freq[i] = 1000 * freq[i];
    }

    HuffmanCodes(arr, corr_freq, size);

    return 0;
}
