Question: Queries with Fixed Length
Consider an -integer sequence, . We perform a query on  by using an integer, , to calculate the result of the following expression:

In other words, if we let , then you need to calculate .

Given  and  queries, return a list of answers to each query.

Solution:

#include <stdio.h>
#include <stdlib.h>

int *arr, *dq;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    dq = (int*)malloc(sizeof(int) * n);
    while (q--) {
        int d;
        scanf("%d", &d);
        int front = 0, back = 0;
        int *mx = (int*)malloc(sizeof(int) * (n - d + 1));
        for (int i = 0; i < n; i++) {
            while (front < back && arr[dq[back - 1]] <= arr[i]) back--;
            dq[back++] = i;
            if (dq[front] <= i - d) front++;
            if (i >= d - 1) mx[i - d + 1] = arr[dq[front]];
        }
        int res = mx[0];
        for (int i = 1; i <= n - d; i++) if (mx[i] < res) res = mx[i];
        printf("%d\n", res);
        free(mx);
    }
    free(arr);
    free(dq);
    return 0;
}
