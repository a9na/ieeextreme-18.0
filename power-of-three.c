#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    unsigned long long N;
    scanf("%llu", &N);
    
    if (N == 1) {
        printf("0\n");  
        return 0;
    }

    unsigned long long power = 1;
    int x = 0;
    
    while (power < N) {
        power *= 3;
        x++;
    }
    
    if (power == N) {
        printf("%d\n", x);
    } else {
        printf("-1\n");
    }
    
    return 0;
}
