#include<iostream>
#include<vector>

using namespace std;

string bellman_ford(vector<double> &dist, vector<vector<double>> &table, int N){
    dist[0] = 1;

    for(int i = 0; i < N-1; i++){
        for(int u = 0; u < N; u++){
            for(int v = 0; v < N; v++){
                if(dist[u] > 0 && dist[u] * table[u][v] > dist[v]){
                    dist[v] = dist[u] * table[u][v];
                }
            }
        }
    }

    for(int u = 0; u < N; u++){
        for(int v = 0; v < N; v++){
            if(dist[u] > 0 && dist[u] * table[u][v] > dist[v]){
                return "YES";
            }
        }
    }
    return "NO";
}

int main(){
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        int N; cin >> N;

        vector<vector<double>> table(N, vector<double>(N));
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                cin >> table[j][k];
            }
        }

        vector<double> dist(N, 0.0);
        cout << bellman_ford(dist, table, N) << '\n';
    }
}
