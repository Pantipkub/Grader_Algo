#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> dp;
vector<int> a;
vector<int> b;
int n, k;

int recur(int N){
    if(N > n-1) return -1e9;
    if(N == n-1) return a[N];
    if(dp[N] != INT_MIN) return dp[N];
    

    int maxChild = INT_MIN;
    for(int i = 1; i <= k; i++){
        int child = recur(N+i) - b[i-1];
        maxChild = max(maxChild, child);
    }

    return dp[N] = maxChild + a[N];
}

int main() {
    cin >> n >> k;

    a.resize(n);
    b.resize(k);
    dp.resize(n, INT_MIN);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++) cin >> b[i];

    cout << recur(0) << endl;
}
