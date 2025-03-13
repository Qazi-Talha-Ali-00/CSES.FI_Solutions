#include<bits/stdc++.h>
using namespace std;
int ans(int n,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(n < 0){
        return INT_MAX;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int x = n;
    // try to remove every possible number except 0 
    int maxi = INT_MAX;
    while(x){
        int val = x%10;
        if(val > 0){
            int b = 1 + ans(n-val,dp);
            maxi = min(maxi,b);
        }
        x = x/10;
    }
    return dp[n]= maxi;
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<ans(n,dp);
    return 0;
}