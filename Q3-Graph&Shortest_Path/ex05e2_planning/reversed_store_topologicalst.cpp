#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N;

int main(){
    cin >> N;
    vector<vector<int>> adjList(N);
    vector<int> indeg(N);
    queue<int> q;
    for(int i = 0; i < N; i++){
        int c; cin >> c;
        indeg[i] = c;
        if(c == 0){
            q.push(i);
        }
        for(int j = 0; j < c; j++){
            int f; cin >> f; 
            adjList[f].push_back(i);    // not adjList[i].push_back(f);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int v: adjList[u]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
            }
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }

}