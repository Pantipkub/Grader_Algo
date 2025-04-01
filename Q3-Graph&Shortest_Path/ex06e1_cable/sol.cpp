#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

int N;

vector<int> p,S;

int findSet(int x){
    if(p[x] == -1) return x;
    //path compression
    p[x] = findSet(p[x]);
    return p[x];
}

void unionIn(int x, int y){
    int s1 = findSet(x);
    int s2 = findSet(y);
    if(S[s1] > S[s2]){
        p[s2] = s1;
        S[s1] = S[s1] + S[s2];
    }
    else{
        p[s1] = s2;
        S[s2] = S[s1] + S[s2];
    }
}

int main(){
    cin >> N;
    p.resize(N, -1);
    S.resize(N, 1);
    vector<vector<int>> adjList(N);
    vector<tuple<int,int,int>> edges;
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j <= N-1; j++){
            int x; cin >> x;
            edges.push_back({x, i, j});
        }
    }
    
    int ans = 0;
    sort(edges.begin(), edges.end());
    
    for(auto x: edges){
        auto [cost,f,s] = x;
        if(findSet(f) != findSet(s)){
            unionIn(f, s);
            ans += cost;
        }
    }
    cout << ans;
}