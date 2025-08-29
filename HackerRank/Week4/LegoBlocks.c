Question: Lego Blocks
You have an infinite number of 4 types of lego blocks of sizes given as (depth x height x width):

d	h	w
1	1	1
1	1	2
1	1	3
1	1	4
Using these blocks, you want to make a wall of height  and width . Features of the wall are:

- The wall should not have any holes in it.
- The wall you build should be one solid structure, so there should not be a straight vertical break across all rows of bricks.
- The bricks must be laid horizontally.

How many ways can the wall be built?


Solution:

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    int maxn = 1000, maxm = 1000;
    static long long row[1001], tot[1001], solid[1001];
    row[0] = 1;
    for (int i = 1; i <= maxm; i++) {
        row[i] = 0;
        for (int j = 1; j <= 4; j++) {
            if (i - j >= 0) row[i] = (row[i] + row[i - j]) % MOD;
        }
    }
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; i++) {
            tot[i] = power(row[i], n);
            solid[i] = tot[i];
            for (int j = 1; j < i; j++) {
                solid[i] = (solid[i] - (solid[j] * tot[i - j]) % MOD + MOD) % MOD;
            }
        }
        printf("%lld\n", solid[m]);
    }
    return 0;
}
