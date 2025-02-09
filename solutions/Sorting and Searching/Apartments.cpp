#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<long long int> apartments(n),size(m);
    for(int i=0;i<n;i++){
        cin>>apartments[i];
    }
    for(int j=0;j<m;j++){
        cin>>size[j];
    }
    sort(apartments.begin(),apartments.end());
    sort(size.begin(),size.end());
    int i,j;
    i=0,j=0;
    int count =0;
    while(i < n && j < m){
        // see if the current apartment and requirements match
        if(size[j]>=apartments[i]-k && size[j] <= apartments[i]+k){
            // allot this house to this tenant
            i++;
            j++;
            count++;
        }else if(size[j] < apartments[i]-k){
            // that is the current apt is smaller than the required
            j++;
        }else{
            i++;
        }
    }
    cout<<count;
    return 0;
}