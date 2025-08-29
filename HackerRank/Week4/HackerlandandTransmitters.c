Question: Hackerland & Transmitters
Hackerland is a one-dimensional city with houses aligned at integral locations along a road. The Mayor wants to install radio transmitters on the roofs of the city's houses. Each transmitter has a fixed range meaning it can transmit a signal to all houses within that number of units distance away.

Given a map of Hackerland and the transmission range, determine the minimum number of transmitters so that every house is within range of at least one transmitter. Each transmitter must be installed on top of an existing house.

Solution:

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(int*)a, y = *(int*)b;
    return (x > y) - (x < y);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    int i = 0, ans = 0;
    while (i < n) {
        ans++;
        int loc = arr[i] + k;
        while (i < n && arr[i] <= loc) i++;
        int pos = arr[i - 1] + k;
        while (i < n && arr[i] <= pos) i++;
    }
    printf("%d\n", ans);
    free(arr);
    return 0;
}

