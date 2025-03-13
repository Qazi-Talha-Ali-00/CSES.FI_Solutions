#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    // Store tickets as {price, index} pairs
    vector<pair<int, bool>> tickets(n);
    for (int i = 0; i < n; i++) {
        cin >> tickets[i].first;
        tickets[i].second = true; // Available ticket
    }
    
    // Sort tickets by price
    sort(tickets.begin(), tickets.end());
    
    for (int i = 0; i < m; i++) {
        int maxPrice;
        cin >> maxPrice;
        
        // Binary search for the best ticket
        int left = 0, right = n - 1;
        int bestIdx = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (tickets[mid].first <= maxPrice && tickets[mid].second) {
                // This ticket is valid and available
                bestIdx = mid;
                left = mid + 1; // Try to find a better (higher price) ticket
            } else if (tickets[mid].first > maxPrice) {
                // This ticket is too expensive
                right = mid - 1;
            } else {
                // This price is valid but ticket is sold, need to check both sides
                // First check left side for valid tickets
                int tempRight = mid - 1;
                int tempLeft = left;
                bool found = false;
                
                while (tempLeft <= tempRight) {
                    int tempMid = tempLeft + (tempRight - tempLeft) / 2;
                    if (tickets[tempMid].first <= maxPrice && tickets[tempMid].second) {
                        bestIdx = tempMid;
                        tempLeft = tempMid + 1;
                        found = true;
                    } else if (tickets[tempMid].first > maxPrice) {
                        tempRight = tempMid - 1;
                    } else {
                        tempRight = tempMid - 1;
                    }
                }
                
                if (found) {
                    break;
                }
                
                // If no valid ticket found on left side, check right side
                left = mid + 1;
            }
        }
        
        if (bestIdx == -1) {
            cout << -1 << "\n";
        } else {
            cout << tickets[bestIdx].first << "\n";
            tickets[bestIdx].second = false; // Mark as sold
        }
    }
    
    return 0;
}