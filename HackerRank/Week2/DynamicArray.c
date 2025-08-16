Question: Dynamic Array
Declare a 2-dimensional array, , of  empty arrays. All arrays are zero indexed.
Declare an integer, , and initialize it to .

There are  types of queries, given as an array of strings for you to parse:

Query: 1 x y
Let .
Append the integer  to .
Query: 2 x y
Let .
Assign the value  to .
Store the new value of  to an answers array.
Note:  is the bitwise XOR operation, which corresponds to the ^ operator in most languages. Learn more about it on Wikipedia.  is the modulo operator.
Finally, size(arr[idx]) is the number of elements in arr[idx]

Solution:
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a;
    scanf("%d%d", &n, &a);

    int *s[n];
    int sz[n];
    for (int i = 0; i < n; i++) {
        s[i] = NULL;
        sz[i] = 0;
    }

    int lastAnswer = 0;

    for (int i = 0; i < a; i++) {
        int type, b, c;
        scanf("%d%d%d", &type, &b, &c);
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            sz[idx]++;
            s[idx] = realloc(s[idx], sz[idx] * sizeof(int));
            s[idx][sz[idx] - 1] = c;
        } else if (type == 2) {
            lastAnswer = s[idx][c % sz[idx]];
            printf("%d\n", lastAnswer);
        }
    }

    for (int i = 0; i < n; i++) {
        free(s[i]);
    }

    return 0;
}
