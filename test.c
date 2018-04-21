
//
// test.c
//
// Copyright (c) 2017 JesseChen <lkchan0719@gmail.com>
//

#include <stdio.h>
#include <stdlib.h>
#include "random_p.h"
#include "color.h"

int
main() {
    int arr[] = {1,2,3};
    int freq[] = {0,0,0};
    int i, j, n = 3;
    int c1 = 0, c2 = 0, c3 = 0;

    printf(BOLD("\n\texpect\t") BOLD("\treal") BOLD("\t\tc1") BOLD("\tc2") BOLD("\tc3\n"));
    // loop 10 times, test 10% ~ 100%
    for(i = 0; i <= 10; i++) {
        freq[0] = i;
        freq[1] = (10 - i) % 2;
        freq[2] = 10 - i - freq[1];

        //generate 3 number with given distribution
        for(j = 0; j < 20000; j++) {
            switch(gen_rand_by_prob(arr, freq, n)) {
                case 1: c1++; break;
                case 2: c2++; break;
                case 3: c3++; break;
                default: break;
            }
        }

        printf(COLOR(RED, "\t %d%%"), i * 10);
        printf(COLOR(GREEN, "\t \t%.4f%% "), (c1/20000.0)*100);
        printf("\t %d\t%d\t%d\n",c1,c2,c3);

        c1 = c2 = c3 = 0;
    }

    printf("\n");
    return 0;
}
