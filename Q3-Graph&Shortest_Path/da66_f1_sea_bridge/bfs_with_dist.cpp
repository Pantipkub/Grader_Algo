/*IMPORTANT! ถ้าข้อนี้ไม่ใส่ dist เพื่อจดจำระยะทางที่ดีที่สุดไว้ เพื่อดักเคส 
มันจะทำให้ส่งไปทำงานซ้ำๆ จน Mem ระเบิด และ Timeout
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int R,C;
int offset[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int count = 2;

vector<vector<int>> dist;

int bfs(queue<pair<pair<int,int>,int>> &q, vector<vector<int>> &grid){
    while(!q.empty()){
        auto [pos, len] = q.front();
        auto [r, c] = pos;
        q.pop();
        for(int i = 0; i < 4; i++){
            int newr = r + offset[i][0];
            int newc = c + offset[i][1];
            if(newr >= 0 && newr < R  && newc >= 0 && newc < C){
                if(grid[newr][newc] == 3) continue;
                else if(grid[newr][newc] == 2) return len;
                else if(grid[newr][newc] == 0){
                    if(len+1 < dist[newr][newc]){
                        q.push({{newr, newc}, len+1});
                        dist[newr][newc] = len+1;
                    }
                }
            }
        }
    }
    return 2;
}

int main(){
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C));
    dist.resize(R, vector<int>(C));
    queue<pair<pair<int,int>,int>> q;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                q.push({{i,j}, 2});
                dist[i][j] = 1;
            }else{
                dist[i][j] = 1e9;
            }
        }
    }

    cout << bfs(q, grid);
}
