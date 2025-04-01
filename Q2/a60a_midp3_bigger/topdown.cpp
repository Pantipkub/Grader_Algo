#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> vec;
vector<int> dp;

int recur(int n){
    if(n > N-1) return 0;
    if(dp[n] != -1) return dp[n];

    int next3 = recur(n+3);
    int next4 = recur(n+4);
    int next5 = recur(n+5);
    return dp[n] = max(max(next3,next4),next5) + vec[n];
}

int main(){
    cin >> N;
    vec.resize(N);
    dp.resize(N, -1);
    for(int i = 0; i < N; i++)
        cin >> vec[i];
    
    int start0 = recur(0);
    int start1 = recur(1);
    int start2 = recur(2);
    cout << max(max(start0,start1),start2);
}