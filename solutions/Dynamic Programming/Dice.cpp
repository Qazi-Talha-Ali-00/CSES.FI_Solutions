#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long int ans(int count,vector<long long int>&dp){
    if(count == 0){
        return 1;
    }else if(count <0){
        return 0;
    }
    if(dp[count] != -1){
        return dp[count];
    }
    long long int val =0;
    for(int i=1;i<=6;i++){
        val +=ans(count-i,dp);
    }
    return dp[count]=val%MOD;
}
int main()
{
    int n;
    cin>> n;
    vector<long long int> dp(n+1,-1);
    cout<<ans(n,dp);
    return 0;
}