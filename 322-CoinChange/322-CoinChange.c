// Last updated: 4/22/2026, 12:36:10 AM
#include <limits.h>

int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];

    for (int i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                int candidate = dp[i - coins[j]] + 1;
                if (candidate < dp[i]) {
                    dp[i] = candidate;
                }
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}