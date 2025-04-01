#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<climits>

using namespace std;

vector<vector<int>> adjList;
vector<vector<int>> visited;

int bfs(queue<pair<pair<int,int>,int>> &q){
    while(!q.empty()){
        auto [group, dist] = q.front();
        auto [u, person] = group;
        q.pop();
        for(int v: adjList[u]){
            if(dist+1 < visited[v][person]){
                if(visited[v][person] == INT_MAX) visited[v][0]++;
                visited[v][person] = dist+1;
                q.push({{v, person}, dist+1});
            }

            if(visited[v][0] == 3){
                // cout << v << endl;
                int maxAns = max(max(visited[v][1], visited[v][2]), visited[v][3]);
                return maxAns;
            }
        }
    }
}

int n;

int main(){
    cin >> n;
    vector<int> start(3 + 1); // Shift 1 (Start 1)
    for(int i = 1; i <= 3; i++){
        cin >> start[i];
    }
    adjList.resize(n+1); // Shift 1
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int v; cin >> v;
            adjList[i].push_back(v);
        }
    }

    visited.resize(n+1, vector<int>(3 + 1, INT_MAX)); // visited + distance, visited[station][0] use to store the amount of friend that has arrived at this station
    queue<pair<pair<int,int>,int>> q; // {{start, person}, distance}
    for(int i = 1; i <= 3; i++){
        q.push({{start[i], i}, 0});
        int station = start[i];
        visited[station][i] = 0;
        visited[station][0] = 1;
        // cout << visited[station][1] << ' ' << visited[station][2] << ' ' << visited[station][3] << endl;
    }
   
    cout << bfs(q);
    
}

// vector<tuple<int,int,int>> visited;
// cout << get<0>(visited[1]) << ' ' << get<1>(visited[1]) << ' ' << get<2>(visited[1]);