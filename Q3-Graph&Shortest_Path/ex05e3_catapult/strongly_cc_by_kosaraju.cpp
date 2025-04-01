//Solving Strongly Connected Component problem by Kosaraju's algorithm 
//Need more clarify about Topo sort & how Kosaraju worked

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int N;
vector<vector<int>> normAdjList, revAdjList;
vector<int> componentSize;
vector<bool> visited;
stack<int> order;

void dfs_for_ordering(int u){
    visited[u] = true;
    for(int v: normAdjList[u]){
        if(visited[v] == false){
            dfs_for_ordering(v);
        }
    }
    order.push(u);
}

void dfs_for_finding_scc(int u, int &size){
    visited[u] = true;
    size++;
    for(int v: revAdjList[u]){
        if(visited[v] == false){
            dfs_for_finding_scc(v, size);
        } //else: nothing (size = 1)
    }
}

int main(){
    cin >> N;
    normAdjList.resize(N);
    revAdjList.resize(N); // reversed arrow
    for(int i = 0; i < N; i++){
        int M; cin >> M;
        for(int j = 0; j < M; j++){
            int x; cin >> x;
            normAdjList[i].push_back(x);
            revAdjList[x].push_back(i);
        }
    }

    // Step 1: Topological Sort (DFS on original graph)
    visited.assign(N, false);
    for(int i = 0; i < N; i++){
        if(!visited[i]){ // visited[i] == false
            dfs_for_ordering(i);
        }
    }

    // Step 2: Find SCCs (DFS on reversed graph)
    visited.assign(N, false);
    while(!order.empty()){
        int u = order.top();
        order.pop();
        if(visited[u] == false){
            int size = 0;
            dfs_for_finding_scc(u, size);
            componentSize.push_back(size);
        }
    }

    // Step 3: Sort results and output
    sort(componentSize.begin(), componentSize.end());
    for(auto x: componentSize){
        cout << x << ' ';
    }
}