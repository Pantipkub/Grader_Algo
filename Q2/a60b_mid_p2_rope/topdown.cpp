#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> dp;

int recur(int N, int a, int b, int c){
    if(N < 0) return -9999;
    if(N == 0) return 0;
    if(dp[N] != -1) return dp[N];

    int A = recur(N - a, a, b, c) + 1;
    int B = recur(N - b, a, b, c) + 1;
    int C = recur(N - c, a, b, c) + 1;

    return dp[N] = max(max(A,B),C);
}

int main(){
    
    int n, a, b, c; cin >> n >> a >> b >> c;
    dp.resize(n+1, -1);
    cout << recur(n, a, b, c);

}