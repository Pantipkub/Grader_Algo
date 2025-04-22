#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,e,k;
int count = 0;

void bfs(int a, vector<vector<int>> &adjList, vector<int> &visited){
    queue<int> q;
    visited[a] = 0;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adjList[u]){
            if(visited[v] == -1){
                visited[v] = visited[u]+1;
                q.push(v);
            }
        }
    }
}

int main(){
    cin>>n>>e>>k;
    vector<vector<int>> adjList(n+1);
    for(int i = 0; i < e; i++){
        int f,s; cin>>f>>s;
        adjList[f].push_back(s);
        adjList[s].push_back(f);
    }
    vector<int> visited(n+1, -1);
    bfs(0, adjList, visited);
    for(int i = 0; i < n+1; i++){
        if(visited[i] == k) count++;
    }
    cout << count;
}
