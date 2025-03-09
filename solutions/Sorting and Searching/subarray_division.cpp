#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    unordered_map<long long int,long long int> m;
  long long  int pre = 0;
    int y;
   long long int rem;
    long long int count=0;
    for(int i=0;i<n;i++){
        cin>>y;
        pre+=y;
        rem = pre%n;
        if(rem < 0){
            rem+=n;
        }
        if(rem==0){
            count++;
        }
        count += m[rem];
        m[rem]++;
    }
    cout<<count;
    return 0;
}