#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumWithLimit(vector<int> &A, int w) {
    int n = A.size();
    vector<int> prefix(n + 1, 0);
    deque<int> dq;
    int maxSum = INT_MIN;

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + A[i - 1];

        // เอาค่า prefix ที่หลุดจากช่วง w ออก
        while (!dq.empty() && dq.front() < i - w)
            dq.pop_front();

        // อัปเดตค่าผลรวมที่มากที่สุด
        if (!dq.empty())
            maxSum = max(maxSum, prefix[i] - prefix[dq.front()]);

        // เก็บค่า prefix index เข้า deque โดยรักษา monotonicity
        while (!dq.empty() && prefix[dq.back()] >= prefix[i])
            dq.pop_back();
        dq.push_back(i);
    }
    return maxSum;
}

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << maxSubarraySumWithLimit(A, w) << endl;
    return 0;
}
