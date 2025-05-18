#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    
    set<int> positions;
    positions.insert(0);  // Start of the street
    positions.insert(x);  // End of the street
    
    map<int, int> lengths;  // Map to store frequency of each passage length
    lengths[x] = 1;  // Initially, there's only one passage of length x
    
    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        
        // Find the positions before and after the new traffic light
        auto it = positions.upper_bound(pos);
        int right = *it;
        int left = *(--it);
        
        // Remove the old passage length
        lengths[right - left]--;
        if (lengths[right - left] == 0) {
            lengths.erase(right - left);
        }
        
        // Add the two new passage lengths
        lengths[pos - left]++;
        lengths[right - pos]++;
        
        // Add the new position to our set
        positions.insert(pos);
        
        // Print the maximum length (the largest key in the map)
        cout << lengths.rbegin()->first << " ";
    }
    
    return 0;
}