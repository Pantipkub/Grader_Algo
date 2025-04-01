#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

int ans = 0;

void dfs_cc(int a, vector<vector<int>> &adjList, vector<int> &component, int cc_num, vector<int> &parent) {
    component[a] = cc_num;
    stack<int> q;
    q.push(a);
    bool isLine = true;
    
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        
        if (adjList[u].size() >= 3) isLine = false;
        
        for (int v : adjList[u]) {
            if (component[v] == -1) {  // hasn't been visited
                component[v] = cc_num;
                parent[v] = u;  // v's parent will be updated when "v" node get pushed into a stack
                q.push(v);
            } else if (v != parent[u]) {  // detect a circuit, elif block means "not a node we just recently traverse from"
                isLine = false;
            }
        }
    }
    
    if (isLine) ans++;
}


int main(){
    int v,e; cin >> v >> e;
    vector<vector<int>> adjList(v);
    for(int i = 0; i < e; i++){
        int f,s; cin >> f >> s;
        adjList[f].push_back(s);
        adjList[s].push_back(f);
    }

    // grouping each component
    vector<int> component(v, -1);
    int cc_num = 0;
    for(int i = 0; i < v; i++){
        vector<int> parent(v, -1);
        if(component[i] == -1){
            ++cc_num;
            dfs_cc(i, adjList, component, cc_num, parent);
        }
    }

    cout << ans;
}

//deg >= 3  -> wrong
//circuit   -> wrong