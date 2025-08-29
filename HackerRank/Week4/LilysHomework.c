Question: Lily's Homework
Whenever George asks Lily to hang out, she's busy doing homework. George wants to help her finish it faster, but he's in over his head! Can you help George understand Lily's homework so she can hang out with him?

Consider an array of  distinct integers, . George can swap any two elements of the array any number of times. An array is beautiful if the sum of  among  is minimal.

Given the array , determine and return the minimum number of swaps that should be performed in order to make the array beautiful.

Solution:

#include <stdio.h>
#include <stdlib.h>

int cmp_asc(const void *a, const void *b) { return (*(int*)a - *(int*)b); }
int cmp_desc(const void *a, const void *b) { return (*(int*)b - *(int*)a); }

int min(int a, int b) { return a < b ? a : b; }

int count_swaps(int *arr, int *sorted, int n) {
    int *visited = (int*)calloc(n, sizeof(int));
    int *pos = (int*)malloc(n * sizeof(int));

    typedef struct { int val; int idx; } Elem;
    Elem *map = (Elem*)malloc(n * sizeof(Elem));
    for (int i = 0; i < n; i++) {
        map[i].val = arr[i];
        map[i].idx = i;
    }
    qsort(map, n, sizeof(Elem), cmp_asc);

    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (map[m].val == sorted[i]) { pos[i] = map[m].idx; break; }
            else if (map[m].val < sorted[i]) l = m + 1;
            else r = m - 1;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] || pos[i] == i) continue;
        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = 1;
            j = pos[j];
            cycle_size++;
        }
        if (cycle_size > 0) res += cycle_size - 1;
    }

    free(pos);
    free(visited);
    free(map);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    int *arr_asc = (int*)malloc(n * sizeof(int));
    int *arr_desc = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr_asc[i] = arr[i];
        arr_desc[i] = arr[i];
    }

    qsort(arr_asc, n, sizeof(int), cmp_asc);
    qsort(arr_desc, n, sizeof(int), cmp_desc);

    int res = min(count_swaps(arr, arr_asc, n), count_swaps(arr, arr_desc, n));
    printf("%d\n", res);

    free(arr);
    free(arr_asc);
    free(arr_desc);
    return 0;
}
