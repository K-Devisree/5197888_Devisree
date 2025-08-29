Question: Equal Stacks
You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they are all the same height, then return the height.

Solution:
#include <stdio.h>
#include <stdlib.h>

int main() {
    int nA, nB, nC;
    if (scanf("%d %d %d", &nA, &nB, &nC) != 3) return 0;

    int *u = (int *)malloc(sizeof(int) * nA);
    int *v = (int *)malloc(sizeof(int) * nB);
    int *w = (int *)malloc(sizeof(int) * nC);

    for (int i = 0; i < nA; i++) scanf("%d", &u[i]);
    for (int i = 0; i < nB; i++) scanf("%d", &v[i]);
    for (int i = 0; i < nC; i++) scanf("%d", &w[i]);

    long long s1 = 0, s2 = 0, s3 = 0;
    for (int i = 0; i < nA; i++) s1 += u[i];
    for (int i = 0; i < nB; i++) s2 += v[i];
    for (int i = 0; i < nC; i++) s3 += w[i];

    int i1 = 0, i2 = 0, i3 = 0;

    while (1) {
        if (s1 == s2 && s2 == s3) break;
        if (i1 == nA || i2 == nB || i3 == nC) { s1 = s2 = s3 = 0; break; }
        if (s1 >= s2 && s1 >= s3) s1 -= u[i1++];
        else if (s2 >= s1 && s2 >= s3) s2 -= v[i2++];
        else s3 -= w[i3++];
    }

    printf("%lld\n", s1);

    free(u);
    free(v);
    free(w);
    return 0;
}

