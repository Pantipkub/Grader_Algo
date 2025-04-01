#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n;
vector<vector<int>> adjList;

vector<int> bfs(int start){
    vector<int> dist(n+1, INT_MAX);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: adjList[u]){
            if(dist[v] == INT_MAX){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}


int main() {
    cin >> n;
    vector<int> start(4); // t1, t2, t3
    for (int i = 1; i <= 3; i++) {
        cin >> start[i];
    }

    adjList.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            adjList[i].push_back(v);
        }
    }

    // We need to span the dist for each starter node (n1,n2,n3)
    vector<int> dist1 = bfs(start[1]);
    vector<int> dist2 = bfs(start[2]);
    vector<int> dist3 = bfs(start[3]);

    // Iterate through every node, finding the least maximum cost
    int min_max_cost = INT_MAX;
    for(int i = 1; i <= n; i++){
        // The impossible node that n1 or n2 or n3 can't reach, will left with INT_MAX (No path from nA->nB)
        // Which means: We will skip that node, cuz not everyone can reach that node
        // But, if it's possible: we will compare the minimum of all 3 ways max cost 
        if(dist1[i] != INT_MAX && dist2[i] != INT_MAX && dist3[i] != INT_MAX){
            min_max_cost = min(min_max_cost, max(max(dist1[i], dist2[i]), dist3[i]));
        }
    }
    
    cout << min_max_cost << endl;
}
