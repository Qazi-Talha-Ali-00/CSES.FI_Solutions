#include<bits/stdc++.h>
using namespace std;
bool can_occupy(vector<vector<char>>&board,int i,int j){
    if(board[i][j]=='*'){
        return false;
    }
    int row , col;
    row = i,col=j;
    while(row >=0 && col< board[0].size()){
        if(board[row][col] =='Q'){
            return false;
        }
        row--;
        col++;
    }
    row = i,col=j;
    while(row >=0 && col >=0 ){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }
    return true;
}
void ans(vector<vector<char>>&board,int &count,vector<int>&cols,int i){
    if(i>=8){
        count++;
        return;
    }
    for(int j=0;j<8;j++){
        if(cols[j] != 1 && can_occupy(board,i,j)){
            cols[j]=1;
            board[i][j]='Q';
            ans(board,count,cols,i+1);
            board[i][j]='.';
            cols[j]=0;
        }
    }
    
}
using namespace std;
int main()
{
    vector<vector<char>> board(8, vector<char>(8));
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            cin>>board[i][j];
        }
    }
    // vector<int> rows(8,0);
    vector<int> cols(8,0);
    int count=0;
    ans(board,count,cols,0);
    cout<<count;
    return 0;
}