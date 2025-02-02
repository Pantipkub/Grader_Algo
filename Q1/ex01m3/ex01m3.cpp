#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

// ฟังก์ชันตรวจสอบว่าในเวลา time ลูกค้าได้รับที่นั่งกี่คน
ll countCustomersServed(const vector<int>& T, ll time, int N) {
    ll count = 0;
    for (int i = 0; i < N; i++) {
        count += (time / T[i]) + 1;  // นับลูกค้าที่เข้าไปนั่งที่ที่นั่ง i ในเวลานี้
    }
    return count;
}

// ฟังก์ชันหาเวลาที่ลูกค้าหมายเลข c จะได้ที่นั่ง
ll findSeatingTime(const vector<int>& T, ll c, int N) {
    ll left = 0, right = 1e18, answer = 0;
    
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (countCustomersServed(T, mid, N) >= c) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

int main() {
    int N, A;
    cin >> N >> A;
    vector<int> T(N);

    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    vector<ll> queries(A);
    for (int i = 0; i < A; i++) {
        cin >> queries[i];
    }

    for (ll c : queries) {
        cout << findSeatingTime(T, c, N) << endl;
    }

    return 0;
}
