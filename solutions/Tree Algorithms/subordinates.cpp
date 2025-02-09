#include<bits/stdc++.h>
using namespace std;
int ans(vector<vector<int>> &adj,int employee,vector<int>&arr){
    int count =0;
    for(int i=0;i<adj[employee].size();i++){
        count += ans(adj,adj[employee][i],arr);
    }
    arr[employee]=count;
    return count + 1;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    int a;
    for(int i=0;i<n-1;i++){
        cin>>a;
        adj[a-1].push_back(i+1);
    }
    vector<int> arr(n);
    ans(adj,0,arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    // cout<<arr.back();
    
    return 0;
}