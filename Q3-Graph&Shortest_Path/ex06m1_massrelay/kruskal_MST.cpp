#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<climits>

using namespace std;

int N,M,Q;

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
    }else{
        p[s1] = s2;
        S[s2] = S[s1] + S[s2];
    }
}

int main(){
    cin >> N >> M >> Q;
    vector<tuple<int,int,int>> edges(M);
    for(int i = 0; i < M; i++){
        int a,b,w; cin >> a >> b >> w;
        edges[i] = {w,a,b};
    }

    sort(edges.begin(), edges.end());

    vector<int> questions(Q);
    for(int q = 0; q < Q; q++){
        cin >> questions[q];
    }

    p.assign(N,-1); // assign ?
    S.assign(N,1);
    
    vector<int> possibleEdges;
    for(auto [w,u,v]: edges){
        if(findSet(u) != findSet(v)){
            unionIn(u, v);
            possibleEdges.push_back(w);
        }
    }

    // Not necessary to have this line because we already sort once before looping
    // sort(possibleEdges.begin(), possibleEdges.end());
    
    for(auto q: questions){
        cout << possibleEdges[possibleEdges.size() - q] << '\n';
    }
}