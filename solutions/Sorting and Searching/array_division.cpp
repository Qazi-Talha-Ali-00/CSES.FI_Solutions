#include <bits/stdc++.h>
using namespace std;

bool isPossible(const vector<int>& arr, long long maxSum, int k) {
    int subarrays = 1;
    long long currentSum = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        // If a single element is greater than maxSum, it's impossible
        if ((long long)arr[i] > maxSum) return false;
        
        if (currentSum + (long long)arr[i] > maxSum) {
            // Start a new subarray
            subarrays++;
            currentSum = arr[i];
        } else {
            currentSum += arr[i];
        }
    }
    
    return subarrays <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    long long totalSum = 0;
    int maxElement = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalSum += (long long)arr[i];
        maxElement = max(maxElement, arr[i]);
    }
    
    // Binary search
    long long left = (long long)maxElement;
    long long right = totalSum;
    
    while (left < right) {
        long long mid = left + (right - left) / 2;
        
        if (isPossible(arr, mid, k)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left;
    
    return 0;
}