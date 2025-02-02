#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, w;

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

int conquer(vector<int> &v, int start, int mid, int stop, vector<int> &sumVec){
    int bestLeft = INT_MIN, bestRight = INT_MIN;

    // Left side (max subarray ending at mid)
    for (int i = mid, count = 0; i >= start && count < w; i--, count++) {
        bestLeft = max(bestLeft, getSum(sumVec, i, mid));
    }

    // Right side (max subarray starting at mid + 1)
    for (int i = mid + 1, count = 0; i <= stop && count < w; i++, count++) {
        bestRight = max(bestRight, getSum(sumVec, mid + 1, i));
    }

    return bestLeft + bestRight;
}

// Divide & Conquer
int divide(vector<int>& v, int start, int stop, vector<int>& sumVec) {
    if (start == stop) return v[start];  // Base case

    int mid = (start + stop) / 2;

    int left_max = divide(v, start, mid, sumVec);
    int right_max = divide(v, mid + 1, stop, sumVec);
    int cross_max = conquer(v, start, mid, stop, sumVec);
   
    return max(left_max, max(right_max, cross_max));
}

int main() {
    cin >> n >> w;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    vector<int> sumVec = sumPrefix(vec);  // Compute prefix sum

    cout << divide(vec, 0, n - 1, sumVec) << endl;  // Call divide function
}
