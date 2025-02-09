#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        int a ,b;
        cin>>a;
        cin>>b;
        arr.push_back({a,b});
    }
    vector<pair<int,int>> ans;
    int count =0,maxi = INT_MIN;
    for(int i=0;i<n;i++){
        if(ans.size() == 0){
            ans.push_back(arr[i]);
        }else{
            if(ans.back().second >= arr[i].first){
                ans.back().first = max(ans.back().first,arr[i].first);
                ans.back().second = min(ans.back().second,arr[i].second);
                count++;
            }else{
                ans.push_back(arr[i]);
                maxi = max(maxi,count);
                count = 0;
            }
        }
    }
    maxi = max(maxi,count);
    cout<<maxi;
    return 0;

}