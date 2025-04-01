#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int V, E; cin >> V >> E;
    vector<int> weighted(V);
    for (int i = 0; i < V; i++) cin >> weighted[i];

    vector<vector<int>> adjList(V);
    vector<int> in_degree(V, 0);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        in_degree[v]++; // counting each node's in_degree
    }

    // Find a root node (Topological Sorting)
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

    // minCost collect the least node's value from path, and store in the current node
    // ex. 10->20->50, node: 1,2,3
    // minCost[3] = 10;
    vector<int> minCost(V, INT_MAX);
    int maxAns = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        // Calculating maxAns by "current weight" - "minimum weight from any path to this node"
        if(minCost[u] != INT_MAX){
            maxAns = max(maxAns, weighted[u] - minCost[u]);
        }

        for(int v: adjList[u]){
            // minCost[v] = min(least value from other path that has been visited "v" node, the least node's value from current path, the current node's value "u")
            minCost[v] = min(minCost[v], min(minCost[u], weighted[u]));
            // if we have checked all possible path to "v" node, we are ready to calculate the maxAns
            if(--in_degree[v] == 0){
                q.push(v);
            }
        }
    }
    cout << maxAns << "\n";
}
