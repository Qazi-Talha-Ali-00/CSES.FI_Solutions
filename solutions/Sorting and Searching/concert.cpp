#include<bits/stdc++.h>
using namespace std;
long long int find(vector<int>&arr,int target,unordered_map<long long int,bool>&m){
    int start =0,end = arr.size()-1;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] > target){
            end = mid-1;
        }else if(arr[mid] <= target){
            if(m[mid] == false){
                start = mid+1;
                ans = mid;
            }else{
                end = mid-1;
            }
        }
    }
    if(ans != -1){
m[ans]=true;
    }
    
    return ans;
}
int main()
{
    int n , m;
    cin>>n;
    cin>>m;
    vector<int> price(n),people(m);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<m;i++){
        cin>>people[i];
    }
    sort(price.begin(),price.end());
    unordered_map<long long int,bool>map;
    int j=0;
    while(j<m){
       long long int val = find(price,people[j++],map);
        if(val != -1){
            val = price[val];
        }
        cout<<val<<endl;
    }
    return 0;
}