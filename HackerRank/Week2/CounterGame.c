Question: Counter Game
Louise and Richard have developed a numbers game. They pick a number and check to see if it is a power of . If it is, they divide it by . If not, they reduce it by the next lower number which is a power of . Whoever reduces the number to  wins the game. Louise always starts.

Given an initial value, determine who wins the game.

Solution:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ispt(unsigned long n) {
    return (n && !(n & (n - 1)));
}

unsigned long nlpt(unsigned long n) {
    unsigned long a = 1;
    while (a << 1 < n) {
        a <<= 1;
    }
    return a;
}

char* cg(unsigned long n) {
    int turn = 0; 
    while (n > 1) {
        if (ispt(n)) {
            n /= 2;
        } else {
            n -= nlpt(n);
        }
        turn = 1 - turn;
    }

    return turn == 0 ? "Richard" : "Louise";
}

int main() {
    int b;
    scanf("%d", &b);
    while (b--) {
        unsigned long n;
        scanf("%lu", &n);
        printf("%s\n", cg(n));
    }
    return 0;
}
