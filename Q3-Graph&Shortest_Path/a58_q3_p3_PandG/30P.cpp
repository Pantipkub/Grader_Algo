#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>

using namespace std;

int R,C,n,T,r,c;
int offset[5][2] = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<bool>> map;

void bfs(vector<vector<int>> &visited, priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> &q){
    int clock = 0;
    while(!q.empty()){
        if(clock < T){
            auto [time, row, col] = q.top();
            if(time < clock){
                clock++;
            }else{
                q.pop();
                if(map[row][col] && visited[row][col] != 2){
                    visited[row][col] = 2;
                }
                for(int i = 0; i < 5; i++){
                    int newr = row + offset[i][0];
                    int newc = col + offset[i][1];
                    if(newr >= 0 && newr < R && newc >= 0 && newc < C){
                        q.push({time+1, newr, newc});
                    }
                }
            }
        }
    }
}

int main(){
    int N; cin >> N;
    
    while(N--){

        cin >> R >> C >> n >> T >> r >> c;
        vector<tuple<int,int,int>> ghosts(n);
        for(int i = 0; i < n; i++){
            int t,rBirth,cBirth; cin >> t >> rBirth >> cBirth;
            ghosts[i] = {t,rBirth,cBirth};
        }
    
        map.assign(R, vector<bool>(C));
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                char x; cin >> x;
                if(x == '.') map[i][j] = true;
                else map[i][j] = false;
            }
        }
        
        vector<vector<int>> pManVisited(R, vector<int>(C));
        pManVisited[r][c] = 2;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q1;
        q1.push({0,r,c});
        bfs(pManVisited, q1);

        vector<vector<int>> ghostsVisited(R, vector<int>(C));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q2;
        // sort(ghosts.begin(), ghosts.end());
        for(int i = 0; i < n; i++){
            q2.push(ghosts[i]);
        }
        bfs(ghostsVisited, q2);

        bool flag = false;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(pManVisited[i][j] == 2 && ghostsVisited[i][j] != 2){
                    flag = true;
                }
            }
        }

        flag ? cout << "YES" : cout << "NO";
        cout << '\n';
    }
}