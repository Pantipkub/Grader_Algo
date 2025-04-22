#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

int N,M,K;
vector<int> places;

int minAns = INT_MAX;

void bfs(int u, int &sum, vector<int> &visited){
    int count = 1;
    while(!q.empty()){
        auto u = q.front();
        for(auto [v, cost] : adjList[u]){
            sum += cost;
            if(sum > minAns) continue;; //BT
            if(visited[v] == 0){
                for(int x: places){
                    if(v == x){
                        count++;
                    }
                }
            }
            if(count)
        }
    }
}   

int main(){
    cin >> N >> M >> K;
    places.resize(K);
    for(int i = 0; i < K; i++){
        cin >> places[i];
    }

    sort(places.begin(), places.end());

    vector<vector<pair<int,int>>> adjList(N);
    for(int i = 0; i < M; i++){
        int f,s,cost; cin >> f >> s >> cost;
        adjList[f].push_back({s,cost});
        adjList[s].push_back({f,cost});
    }


    for(int i = 0; i < K; i++){
        queue<int> q;
        q.push(places[i]);

        int sum = 0;
        vector<int> visited(N+1);
        bfs(q, sum, visited);
    }

}