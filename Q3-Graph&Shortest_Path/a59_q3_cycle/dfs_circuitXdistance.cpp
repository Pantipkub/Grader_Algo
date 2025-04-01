#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int ans;

void dfs_cd(int a, vector<vector<int>> &adjList, vector<int> &visited, int parent, int counter){
    visited[a] = counter;
    for(int adj: adjList[a]){
        if(visited[adj] == 0){
            dfs_cd(adj, adjList, visited, a, counter+1);
        }else if(adj != parent && counter > visited[adj]){
            ans = visited[a] - visited[adj] + 1; // instead of using abs(), we trap the if case with "counter > visited[adj]"
            return;                              // เพราะยังไงตัวหลานก็ต้อง counter มากกว่าปู่เสมอ
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

    vector<int> visited(n, 0);
    dfs_cd(0, adjList, visited, -1, 1);
    cout << ans;
}