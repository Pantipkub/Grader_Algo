#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

void dfs(int a, vector<vector<int>> &adjList, vector<int> &visited){
    stack<int> st;
    st.push(a);
    visited[a] = 0;
    while(st.size() > 0){
        int u = st.top();
        st.pop();
        for(int adj: adjList[u]){
            if(visited[adj] == -1){
                visited[adj] = visited[u] + 1;
                st.push(adj);
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
        sort(adjList[f].begin(), adjList[f].end());
        sort(adjList[s].begin(), adjList[s].end());
    }

    vector<int> visited(n, -1);
    dfs(0, adjList, visited);
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