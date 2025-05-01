#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<climits>

using namespace std;

int R,C, K;
vector<vector<int>> grid;
queue<pair<int,int>> start;
vector<vector<vector<int>>> vectors;

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

void bfs(pair<int,int> p, vector<vector<int>> &visited){
    queue<pair<int,int>> q; q.push(p);
    visited[p.first][p.second] = 0;
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int newr = r + dr[i];
            int newc = c + dc[i];
            if(newr >= 0 && newr < R && newc >= 0 && newc < C && grid[newr][newc] != 1){
                if(visited[newr][newc] == -1){
                    visited[newr][newc] = visited[r][c] + 1;
                    q.push({newr,newc});
                }
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    cin >> R >> C >> K;
    grid.resize(R, vector<int>(C));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 2) start.push({i,j});
        }
    }

    int N = start.size();
    vectors.resize(N, vector<vector<int>>(R, vector<int>(C, -1)));
    for(int i = 0; i < N; i++){
        pair<int,int> p = start.front();
        start.pop();
        bfs(p, vectors[i]);
    }

    int count = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(grid[i][j] == 1) continue;

            bool allReachable = true;
            int maxDist = INT_MIN, minDist = INT_MAX;
            for(int k = 0; k < N; k++){
                if(vectors[k][i][j] == -1){
                    allReachable = false;
                    break;
                }
                minDist = min(minDist, vectors[k][i][j]);
                maxDist = max(maxDist, vectors[k][i][j]);
            }
            
            if(allReachable && abs(maxDist - minDist) <= K) count++;
        }
    }

    cout << count;
}
