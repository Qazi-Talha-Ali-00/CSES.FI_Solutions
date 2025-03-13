#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int ans(vector<vector<char>>& arr,int i,int j,int n,vector<vector<int>>&dp){
    if(i>=n || j >= n){
        return 0;
    }
    if(arr[i][j]=='*'){
        return 0;
    }
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return dp[i][j]= (ans(arr,i+1,j,n,dp)%MOD+ans(arr,i,j+1,n,dp)%MOD)%MOD;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<char>> arr(n,vector<char> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<ans(arr,0,0,arr.size(),dp);
    
    return 0;
}