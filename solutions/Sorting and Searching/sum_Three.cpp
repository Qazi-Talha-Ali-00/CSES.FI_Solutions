#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long int target;
    cin>>n;
    cin>>target;
    vector<pair<long long int,int>> arr(n);
    for(int i=0;i<n;i++){
        long long int a;
        cin>>a;
        arr[i] = {a,i+1};
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-2;i++){
        int start = i+1;
        int end = n-1;
        while(start < end){
            if(arr[start].first + arr[end].first == target-arr[i].first){
               
                
                cout<<arr[i].second<<" "<<arr[start].second<<" "<<arr[end].second;
                return 0;
            }else if(arr[start].first+arr[end].first > target-arr[i].first){
                end--;
            }else{
                start++;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}