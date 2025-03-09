#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long x;
    cin >> n >> x;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<long long, long long> prefixSums;
    prefixSums[0] = 1; // Empty subarray has sum 0
    
    long long currentSum = 0;
    long long count = 0;
    
    for (int i = 0; i < n; i++) {
        currentSum += a[i];
        
        // Count subarrays ending at current position with sum x
        count += prefixSums[currentSum - x];
        
        // Update prefix sum count
        prefixSums[currentSum]++;
    }
    
    cout << count;
    return 0;
}