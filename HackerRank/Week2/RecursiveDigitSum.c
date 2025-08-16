Question: RecursiveDigitsum
We define super digit of an integer  using the following rules:

Given an integer, we need to find the super digit of the integer.

If  has only  digit, then its super digit is 9875.
Otherwise, the super digit of  is equal to the super digit of the sum of the digits of .
For example, the super digit of  will be calculated as:

	super_digit(9875)   	9+8+7+5 = 29 
	super_digit(29) 	2 + 9 = 11
	super_digit(11)		1 + 1 = 2
	super_digit(2)		= 2  

Solution:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sdh(long long n) {
    if (n < 10) {
        return n;
    }
    long long s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return sdh(s);
}

int sd(char n[], int a) {
    long long s = 0;
    int len = strlen(n);
    for (int i = 0; i < len; i++) {
        s += n[i] - '0';
    }
    s *= a;
    return sdh(s);
}

int main() {
    char n[100001];
    int a;
    scanf("%s %d", n, &a);
    printf("%d\n", sd(n, a));
    return 0;
}
