#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int ans(vector<int>&arr,int index,int prev,int m,vector<vector<int>>&dp){
    if(index >=arr.size()){
        return 1;
    }
    if(dp[index][prev] !=-1){
        return dp[index][prev];
    }
    if(arr[index] != 0){
        if(prev !=0 && abs(prev - arr[index]) > 1){
            return 0;
        }
        return dp[index][prev]= ans(arr,index+1,arr[index],m,dp);
    }
    int val=0;
    int start, end;
if (prev == 0) {  
    start = 1, end = m;  // If no previous value, we consider all numbers
} else {
    start = max(1, prev - 1);
    end = min(m, prev + 1);
}
    for(int i=start;i<=end;i++){
        if (prev != 0 && abs(prev - i) > 1) continue; 
        // arr[index]=i;
      val= (val+ ans(arr,index+1,i,m,dp))%MOD;
    }
    return dp[index][prev]= val;
}

int main() {    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(m + 1, -1));  // m+2 to prevent out-of-bounds access
    cout<<ans(arr,0,0,m,dp);
    
    return 0;
}
