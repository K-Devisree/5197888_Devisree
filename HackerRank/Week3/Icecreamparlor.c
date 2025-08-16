Question: Ice cream parlor

Two friends like to pool their money and go to the ice cream parlor. They always choose two distinct flavors and they spend all of their money.

Given a list of prices for the flavors of ice cream, select the two that will cost all of the money they have.

Solution:

#include <stdio.h>
#include <stdlib.h>

int* icecreamParlor(int totalMoney, int* prices, int n) {
    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prices[i] + prices[j] == totalMoney) {
                result[0] = i + 1;
                result[1] = j + 1;
                return result;
            }
        }
    }
    return result;
}

int main() {
    int trips;
    scanf("%d", &trips);

    for (int t = 0; t < trips; t++) {
        int totalMoney, flavors;
        scanf("%d", &totalMoney);
        scanf("%d", &flavors);

        int* prices = (int*)malloc(flavors * sizeof(int));
        for (int i = 0; i < flavors; i++) {
            scanf("%d", &prices[i]);
        }

        int* indices = icecreamParlor(totalMoney, prices, flavors);
        printf("%d %d\n", indices[0], indices[1]);

        free(prices);
        free(indices);
    }

    return 0;
}
