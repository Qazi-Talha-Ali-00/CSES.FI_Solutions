#include <bits/stdc++.h>
using namespace std;

const int N = 7;
vector<int> dx = {1, -1, 0, 0}; // D, U, R, L
vector<int> dy = {0, 0, 1, -1};
char moves[4] = {'D', 'U', 'R', 'L'};

int ans(string &s, int i, int row, int col, vector<vector<bool>> &visited) {
    // If we reach the target at the exact step count, it's a valid path
    if (i == s.size()) {
        return (row == 6 && col == 0);
    }
    // If out of bounds or already visited, return 0
    if (row < 0 || row >= 7 || col < 0 || col >= 7 || visited[row][col]) {
        return 0;
    }
    
    visited[row][col] = true; // Mark the current cell as visited
    int val = 0;

    if (s[i] == '?') {  // Try all directions
        for (int k = 0; k < 4; k++) {
            int x = row + dx[k];
            int y = col + dy[k];
            val += ans(s, i + 1, x, y, visited);
        }
    } else {  // Move only in the specified direction
        int pos = (s[i] == 'L') ? 3 : (s[i] == 'R') ? 2 : (s[i] == 'U') ? 1 : 0;
        int x = row + dx[pos];
        int y = col + dy[pos];
        val += ans(s, i + 1, x, y, visited);
    }

    visited[row][col] = false; // Backtrack
    return val;
}

int main() {
    string s;
    cin >> s;
    
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    cout << ans(s, 0, 0, 0, visited);
    
    return 0;
}
