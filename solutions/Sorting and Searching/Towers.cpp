#include<bits/stdc++.h>
using namespace std;
int binary(vector<int>&arr,int end,int target){
    int start =0;
    int ans =-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid] > target){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,-1);
    int count =-1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        int index = binary(arr,count,x);
        if(index == -1){
            count++;
            arr[count]=x;
        }else{
            arr[index]=x;
        }
    }
    cout<<count+1;
    return 0;
}