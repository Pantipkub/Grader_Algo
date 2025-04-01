#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<climits>

using namespace std;

int N;
vector<vector<int>> adjMatrix;

const int INF = 1e9;

int main(){
    cin>>N;
    adjMatrix.resize(N+1, vector<int>(N+1, INF));
    cin>>adjMatrix[1][2];
    adjMatrix[2][1] = adjMatrix[1][2];

    for(int i = 3; i <= N; i++){
        int roads; cin >> roads;
        for(int j = 0; j < roads; j++){
            int f,cost; cin >> f >> cost;
            adjMatrix[i][f] = cost;
            adjMatrix[f][i] = cost;
        }
    }

    for(int i = 1; i <= N; i++){
        adjMatrix[i][i] = 0;
    }

    
    for(int k = 3; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(adjMatrix[i][k] != INF && adjMatrix[k][j] != INF){
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
        cout << adjMatrix[1][2] << ' ';
    }
}