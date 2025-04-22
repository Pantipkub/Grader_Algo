#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(k), dp(n, INT_MIN);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++) cin >> b[i];

    dp[0] = a[0];

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                dp[i] = max(dp[i], dp[i - j] - b[j - 1] + a[i]);
            }
        }
    }

    cout << dp[n - 1] << endl;
}
