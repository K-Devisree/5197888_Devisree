Question: QHEAP1
This question is designed to help you get a better understanding of basic heap operations.

There are  types of query:

" " - Add an element  to the heap.
" " - Delete the element  from the heap.
"" - Print the minimum of all the elements in the heap.
NOTE: It is guaranteed that the element to be deleted will be there in the heap. Also, at any instant, only distinct elements will be in the heap.

Solution:

#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

int heap[MAX], size = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void push(int x) {
    int i = size++;
    heap[i] = x;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] > heap[i]) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void heapify(int i) {
    int l = 2 * i + 1, r = 2 * i + 2, s = i;
    if (l < size && heap[l] < heap[s]) s = l;
    if (r < size && heap[r] < heap[s]) s = r;
    if (s != i) {
        swap(&heap[i], &heap[s]);
        heapify(s);
    }
}

void erase(int x) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == x) {
            heap[i] = heap[--size];
            heapify(i);
            break;
        }
    }
}

int main() {
    int q, t, x;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &x);
            push(x);
        } else if (t == 2) {
            scanf("%d", &x);
            erase(x);
        } else {
            printf("%d\n", heap[0]);
        }
    }
    return 0;
}
