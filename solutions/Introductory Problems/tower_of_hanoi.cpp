#include<bits/stdc++.h>
using namespace std;
void ans(int stack1,int stack2, int stack3,int n){
    if(n == 1){
        cout<<stack1<<" "<<stack3<<endl;
        return;
    }
    ans(stack1,stack3,stack2,n-1);
    cout<<stack1<<" "<<stack3<<endl;
    ans(stack2,stack1,stack3,n-1);
}
int main()
{
    int n;
    cin>>n;
    int val = pow(2,n)-1;
    cout<<val<<endl;
    ans(1,2,3,n);
    return 0;
}