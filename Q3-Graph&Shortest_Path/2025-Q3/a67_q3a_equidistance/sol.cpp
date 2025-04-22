// circuit == 0 0

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<climits>

using namespace std;

vector<int> p,S;
bool flag;

int findset(int x){
    if (p[x] == -1) return x;
    //path compression
    p[x] = findset(p[x]);
    return p[x];
}

void unionIn(int x, int y){
    int s1 = findset(x);
    int s2 = findset(y);
    if(S[s1] > S[s2]){
        p[s2] = s1;
        S[s1] = S[s1] + S[s2];
    }
    else{
        p[s1] = s2;
        S[s2] = S[s1] + S[s2];
    }
}

void dfs_cd(int a, vector<vector<int>> &parentVec, vector<bool> &visited, int parent, vector<vector<int>> &adjList){
    visited[a] = true;
    for (int b : adjList[a]){
        if(visited[b] == false){
            dfs_cd(b,parentVec,visited,a, adjList);
        }
        else if(b != parent){
            // cout << "found";
            flag = true;
            return;
        }
    }
}

void bfs(int a, vector<vector<int>> &parentVec, vector<bool> &visited, vector<vector<int>> &adjList, int &count){
    count++;
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adjList[u]){
            q.push(v);
            count++;
        }
    }
}

int N,Q;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    cin >> N >> Q;
    for(int i = 0;i < Q; i++){

        vector<vector<int>> parentVec(N);
        vector<vector<int>> adjList(N);
        vector<int> indeg(N);
        bool out = false;
        for(int j = 0; j < N; j++){
            int parent; cin >> parent;
            if(parent != -1){
                --parent;
                adjList[parent].push_back(j);
            }
            if(parent == j){
                out = true;
                break;
            }
            
            parentVec[j].push_back(parent); // 1 from -1
            if(parent != -1) indeg[j]++;
        }
        
        if(out){
            cout << 0 << ' ' << 0 << endl;
            continue;
        }
                
        vector<bool> visited(N, false);
        bool endRound = false;
        flag = false;
        for(int j = 0; j < N; j++){
            vector<bool> visited(N, false);
            dfs_cd(j,parentVec,visited,parentVec[j][0],adjList);
            if(flag){
                cout << 0 << ' ' << 0 << endl;
                endRound = true;
                break;
            }
            
        }

        if(endRound) continue;
        
        int maxCount = -9999;
        for(int j = 0; j < N; j++){

            int count = 0;
            if(parentVec[j][0] == -1){

                bfs(j,parentVec,visited,adjList,count);
                maxCount = max(maxCount, count);
            }
            
        }

        cout << 1 << ' ' << maxCount << endl;

    }
}