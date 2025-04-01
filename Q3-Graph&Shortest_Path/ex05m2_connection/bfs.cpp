#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N,E,K; 
int maxAns = 0;

int count;

void bfs(int a, vector<vector<int>> &adjList, vector<int> &dist){
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    count = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adjList[u]){
            if(dist[u] >= K) continue;  //If the current node already reached K value, we won't traverse more after this node 
            if(dist[v] == -1){
                count++;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    cin >> N >> E >> K;
    vector<vector<int>> adjList(N);
    vector<int> degree(N);
    for(int i = 0; i < E; i++){
        int f,s; cin >> f >> s;
        adjList[f].push_back(s);
        adjList[s].push_back(f);
    }
    for(int i = 0; i < N; i++){
        vector<int> dist(N, -1);
        bfs(i, adjList, dist);
        maxAns = max(maxAns, count);
    }
    cout << maxAns << '\n';
}

//Really? Not timeout?