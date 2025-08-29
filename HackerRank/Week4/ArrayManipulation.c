Question: Array Manipulation
Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.

Solution:

#include <stdio.h>
#include <stdlib.h>

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    long long *arr = (long long*)calloc(n + 2, sizeof(long long));
    for (long long i = 0; i < m; i++) {
        long long a, b, k;
        scanf("%lld %lld %lld", &a, &b, &k);
        arr[a] += k;
        if (b + 1 <= n) arr[b + 1] -= k;
    }
    long long max = 0, sum = 0;
    for (long long i = 1; i <= n; i++) {
        sum += arr[i];
        if (sum > max) max = sum;
    }
    printf("%lld\n", max);
    free(arr);
    return 0;
}
