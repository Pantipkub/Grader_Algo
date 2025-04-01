#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int sudTarng;
vector<int> dp, arr;

int recur(int N){
    if(N > sudTarng) return -9999999;
    if(N == sudTarng) return arr[N];
    if(dp[N] != -1) return dp[N];

    int p1 = recur(N+1) + arr[N];
    int p2 = recur(N+2) + arr[N];
    int p3 = recur(N+3) + arr[N];

    return dp[N] = max(max(p1,p2),p3);
}

int main(){
    int n; cin >> n;
    sudTarng = n-1;
    dp.resize(n, -1);
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << recur(0) << endl;
}