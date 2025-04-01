#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int N,M,K; cin>>N>>M>>K;
    int V; cin>>V;

    vector<int> start(K);
    for(int i = 0; i < K; i++) cin >> start[i];

    // reversed graph
    vector<vector<pair<int,int>>> revAdjList(N);
    for(int i = 0; i < M; i++){
        int a,b,w; cin>>a>>b>>w;
        revAdjList[b].push_back({a,w});
    }

    vector<int> dist(N, INT_MAX);
    dist[V] = 0;

    for(int i = 0; i < N-1; i++){
        for(int u = 0; u < N; u++){
            for(auto [v, w]: revAdjList[u]){
                if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    int minAns = INT_MAX;
    for(auto s: start){
        minAns = min(minAns, dist[s]);
    }
    
    // ไว้ใช้เช็คว่า มีเส้นทางไปถึงจริงๆใช่มั้ย ถ้าโจทย์ไม่รับประกัน
    if (minAns == INT_MAX) cout << "-1\n";
    else cout << minAns << "\n";
}