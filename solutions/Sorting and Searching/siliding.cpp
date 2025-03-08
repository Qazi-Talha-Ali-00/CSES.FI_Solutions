#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int end=k-1 ,start=0;
    while(end < n && start < n){
        vector<int> temp;
        for(int i=start;i<=end;i++){
            temp.push_back(arr[i]);
        }
        sort(temp.begin(),temp.end());
        if(k%2 == 1){
            cout<<temp[k/2]<<" ";
        }else{
            int val;
            val = min(temp[k/2],temp[k/2-1]);
            cout<<val<<" ";
        }
        // temp.clear();
        start++;
        end++;
    }
    return 0;
}