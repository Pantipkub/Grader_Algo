#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> forest;
vector<vector<int>> table;
int n, m;

int recur(int r, int c) {
    if (r >= n || c >= m) return 0; // Base case: Out of bounds
    if (table[r][c] != -1) return table[r][c]; // Memoization

    int down = recur(r + 1, c) + forest[r][c];       // Move down
    int right = recur(r, c + 1) + forest[r][c];      // Move right
    int diagonal = (r + 1 < n && c + 1 < m) ? recur(r + 1, c + 1) + forest[r][c] + forest[r + 1][c + 1] : 0;

    return table[r][c] = max(max(down, right), diagonal);
}

int main() {
    cin >> n >> m;
    forest.resize(n, vector<int>(m));
    table.assign(n, vector<int>(m, -1)); // Initialize DP table with -1

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> forest[i][j];

    cout << recur(0, 0) << endl; // Start from (0,0)
}
