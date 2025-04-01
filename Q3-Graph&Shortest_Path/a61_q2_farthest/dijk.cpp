#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<set>

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
    set<pair<int,int>> s;
    s.insert({0, 0});
    while(!s.empty()){
        auto [cost, u] = *(s.begin());
        s.erase(s.begin());
        for(auto [v,w]: adjList[u]){
            if(dist[v] > w + cost){
                dist[v] = w + cost;
                s.insert({dist[v],v});
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