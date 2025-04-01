#include<iostream>
#include<vector>

using namespace std;

vector<int> dp;
vector<int> c;

int sudTarng;

int recur(int n){
    if(n > sudTarng) return 0;
    if(dp[n] != -1) return dp[n];

    return dp[n] = max(recur(n+2) + c[n] , recur(n+1));
}

int main(){
    int n; cin >> n;
    sudTarng = n-1;
    c.resize(n);
    dp.resize(n, -1);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    cout << recur(0);
}