#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map<int,int> m_keys,m_index;
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        m_keys[a]=i;
        m_index[i]=a;
    }
    int count =1,start=m_keys[1];
    for(int i=2;i<=n;i++){
        if(start < m_keys[i]){
            start = m_keys[i];
        }else{
            count++;
            start = m_keys[i];
        }
    }
    int a,b;
    for(int i=0;i<m;i++){
        // these are the positions that needs to be swapped
        cin>>a>>b;
        int val_a,val_b;
        val_a=m_index[a];
        val_b = m_index[b];
        if(a < b){
            
            if(val_b < val_a){
                count--;
                cout<<count<<endl;
            }else{

            }
        }else{
            if(val_b > val_a){

            }else{

            }
        }
    }
    return 0;
}