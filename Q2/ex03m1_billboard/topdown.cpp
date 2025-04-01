#include<iostream>
#include<vector>

using namespace std;

vector<int> dp;
vector<int> c;

int sudTarng;

int recur(int n){
    if(n > sudTarng) return 0;
    if(dp[n] != -1) return dp[n];

    int next1 = recur(n+2);
    int next2 = recur(n+3);
    return dp[n] = max(next1,next2) + c[n];
}

int main(){
    int n; cin >> n;
    sudTarng = n-1;
    c.resize(n);
    dp.resize(n, -1);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    int start0 = recur(0);
    int start1 = recur(1);
    cout << max(start0, start1);
}