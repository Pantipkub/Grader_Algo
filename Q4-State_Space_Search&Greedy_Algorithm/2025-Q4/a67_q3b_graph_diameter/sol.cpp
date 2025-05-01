#include<bits/stdc++.h>


using namespace std;

int N,M;

int main(){
    cin >> N >> M;
    vector<vector<int>> adjMatrix(N, vector<int>(N, INT_MAX));
    for(int i = 0; i < M; i++){
        int f,s,cost; cin >> f >> s >> cost;
        f--;
        s--;
        adjMatrix[f][s] = cost;
    }

    for(int i = 0; i < N; i++){
        adjMatrix[i][i] = 0;
    }

    for(int k = 0; k < N; k++){
        for(int i = 0; i <= N-1; i++){
            for(int j = 0; j <= N-1; j++){
                if(adjMatrix[i][k] != INT_MAX && adjMatrix[k][j] != INT_MAX){
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
    }

    int minMaxAns = INT_MIN;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            minMaxAns = max(minMaxAns, adjMatrix[i][j]);
            // cout << adjMatrix[i][j] << ' ';
        }
        // cout << endl;
    }

    cout << minMaxAns;
}