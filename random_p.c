
//
// random_p.c
//
// Copyright (c) 2017 JesseChen <lkchan0719@gmail.com>
//

#include <stdio.h>
#include <stdlib.h>
#include "random_p.h"


int
find_ceil(int base[], int random, int low, int high) {
    int mid; 

    while(low < high) {
        mid = low + ((high - low) >> 1);
        (random > base[mid]) ? (low = mid + 1) : (high = mid);
    }

    return (base[low] >= random) ? low : -1;
}


/*
 * generate number with specify probability
 */

int
gen_rand_by_prob(int base[], int freq[], int n) {
    int prefix[n];
    int index, random;
    int i;

    prefix[0] = freq[0];
    for(i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] + freq[i];
    }

    random = (rand() % prefix[n-1]) + 1;
    index = find_ceil(prefix, random, 0, n - 1);

    return base[index];
}
