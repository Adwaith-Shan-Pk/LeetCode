// Last updated: 4/22/2026, 12:14:49 AM
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < pricesSize; i++) {
        // Update the minimum price seen so far
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } 
        // Calculate potential profit if we sold today
        else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}