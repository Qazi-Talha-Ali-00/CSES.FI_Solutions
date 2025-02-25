#include <bits/stdc++.h>
using namespace std;

int ans(vector<int>& coins, int target, vector<int>& dp) {
    if (target == 0) return 0;  // 0 coins needed for sum 0
    if (target < 0) return INT_MAX / 2;  // Large value to avoid min issues
    if (dp[target] != -1) return dp[target];

    int min_coins = INT_MAX / 2; // Large initial value
    for (int coin : coins) {
        min_coins = min(min_coins, 1 + ans(coins, target - coin, dp));
    }
    
    return dp[target] = min_coins;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, -1);
    int result = ans(coins, x, dp);
    cout << (result >= INT_MAX / 2 ? -1 : result) << endl;
    return 0;
}
