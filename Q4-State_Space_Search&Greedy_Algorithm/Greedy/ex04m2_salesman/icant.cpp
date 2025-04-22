#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N,M; cin >> N >> M;
    vector<int> orders(M);
    for(int i = 0; i < M; i++){
        cin >> orders[i];
    }

    vector<int> costs(M);
    for(int i = 0; i < M; i++){
        cin >> costs[i];
    }

    for(int i = 0; i < N; i++){
        int f,s; cin >> f >> s;
        pair<int,int> portal = {f,s};

        
    }
}