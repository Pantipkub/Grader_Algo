#include<iostream>
#include<vector>

using namespace std;

int N;
int ans = 0;

void recur(int cur, int sum, int step){
    if(sum == N){
        ans++;
        return;
    }
    if(sum > N) return; // Backtracking
    if(cur == 0 && step != 0) return;

    for(int i = cur; i <= N-sum; i++){
        recur(i, sum+i, step+1);
    }
}

int main(){
    cin >> N;
    recur(0, 0, 0);
    cout << ans << endl;
}