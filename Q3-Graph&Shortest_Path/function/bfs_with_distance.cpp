#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(int a, vector<vector<int>> &adjList, vector<int> &visited){
    queue<int> q;
    q.push(a);
    visited[a] = 0;
    while(q.size() > 0){
        int u = q.front();
        q.pop();
        for(int adj: adjList[u]){
            if(visited[adj] == -1){
                visited[adj] = visited[u] + 1;
                q.push(adj);
            }
        }
    }
}

int main(){
    int n; cin >> n;
    vector<vector<int>> adjList(n);
    for(int i = 0; i < n; i++){
        int f,s; cin >> f >> s;
        adjList[f].push_back(s);
        adjList[s].push_back(f);
    }

    vector<int> visited(n, -1);
    bfs(0, adjList, visited);
    for(int i = 0; i < n; i++){
        cout << visited[i] << ' ';
    }
}

//testcase
// 9 
// 0 1 
// 0 2 
// 1 3 
// 1 4 
// 2 5 
// 2 6 
// 2 7 
// 4 5 
// 5 8