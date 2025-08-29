Question: The Maximum Subarray
We define subsequence as any subset of an array. We define a subarray as a contiguous subsequence in an array.

Given an array, find the maximum possible sum among:

all nonempty subarrays.
all nonempty subsequences.
Print the two values as space-separated integers on one line.

Note that empty subarrays/subsequences should not be considered.

Solution:

#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int *a = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        int cur = a[0], best = a[0];
        for (int i = 1; i < n; i++) {
            if (cur + a[i] > a[i]) cur += a[i];
            else cur = a[i];
            if (cur > best) best = cur;
        }

        int subseq = a[0], hasPos = 0, posSum = 0, mx = a[0];
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                hasPos = 1;
                posSum += a[i];
            }
            if (a[i] > mx) mx = a[i];
        }
        if (hasPos) subseq = posSum;
        else subseq = mx;

        printf("%d %d\n", best, subseq);
        free(a);
    }
    return 0;
}
