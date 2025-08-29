Question: Jesse and Cookies
Jesse loves cookies and wants the sweetness of some cookies to be greater than value . To do this, two cookies with the least sweetness are repeatedly mixed. This creates a special combined cookie with:

sweetness  Least sweet cookie   2nd least sweet cookie).

This occurs until all the cookies have a sweetness .

Given the sweetness of a number of cookies, determine the minimum number of operations required. If it is not possible, return .

Solution:

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000005

long long heap_arr[MAXN];
int heap_sz = 0;

void swap_ll(long long *a, long long *b) { long long t = *a; *a = *b; *b = t; }

void sift_up(int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap_arr[parent] > heap_arr[idx]) { swap_ll(&heap_arr[parent], &heap_arr[idx]); idx = parent; }
        else break;
    }
}

void sift_down(int idx) {
    for (;;) {
        int l = 2 * idx + 1, r = 2 * idx + 2, smallest = idx;
        if (l < heap_sz && heap_arr[l] < heap_arr[smallest]) smallest = l;
        if (r < heap_sz && heap_arr[r] < heap_arr[smallest]) smallest = r;
        if (smallest == idx) break;
        swap_ll(&heap_arr[idx], &heap_arr[smallest]);
        idx = smallest;
    }
}

void push_val(long long x) { heap_arr[heap_sz] = x; sift_up(heap_sz++); }

long long pop_min() {
    long long val = heap_arr[0];
    heap_arr[0] = heap_arr[--heap_sz];
    if (heap_sz > 0) sift_down(0);
    return val;
}

int main() {
    int n;
    long long K;
    if (scanf("%d %lld", &n, &K) != 2) return 0;
    for (int i = 0; i < n; i++) {
        long long v; scanf("%lld", &v);
        push_val(v);
    }
    long long ops = 0;
    while (heap_sz > 1 && heap_arr[0] < K) {
        long long a = pop_min();
        long long b = pop_min();
        long long c = a + 2 * b;
        push_val(c);
        ops++;
    }
    if (heap_sz > 0 && heap_arr[0] >= K) printf("%lld\n", ops);
    else printf("-1\n");
    return 0;
}
