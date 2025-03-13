#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long int ans(vector<int>& coins, int index, int x, vector<vector<long long int>>& dp) {
    // Base case: If the target sum is achieved
    if (x == 0) {
        return 1;
    }
    // Base case: If the target sum is not achievable
    if (x < 0 || index >= coins.size()) {
        return 0;
    }
    // If the result is already computed, return it
    if (dp[index][x] != -1) {
        return dp[index][x];
    }
    // Recursive case:
    // Option 1: Include the current coin (coins[index]) and stay at the same index (since infinite supply is allowed)
    // Option 2: Exclude the current coin and move to the next index
    long long int include = ans(coins, index, x - coins[index], dp) % MOD;
    long long int exclude = ans(coins, index + 1, x, dp) % MOD;
    // Store the result in the DP table and return
    return dp[index][x] = (include + exclude) % MOD;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    // Initialize the DP table with -1
    vector<vector<long long int>> dp(n, vector<long long int>(x + 1, -1));
    cout << ans(coins, 0, x, dp);
    return 0;
}