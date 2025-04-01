#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>

using namespace std;

int N;
vector<vector<int>> adjList;
vector<int> sol;

void bfs_dist(int a, map<int,int> &indeg){
    stack<pair<int,int>> q; // u,count
    vector<int> dist(N);
    q.push({a, 1});
    dist[a] = 1;
    int maxPathLength = INT_MIN;
    while(!q.empty()){
        auto [u, count] = q.top();
        q.pop();
        for(int v: adjList[u]){
            if(dist[v] == 0){
                indeg[v]--;
                dist[v] = count+1;
                q.push({v,count+1});
            }else{ // circuit detected
                int pathLength = abs(dist[v] - dist[u]) + 1;
                maxPathLength = max(maxPathLength, pathLength);
            }
        }
    }
    sol.push_back(maxPathLength);
}

int main(){
    cin >> N;
    map<int, int> indeg;
    adjList.resize(N);
    for(int i = 0; i < N; i++){
        int M; cin >> M;
        for(int j = 0; j < M; j++){
            int x; cin >> x;
            indeg[i]++;
            adjList[i].push_back(x);
        }
    }

    queue<int> q;
    for(int i = 0; i < N; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        sol.push_back(1);
        int u = q.front();
        q.pop();
        for(auto v: adjList[u]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(indeg[i] > 0){
            bfs_dist(i, indeg);
        }
    }

    for(auto x: sol){
        cout << x << ' ';
    }
}