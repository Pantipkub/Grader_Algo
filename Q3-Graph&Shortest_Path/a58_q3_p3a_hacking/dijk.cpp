#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>

using namespace std;

int N,M,K;

int main(){
    cin>>N>>M>>K;
    vector<int> start(K);
    for(int i = 0; i < K; i++){
        cin >> start[i];
    }

    vector<int> costs(N);
    for(int i = 0; i < N; i++){
        cin >> costs[i];
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i = 0; i < K; i++){
        int startNode = start[i];
        pq.push({costs[startNode], startNode});
    }

    vector<vector<int>> adjList(N);
    for(int i = 0; i < M; i++){
        int u,v; cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> dist(N, INT_MAX);
    for(int i = 0; i < K; i++){
        int startNode = start[i];
        dist[startNode] = costs[startNode];
    }  

    while(!pq.empty()){
        auto [T, u] = pq.top();
        pq.pop();
        for(auto v: adjList[u]){
            if(dist[v] > dist[u] + costs[v]){
                dist[v] = dist[u] + costs[v];
                pq.push({dist[v], v});
            }
        }
    }

    auto maxAns = max_element(dist.begin(), dist.end());

    cout << *maxAns << endl;

}