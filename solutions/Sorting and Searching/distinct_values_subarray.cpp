#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<long long int,long long int>m;
    long long int first = 0,second = 0;
   long long int ans = 0;
    while(first < n && second < n){
        m[arr[second]]++;
        while(m[arr[second]] > 1){
            m[arr[first]]--;
            if(m[arr[first]] == 0){
                m.erase(arr[first]);
            }
            first++;
        }
        ans += second-first+1;
        second++;
    }
    cout<<ans;
    return 0;
}