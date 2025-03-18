#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp; // Memoization table
set<int> sums; // Stores unique sums

// Recursive function to compute sums
void findSums(vector<int>& coins, int i, int sum) {
    if (i == coins.size()) {
        if (sum > 0) sums.insert(sum);
        return;
    }
    
    // If this state is already computed, return
    if (dp[i][sum] != -1) return;
    dp[i][sum] = 1;

    // Option 1: Include coins[i]
    findSums(coins, i + 1, sum + coins[i]);

    // Option 2: Exclude coins[i]
    findSums(coins, i + 1, sum);
}

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    int sumLimit = accumulate(coins.begin(), coins.end(), 0); // Maximum sum possible
    dp.assign(n + 1, vector<int>(sumLimit + 1, -1)); // Initialize DP table

    findSums(coins, 0, 0); // Start recursion

    cout << sums.size() << endl;
    for (int sum : sums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
