#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> vec;
vector<int> dp;

int recur(int n){
    if(n > N-1) return 0;
    if(dp[n] != -1) return dp[n];

    return dp[n] = max(recur(n+3) + vec[n], recur(n+1));
}

int main(){
    cin >> N;
    vec.resize(N);
    dp.resize(N, -1);
    for(int i = 0; i < N; i++)
        cin >> vec[i];
    
    cout << recur(0);
}