#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    unordered_map<int, int> lastPosition;
    lastPosition.reserve(n);
    
    int start = 0;
    int maxi = 0;
    
    for (int end = 0; end < n; end++) {
        auto it = lastPosition.find(arr[end]);
        if (it != lastPosition.end() && it->second >= start) {
            start = it->second + 1;
        }
        lastPosition[arr[end]] = end;
        maxi = max(maxi, end - start + 1);
    }
    
    cout << maxi;
    
    return 0;
}