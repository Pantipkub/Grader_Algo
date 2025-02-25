#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> vec;
vector<int> dp;

int main(){
    cin >> n;
    vec.resize(n);
    dp.resize(n, -1);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    
    dp[0] = vec[0];
    dp[1] = max(dp[0], vec[1]);
    dp[2] = max(dp[1], vec[2]);
    for(int i = 3; i < n; i++){
        dp[i] = max(max(dp[i-3] + vec[i], dp[i-2]), dp[i-1]);
    }
    cout << dp[n-1];
}