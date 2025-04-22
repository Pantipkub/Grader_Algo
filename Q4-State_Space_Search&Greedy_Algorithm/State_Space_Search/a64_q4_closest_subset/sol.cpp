#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int N,M,K, maxAns = INT_MAX;
vector<int> values;
vector<int> prefSum;

bool BB(int step, int sum, int chosen){
    int unchosen = M-chosen;
    
    sum += (prefSum[step+unchosen] - prefSum[step]);
    if(sum - K > maxAns) return false;
    return true;
}

void brute(int step, int sum, int chosen){
    if(chosen == M){
        maxAns = min(maxAns, abs(K-sum));
        return;
    }

    if(N-step < M-chosen) return;

    
    brute(step+1, sum + values[step], chosen+1);
    if(!BB(step, sum, chosen)) return;
    
    brute(step+1, sum, chosen);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    values.resize(N);
    for(int i = 0; i < N; i++){
        cin >> values[i];
    }

    sort(values.begin(), values.end());

    prefSum.resize(N);
    prefSum[0] = 0;
    for(int i = 1; i < N; i++){
        prefSum[i] = prefSum[i-1] + values[i];
    }

    brute(0, 0, 0);

    cout << maxAns;
}