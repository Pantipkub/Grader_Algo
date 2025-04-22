#include<iostream>
#include<vector>

using namespace std;

int recur(int n, vector<int> &c, vector<int> &dp){
    if(n < 0) return 0;
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = max(recur(n-1, c, dp), recur(n-2, c, dp)+c[n]);
    return dp[n];
    
    
}

int main(){
    int n; cin >> n;
    vector<int> c(n);
    vector<int> dp(n, -1);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    dp[0] = c[0], dp[1] = max(c[1],c[0]);
    cout << recur(n-1, c, dp);
}