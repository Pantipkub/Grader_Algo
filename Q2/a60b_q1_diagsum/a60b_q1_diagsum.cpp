#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }

    int maxSum = vec[0][0];

    // Diagonals starting from (0, i)
    for (int i = 0; i < n; i++) {
        int r = 0, c = i;
        int maxCur = 0, maxGlobal = -1e9;
        while (r < n && c < n) {
            maxCur = max(maxCur + vec[r][c], vec[r][c]);
            maxGlobal = max(maxGlobal, maxCur);
            r++; c++;  // Move diagonally down-right
        }
        maxSum = max(maxSum, maxGlobal);
    }

    // Diagonals starting from (i, 0)
    for (int i = 1; i < n; i++) {
        int r = i, c = 0;
        int maxCur = 0, maxGlobal = -1e9;
        while (r < n && c < n) {
            maxCur = max(maxCur + vec[r][c], vec[r][c]);
            maxGlobal = max(maxGlobal, maxCur);
            r++; c++;  // Move diagonally down-right
        }
        maxSum = max(maxSum, maxGlobal);
    }

    cout << maxSum;
}

