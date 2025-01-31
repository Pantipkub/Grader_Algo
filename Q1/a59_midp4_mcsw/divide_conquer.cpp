#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Compute prefix sum
vector<int> sumPrefix(vector<int>& v) {
    int n = v.size();
    vector<int> sumVec(n + 1, 0); // Extra space for prefix sum
    for (int i = 1; i <= n; i++) {
        sumVec[i] = sumVec[i - 1] + v[i - 1];
    }
    return sumVec;
}

// Get sum from index `a` to `b`
int getSum(vector<int>& sumVec, int a, int b) {
    return sumVec[b] - sumVec[a - 1];
}

// Divide & Conquer
int divide(vector<int>& v, int start, int stop, vector<int>& sumVec) {
    if (start == stop) return v[start];  // Base case

    int m = (start + stop) / 2;

    int left_max = divide(v, start, m, sumVec);
    int right_max = divide(v, m + 1, stop, sumVec);

    // Find max crossing sum
    int mid_max = INT_MIN;
    for (int i = m; i >= start; i--) {  // Left part
        for (int j = m + 1; j <= stop; j++) {  // Right part
            int sum = getSum(sumVec, i, j);
            mid_max = max(mid_max, sum);
        }
    }

    return max(left_max, max(right_max, mid_max));
}

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    vector<int> sumVec = sumPrefix(vec);  // Compute prefix sum

    cout << divide(vec, 0, n - 1, sumVec) << endl;  // Call divide function
}
