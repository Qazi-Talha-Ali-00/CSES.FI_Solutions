#include<bits/stdc++.h>
using namespace std;
long long int ans(vector<long long int>&arr,int left,int right,vector<vector<long long int>>&dp){
    if(left > right){
        return 0;
    }
    if(dp[left][right] != -1){
        return dp[left][right];
    }
    long long int val1,val2;
    val1 = arr[left]+ min(ans(arr,left+2,right,dp),ans(arr,left+1,right-1,dp));
    val2 = arr[right] + min(ans(arr,left+1,right-1,dp),ans(arr,left,right-2,dp));
    return dp[left][right]= max(val1,val2);
}
int main()
{
    int n;
    cin>>n;
    vector<long long int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<long long int>>dp(n,vector<long long int>(n,-1));
    cout<<ans(arr,0,n-1,dp);
  
    return 0;
}