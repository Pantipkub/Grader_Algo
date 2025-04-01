// this cant be a solution, because in the worst case which is having every edges between u&v ; u < v
// not memorizing each path's answer cause a timeout 
// 0 → 1 → 2 → 3 → 4
// ↓   ↓   ↓   ↓
// 2   3   4   4
// ↓   ↓   ↓
// 3   4   4
// ↓   ↓
// 4   4
// ↓
// 4

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int maxAns = 0;

void recur(int a, vector<vector<int>> &adjList, vector<int> &weighted, int minNode){
    maxAns = max(maxAns, weighted[a] - minNode);
    if(adjList[a].empty()) return;
    for(int adj: adjList[a]){
        if(weighted[adj] < minNode){
            recur(adj, adjList, weighted, weighted[adj]);
        }else{
            recur(adj, adjList, weighted, minNode);
        }
    }
}

void in_degree_cal(vector<vector<int>> &adjList, queue<int> &zero_in_deg, int n){
    vector<int> in_degree(n);
    // u->v
    for(int u = 0; u < adjList.size(); u++){
        for(auto v: adjList[u]){
            in_degree[v]++;
        }
    }

    for(int i = 0; i < n; i++){
        if(in_degree[i] == 0) zero_in_deg.push(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int V,E; cin >> V >> E;
    vector<int> weighted(V);
    for(int i = 0; i < V; i++){
        cin >> weighted[i];
    }
    vector<vector<int>> adjList(V);
    for(int i = 0; i < E; i++){
        int f,s; cin >> f >> s;
        adjList[f].push_back(s);
    }
    queue<int> zero_in_deg;
    in_degree_cal(adjList, zero_in_deg, V);

    while(!zero_in_deg.empty()){
        int root = zero_in_deg.front();
        recur(root, adjList, weighted, weighted[root]);
        zero_in_deg.pop();
    }
    cout << maxAns;

}