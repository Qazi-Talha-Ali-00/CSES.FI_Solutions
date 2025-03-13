
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long int ans(vector<int>&coins,int sum,int x,vector<long long int>&dp){
    if(sum ==x){
        return 1;
    }
    if(sum > x){
        return 0;
    }
    if(dp[sum] != -1){
        return dp[sum];
    }

    long long int val =0;
    for(int i=0;i<coins.size();i++){
        val = (val + ans(coins, sum + coins[i], x, dp)) % MOD;
    }
    return dp[sum]=val;
}
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    vector<long long int> dp(x+1,-1);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<ans(coins,0,x,dp);

    return 0;
}