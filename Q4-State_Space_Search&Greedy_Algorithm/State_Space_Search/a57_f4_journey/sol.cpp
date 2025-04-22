#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int N;
vector<vector<int>> adjMatrix;
vector<bool> visited;
vector<int> maxInEach;

int maxAns = INT_MIN;

void dfs(int step, int sum, int cur, int sumInVal){
    if(step == N && cur == N-1){
        maxAns = max(maxAns, sum);
        return;
    }
    
    if(sum + sumInVal < maxAns) return;

    for(int v = 0; v < N; v++){
        if(v == cur) continue;
        if(!visited[v] && (v != N-1 || (v == N-1 && step == N-1))){
            visited[v] = true;
            dfs(step+1, sum+adjMatrix[cur][v], v, sumInVal-maxInEach[v]);
            visited[v] = false;
        }
    }
}

int main(){
    cin >> N;
    adjMatrix.resize(N, vector<int>(N));
    visited.resize(N, false);
    maxInEach.resize(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> adjMatrix[i][j];
        }
    }

    int sumInVal = 0;
    for(int j = 1; j < N; j++){
        int maxVal = INT_MIN;
        for(int i = 0; i < N; i++){
            if(i != j){
                maxVal = max(maxVal, adjMatrix[i][j]);
            }
        }
        maxInEach[j] = maxVal;
        sumInVal += maxVal;
    }

    visited[0] = true;
    dfs(1, 0, 0, sumInVal);

    cout << maxAns;
}