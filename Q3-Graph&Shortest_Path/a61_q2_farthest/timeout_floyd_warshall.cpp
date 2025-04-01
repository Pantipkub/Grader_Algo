#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main(){
    int N; cin >> N;
    vector<vector<int>> dist(N, vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> dist[i][j];
            if(dist[i][j] == -1 && i != j)
                dist[i][j] = INT_MAX;
        }
    }

    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int minMaxAns = -1;
    bool flag = false;
    for(int i = 1; i < N; i++){
        if(dist[0][i] != INT_MAX){
            minMaxAns = max(minMaxAns, dist[0][i]);
        }else{
            flag = true;
            break;
        }
    }

    flag ? cout << -1 << endl : cout << minMaxAns << endl;
}
