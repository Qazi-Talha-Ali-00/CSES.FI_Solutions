#include <bits/stdc++.h>
using namespace std;

int ans(vector<int>& price, vector<int>& pages, int x, int i,vector<vector<int>>&dp) {
    if (i >= price.size()) {
        return 0;
    }
    if(dp[x][i] != -1){
        return dp[x][i];
    }
    // Don't pick the book
    int option1 = ans(price, pages, x, i + 1,dp);
    
    // Pick the book (only if x >= price[i])
    int option2 = 0;
    if (x >= price[i]) {
        option2 = pages[i] + ans(price, pages, x - price[i], i + 1,dp);
    }

    return dp[x][i]= max(option1, option2);
}

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
    vector<vector<int>> dp(x+1,vector<int>(n,-1));
    
    cout << ans(price, pages, x, 0,dp);
    return 0;
}
