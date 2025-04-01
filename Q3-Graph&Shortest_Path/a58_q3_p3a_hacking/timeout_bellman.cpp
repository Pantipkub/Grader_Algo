#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int N,M,K;

int main(){
    cin>>N>>M>>K;
    vector<int> start(K);
    for(int i = 0; i < K; i++){
        cin >> start[i];
    }

    vector<int> costs(N);
    for(int i = 0; i < N; i++){
        cin >> costs[i];
    }

    vector<vector<int>> adjList(N);
    for(int i = 0; i < M; i++){
        int u,v; cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> dist(N, INT_MAX);
    for(int i = 0; i < K; i++){
        int startNode = start[i];
        dist[startNode] = costs[startNode];
    }

    for(int i = 0; i < N-1; i++){
        for(int u = 0; u < N; u++){
            for(int v: adjList[u]){
                if(dist[u] != INT_MAX && dist[v] > dist[u] + costs[v]){
                    dist[v] = dist[u] + costs[v];
                }
            }
        }
    }

    int maxAns = INT_MIN;
    for(int i = 0; i < dist.size(); i++){
        maxAns = max(maxAns, dist[i]);
    }
    cout << maxAns << endl;

}
