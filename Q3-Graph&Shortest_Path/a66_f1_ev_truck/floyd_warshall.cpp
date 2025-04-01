#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int N,M;

int main(){
    cin >> N >> M;
    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
    for(int i = 0; i < M; i++){
        int a,b,w; cin>>a>>b>>w;
        dist[a][b] = w;
        dist[b][a] = w; 
    }

    for(int i = 0; i < N; i++){
        dist[i][i] = 0;
    }

    int maxAns = INT_MIN;
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
                if(k == N-1 && dist[i][j] != INT_MAX) maxAns = max(maxAns, dist[i][j]);
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << maxAns << endl;
}