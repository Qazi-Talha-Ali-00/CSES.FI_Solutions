#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    
    // Store positions of traffic lights
    set<int> positions;
    // Initialize with street boundaries
    positions.insert(0);
    positions.insert(x);
    
    // Store segments (lengths between consecutive lights)
    multiset<int, greater<int>> segments;
    segments.insert(x); // Initially, the whole street is one segment
    
    vector<int> results;
    
    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        
        // Find the segment where the new traffic light will be placed
        auto it = positions.upper_bound(pos);
        int right = *it;
        int left = *(--it);
        
        // Remove the old segment
        segments.erase(segments.find(right - left));
        
        // Add two new segments
        segments.insert(pos - left);
        segments.insert(right - pos);
        
        // Add the new traffic light position
        positions.insert(pos);
        
        // The longest segment is at the top of our multiset
        results.push_back(*segments.begin());
    }
    
    // Print results
    for (int result : results) {
        cout << result << " ";
    }
    
    return 0;
}   