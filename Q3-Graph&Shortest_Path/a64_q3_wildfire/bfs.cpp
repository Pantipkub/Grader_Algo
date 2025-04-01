#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m,k;
int btValue = 0;

void bfs(int a, vector<vector<int>> &adjList, vector<int> &field){
    queue<int> q; q.push(a);
    btValue -= field[a];
    field[a] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adjList[u]){
            if(field[v] != 0){
                btValue -= field[v];
                field[v] = 0;
                q.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    vector<int> field(n), fire(k);
    vector<vector<int>> adjList(n);
    for(int i = 0; i < n; i++){
        cin >> field[i];
        btValue += field[i];
    }
    for(int i = 0; i < k; i++){
        cin >> fire[i];
    }
    for(int i = 0; i < m; i++){
        int f,s; cin >> f >> s;
        adjList[f].push_back(s);
    }
    for(int i = 0; i < k; i++){
        bfs(fire[i], adjList, field);
        cout << btValue << ' ';
    }

    return 0;
}
