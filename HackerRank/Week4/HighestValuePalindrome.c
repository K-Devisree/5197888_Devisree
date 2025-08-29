Question: Highest Value Palindrome

Palindromes are strings that read the same from the left or right, for example madam or 0110.

You will be given a string representation of a number and a maximum number of changes you can make. Alter the string, one digit at a time, to create the string representation of the largest number possible given the limit to the number of changes. The length of the string may not be altered, so you must consider 's left of all higher digits in your tests. For example  is valid,  is not.

Given a string representing the starting number, and a maximum number of changes allowed, create the largest palindromic string of digits possible or the string '-1' if it is not possible to create a palindrome under the contstraints.

Solution:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char *num = (char*)malloc(n + 1);
    scanf("%s", num);
    int *changed = (int*)calloc(n, sizeof(int));
    int i, j;
    for (i = 0, j = n - 1; i < j; i++, j--) {
        if (num[i] != num[j]) {
            if (k <= 0) break;
            num[i] = num[j] = (num[i] > num[j]) ? num[i] : num[j];
            changed[i] = changed[j] = 1;
            k--;
        }
    }
    if (i >= j) {
        i = 0; j = n - 1;
        while (i <= j && k > 0) {
            if (i == j) {
                if (num[i] != '9' && k > 0) { num[i] = '9'; k--; }
            } else if (num[i] != '9') {
                if (changed[i] || changed[j]) { num[i] = num[j] = '9'; k--; }
                else if (k >= 2) { num[i] = num[j] = '9'; k -= 2; }
            }
            i++; j--;
        }
        printf("%s\n", num);
    } else printf("-1\n");
    free(num);
    free(changed);
    return 0;
}
