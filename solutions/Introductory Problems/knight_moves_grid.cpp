#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>ans(n,vector<int>(n,-1));
    vector<vector<int>>visited(n,vector<int>(n,0));
    visited[0][0]=0;
    ans[0][0]=0;
    queue<pair<int,int>>q;
    q.push({0,0});
    vector<pair<int,int>> dir = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<dir.size();i++){
            int dx = dir[i].first;
            int dy = dir[i].second;
            if(x+dx >=0 && x+dx<n && y+dy>=0 && y+dy<n && !visited[x+dx][y+dy]){
                visited[x+dx][y+dy]=1;
                ans[x+dx][y+dy]= 1+ans[x][y];
                q.push({x+dx,y+dy});
            }
        }
    }
    ans[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}