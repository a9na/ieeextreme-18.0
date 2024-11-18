#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} Interval;

//  a
//  b
//  p1, p2
//  i1, i2    pomoc
// if multiple, print t1 min, further, print t2 min


// input N, num of substances 
// a and b, interval



/*
#include <stdio.h>
#include <stdlib.h>

// Comparison function
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main() {
   int arr[] = {10, 5, 4, 6, 9};
   int n = sizeof(arr) / sizeof(arr[0]);

   qsort(arr, n, sizeof(int), compare);

   printf("Following is the sorted array: ");
   
   int i;
   for (i = 0; i < n; ++i) {
      printf("%d ", arr[i]);
   }
   printf("\n");
   return 0;
}
*/

int fridgeInterval(const void *p1, const void *p2) {
    Interval *i1 = (Interval *)p1;
    Interval *i2 = (Interval *)p2;
    if (i1->a != i2->a) return i1->a - i2->a;
    return i1->b - i2->b;
}


int main() {
    int N;
    scanf("%d", &N);

    if (N == 0) {
        printf("-1\n");
        return 0;
    }

    Interval intervals[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &intervals[i].a, &intervals[i].b);
    }

    qsort(intervals, N, sizeof(Interval), fridgeInterval);

    int max_b_left = intervals[0].b;
    int min_a_right = intervals[N - 1].a;
    
    
    //int min_b_right = intervals[N - (N - 1)].b;
    
    //printf("%d\n", min_b_right);

    for (int i = 1; i < N; i++) {
        if (intervals[i].a < min_a_right) {
            min_a_right = intervals[i].a;
        }
        if (intervals[i - 1].b > max_b_left) {
            max_b_left = intervals[i - 1].b;
        }

        if (max_b_left < min_a_right) {
            printf("%d %d\n", max_b_left, min_a_right);
            return 0;
        }
    }

    printf("-1");
    return 0;
}
