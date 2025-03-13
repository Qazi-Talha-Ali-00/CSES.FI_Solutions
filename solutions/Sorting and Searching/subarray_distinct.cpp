#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printf("\n value of n is %d",n);
    unordered_map<int,int>m;
    long long int count =0;
    int start=0,end=0;
    while(start < n && end < n){
       m[arr[end]]++;
       while(m.size()>x){
        m[arr[start]]--;
        if(m[arr[start]]==0){
            m.erase(arr[start]);
        }
        start++;
       }
       count += end-start+1;
       end++;
        
    }
    cout<<count;
    return 0;
}