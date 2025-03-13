    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int n;
        cin>>n;
        vector<pair<long long int,long long int>> arr;
        long long int a,b;
        for(int i=0;i<n;i++){
            cin>>a>>b;

            arr.push_back({a,+1});
            arr.push_back({b,-1});
        }
        // sort on the basis of arrival time
        sort(arr.begin(),arr.end());
        // for(int i=0;i<arr.size();i++){
        //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
        // }
    long long int count =0,maxi=0;
    long long int left = arr[0].first;
    long long int right = arr[0].second;
       for(int i=0;i<arr.size();i++){
        count+=arr[i].second;
        maxi = max(maxi,count);
       }
        cout<<maxi;

        return 0;

    }