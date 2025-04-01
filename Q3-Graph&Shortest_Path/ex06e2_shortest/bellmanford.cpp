#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, E, S; 
vector<vector<pair<int, int>>> adjList;
vector<int> dist;

void bellman_ford() {
    dist[S] = 0;
    
    // Relax all edges N-1 times
    for(int i = 0; i < N-1; i++){
        for(int u = 0; u < N; u++){
            for(auto [v,w]: adjList[u]){
                if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    
    // Check for negative weight cycle
    for (int u = 0; u < N; u++) {
        for (auto [v, w] : adjList[u]) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                cout << "-1" << endl;
                return;
            }
        }
    }
    
    // Print distances
    for (int i = 0; i < N; i++) {
        cout << (dist[i] == INT_MAX ? INT_MAX : dist[i]) << " ";
    }
    cout << endl;
}

int main() {
    cin >> N >> E >> S;
    adjList.resize(N);
    dist.assign(N, INT_MAX);
    
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back({b, c}); // {target, weight}
    }
    
    bellman_ford();
    
    return 0;
}
