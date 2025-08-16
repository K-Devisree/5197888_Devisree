Question: Waiter
You are a waiter at a party. There is a pile of numbered plates. Create an empty  array. At each iteration, , remove each plate from the top of the stack in order. Determine if the number on the plate is evenly divisible by the  prime number. If it is, stack it in pile . Otherwise, stack it in stack . Store the values in  from top to bottom in . In the next iteration, do the same with the values in stack . Once the required number of iterations is complete, store the remaining values in  in , again from top to bottom. Return the  array.

Solution:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

int* generatePrimes(int q) {
    int* primes = (int*)malloc(q * sizeof(int));
    int count = 0, num = 2;
    while (count < q) {
        if (isPrime(num)) primes[count++] = num;
        num++;
    }
    return primes;
}

int* waiter(int* plates, int n, int q, int* resultSize) {
    int* output = (int*)malloc(n * sizeof(int));
    int topOutput = 0;

    int* current = (int*)malloc(n * sizeof(int));
    int countCurrent = n;
    for (int i = 0; i < n; i++) current[i] = plates[i];

    int* primes = generatePrimes(q);

    for (int i = 0; i < q; i++) {
        int prime = primes[i];
        int* divisible = (int*)malloc(countCurrent * sizeof(int));
        int* notDivisible = (int*)malloc(countCurrent * sizeof(int));
        int divCount = 0, notDivCount = 0;

        for (int j = countCurrent - 1; j >= 0; j--) {
            if (current[j] % prime == 0) divisible[divCount++] = current[j];
            else notDivisible[notDivCount++] = current[j];
        }

        for (int j = divCount - 1; j >= 0; j--) output[topOutput++] = divisible[j];

        free(current);
        current = notDivisible;
        countCurrent = notDivCount;
        free(divisible);
    }

    for (int i = countCurrent - 1; i >= 0; i--) output[topOutput++] = current[i];
    free(current);
    free(primes);

    *resultSize = topOutput;
    return output;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int* plates = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &plates[i]);

    int resultSize;
    int* result = waiter(plates, n, q, &resultSize);
    for (int i = 0; i < resultSize; i++) printf("%d\n", result[i]);

    free(plates);
    free(result);
    return 0;
}
