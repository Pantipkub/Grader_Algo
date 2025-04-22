#include<iostream>
#include<vector>

using namespace std;

int n;

int maxEat(int head, int tail, vector<int> &sushi, vector<vector<int>> &dp){
    //if(head > n-1 || tail < 0) return 0;
    if(dp[head][tail] != -1){
        return dp[head][tail];
    }
    if(head == tail-1){
        dp[head][tail] = max(sushi[head], sushi[tail]);
        return dp[head][tail];
    }
    int eat2Left = maxEat(head+2, tail, sushi, dp) + max(sushi[head], sushi[head+1]);
    int eat2Right = maxEat(head, tail-2, sushi, dp) + max(sushi[tail-1], sushi[tail]);
    int eat1Both = maxEat(head+1, tail-1, sushi, dp) + max(sushi[head], sushi[tail]);
    dp[head][tail] = max(max(eat2Left, eat2Right), eat1Both);
    return dp[head][tail];
}

int main(){
    cin >> n;
    vector<int> sushi(n);
    for(int i = 0; i < n; i++){
        cin >> sushi[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << maxEat(0, n-1, sushi, dp);
}