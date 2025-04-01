#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int main(){
    int N; cin >> N;
    vector<vector<pair<int,int>>> adjList(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int x; cin >> x;
            if(x != -1){
                adjList[i].push_back({j,x});
            }
        }
    }

    vector<int> dist(N, INT_MAX);
    dist[0] = 0;
    for(int i = 0; i < N-1; i++){
        for(int u = 0; u < N; u++){
            for(auto [v, cost] : adjList[u]){
                if(dist[u] != INT_MAX && dist[v] > dist[u] + cost){
                    dist[v] = dist[u] + cost;
                }
            }
        }
    }

    int minMaxAns = -1;
    bool cannotReach = false;

    for(auto x: dist){
        if(x != INT_MAX){
            minMaxAns = max(minMaxAns, x);
        }else{
            cannotReach = true;
            break;
        }
    }

    cannotReach ? cout << -1 : cout << minMaxAns << endl;
}