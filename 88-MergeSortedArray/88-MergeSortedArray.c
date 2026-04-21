// Last updated: 4/22/2026, 12:33:39 AM
1#include <limits.h>
2
3int coinChange(int* coins, int coinsSize, int amount) {
4    int dp[amount + 1];
5
6    for (int i = 0; i <= amount; i++) {
7        dp[i] = INT_MAX;
8    }
9    dp[0] = 0;
10
11    for (int i = 1; i <= amount; i++) {
12        for (int j = 0; j < coinsSize; j++) {
13            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
14                int candidate = dp[i - coins[j]] + 1;
15                if (candidate < dp[i]) {
16                    dp[i] = candidate;
17                }
18            }
19        }
20    }
21
22    return dp[amount] == INT_MAX ? -1 : dp[amount];
23}