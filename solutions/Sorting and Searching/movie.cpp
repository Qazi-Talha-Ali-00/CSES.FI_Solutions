#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>&a,pair<int,int>&b){
    if(b.second > a.second){
        return true;
    }else if(b.second < a.second){
        return false;
    }else{
        return b.first>a.first;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    int x, y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        arr.push_back({x,y});
    }
    vector<pair<int,int>> b;
    sort(arr.begin(),arr.end(),comp);
    for(int i=0;i<n;i++){
        if(b.size()==0){
            b.push_back({arr[i].first,arr[i].second});
        }else{
            if(b.back().second <= arr[i].first){
                b.push_back({arr[i].first,arr[i].second});
            }
        }
    }
    cout<<b.size();
    return 0;
}