#include<iostream>
#include<vector>

using namespace std;

bool dfs_cd(int a, vector<bool> &visited, vector<vector<int>> &adj_list, int parent){
    visited[a] = true;
    for(auto homie: adj_list[a]){   //homie means to the friend node of {a}
        if(visited[homie] == false){    //observing forward: homie have not visited yet
            return dfs_cd(homie, visited, adj_list, a);
        }else if(homie != parent){      //observing backward: homie has been visited and homie isn't a parent node
            return true;
        }
    }
    return false;
}

int main(){
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        int V,E; cin >> V >> E;
        vector<vector<int>> adj_list(V);
        for(int i = 0; i < E; i++){
            int f,s; cin >> f >> s;
            adj_list[f].push_back(s);
            adj_list[s].push_back(f);
        }
        
        int flag = false;
        vector<bool> visited(V, false);
        for(int u = 0; u < V; u++){
            if(visited[u] == false){
                if(dfs_cd(u, visited, adj_list, -1)){
                    flag = true;
                    break;
                }
            }
        }
        flag ? cout << "YES": cout << "NO";
        cout << endl;
    }
}