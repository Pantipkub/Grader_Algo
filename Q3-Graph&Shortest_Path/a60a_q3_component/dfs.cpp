#include<iostream>
#include<vector>

using namespace std;

int V,E;

//the node will spread the cc_num to each connected friend node
void dfs_cc(int a, int cc_num, vector<vector<int>> &adj_list, vector<int> &visited){
    visited[a] = cc_num;
    for(auto adj: adj_list[a]){
        if(visited[adj] == 0){
            dfs_cc(adj, cc_num, adj_list, visited);
        }
    }
}

int main(){
    cin >> V >> E;
    vector<vector<int>> adj_list(V+1);
    for(int i = 0; i < E; i++){
        int f,s; cin >> f >> s;
        adj_list[f].push_back(s);
        adj_list[s].push_back(f);
    }

    int cc_num = 0;
    vector<int> visited(V+1, 0);

    //the other node which isn't spreaded from any other nodes before, will create a new cc_num group
    //then it'll spread the cc_num to the other connected nodes by calling dfs_cc
    for(int u = 1; u <= V; u++){
        if(visited[u] == 0){
            cc_num += 1;
            dfs_cc(u, cc_num, adj_list, visited);
        }
    }
    cout << cc_num;
}