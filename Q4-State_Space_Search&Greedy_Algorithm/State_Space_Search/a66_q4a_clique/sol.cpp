#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int N, maxAns = INT_MIN;
vector<int> tails, power, chosen;
vector<vector<int>> B;

bool isValid(int step){
    for(int i = 0; i < step; i++){
        if(chosen[i]){
            if(!B[i][step]){
                return false;
            }
        }
    }
    return true;    
}

void recur(int step, int sum){
    if(sum + tails[step] < maxAns) return;
    if(step >= N){
        maxAns = max(maxAns, sum);
        return;
    }else{
        chosen[step] = 1;
        if(isValid(step)) recur(step+1, sum+power[step]);
        chosen[step] = 0;
        recur(step+1, sum);
    }
}

int main(){
    cin >> N;
    power.resize(N), tails.resize(N+1), chosen.resize(N), B.resize(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        cin >> power[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> B[i][j];
        }
    }
    for(int i = N-1; i >= 0; i--){
        tails[i] = tails[i+1] + power[i];
    }

    recur(0, 0);

    cout << maxAns;

}