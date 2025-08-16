Question: New Year Chaos
It is New Year's Day and people are in line for the Wonderland rollercoaster ride. Each person wears a sticker indicating their initial position in the queue from  to . Any person can bribe the person directly in front of them to swap positions, but they still wear their original sticker. One person can bribe at most two others.

Determine the minimum number of bribes that took place to get to a given queue order. Print the number of bribes, or, if anyone has bribed more than two people, print Too chaotic.

Solution:

#include <stdio.h>

void mb(int q[], int n) {
    int tb = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }

        int start = q[i] - 2 > 0 ? q[i] - 2 : 0;
        for (int j = start; j < i; j++) {
            if (q[j] > q[i]) {
                tb++;
            }
        }
    }

    printf("%d\n", tb);
}

int main() {
    int a;
    scanf("%d", &a);
    while (a--) {
        int n;
        scanf("%d", &n);
        int q[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &q[i]);
        }
        mb(q, n);
    }
    return 0;
}
