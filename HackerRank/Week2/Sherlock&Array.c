Question: Sherlock&Array
Watson gives Sherlock an array of integers. His challenge is to find an element of the array such that the sum of all elements to the left is equal to the sum of all elements to the right.

Solution:

#include <stdio.h>

const char* bs(int ar[], int n) {
    int ts = 0;
    for (int i = 0; i < n; i++) {
        ts += ar[i];
    }

    int ls = 0;
    for (int i = 0; i < n; i++) {
        if (ls == ts - ls - ar[i]) {
            return "YES";
        }
        ls += ar[i];
    }
    return "NO";
}

int main() {
    int a;
    scanf("%d", &a);

    while (a--) {
        int n;
        scanf("%d", &n);
        int ar[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &ar[i]);
        }
        printf("%s\n", bs(ar, n));
    }

    return 0;
}
