#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 +7;
int ans(int sum,int i,int target,int n,vector<vector<int>>&dp){
    if(sum == target){
        return 1;
    }
    if(sum > target || i > n){
        return 0;
    }
    if(dp[sum][i] != -1){
        return dp[sum][i];
    }
    return dp[sum][i] = (ans(sum+i,i+1,target,n,dp) + ans(sum,i+1,target,n,dp))%MOD;
}
int main()
{
    int n;
    cin>>n;
    int target = n*(n+1)/2;
    if(target%2){
        cout<<0;
        return 0;
    }
    target = target/2;
    vector<vector<int>>dp(target+1,vector<int>(n,-1));
    cout<<ans(0,1,target,n,dp);
    return 0;
}