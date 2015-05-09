#include <stdio.h>

int isHappy(int n) {
    int mod = 0;
    int new_sum = n;
    int route[1000] = {0};
    int sqr[10] = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };

    while ( new_sum > 1 ) {
        n = new_sum;
        new_sum = 0;
        while ( n > 0 ) {
            mod = n % 10;
            new_sum += sqr[mod];
            n = (n - mod) / 10;
        }
        if ( route[new_sum] == 1 ) {
            return -1;
        } else {
            route[new_sum] = 1;
        }
    }
    if ( new_sum == 1 ) {
        return 1;
    }
    return -1;
}

int main(void)
{
    int j = 0;

    for (j = 0; j < 1000; j++) {
        int i = 0;

        for ( i = 0 ; i < 30 ; i++ ) {
            //printf("%s\n", isHappy(i) > 0 ? "true" : "false");
            isHappy(i);
        }
        for ( i = 999500 ; i < 999999 ; i++ ) {
            //printf("%s\n", isHappy(i) > 0 ? "true" : "false");
            isHappy(i);
        }
    }

    return 0;
}
