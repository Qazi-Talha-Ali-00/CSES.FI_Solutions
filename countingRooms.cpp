#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<char>> &arr,int row,int col){
    arr[row][col] = '#';
    queue<pair<int,int>>q;
    q.push({row,col});
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int n = arr.size();
    int m = arr[0].size();
    while(!q.empty()){
        int i , j;
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int x,y;
            x = i+dir[k].first;
            y = j+dir[k].second;
            if(x>=0 && y>=0 && x<n && y <m && arr[x][y]=='.'){
                q.push({x,y});
                arr[x][y]='#';
            }
        }
    }
    return;
}
int main()
{
    int n ,m;
    cin>>n;
    cin>>m;
    vector<vector<char>> arr(n,vector<char> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.'){
                count++;
                bfs(arr,i,j);
            }
        }
    }
    cout<<count;
    return 0;
}