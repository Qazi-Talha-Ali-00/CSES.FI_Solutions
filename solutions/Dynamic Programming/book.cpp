#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    // Fix: Use (n+1) size for the DP table
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    // Bottom-up DP
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j <= x; j++) {
            int option1 = dp[i+1][j]; // Not picking the current book
            int option2 = (j >= price[i]) ? pages[i] + dp[i+1][j-price[i]] : 0; // Picking the book if possible
            
            dp[i][j] = max(option1, option2);
        }
    }
    
    cout << dp[0][x]; // Maximum pages with budget x
    return 0;
}
