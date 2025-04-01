#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

int R,C,K;
int offset[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int counter = 0;

void bfs(vector<vector<int>> &grid, queue<pair<pair<int,int>,int>> &q){
    
    while(!q.empty()){
        auto [pos, d] = q.front();
        auto [x, y] = pos;
        q.pop();
        for(int i = 0; i < 4; i++){
            int newx = x + offset[i][0];
            int newy = y + offset[i][1];
            if(newx >= 0 && newx < R && newy >= 0 && newy < C){
                if(grid[newx][newy] == 0 && d < K){
                    ++counter;
                    grid[newx][newy] = 1;
                    q.push({{newx, newy}, d+1});
                }
            }
        }
    }
}   

int main(){
    cin>>R>>C>>K;
    vector<vector<int>> grid(R, vector<int>(C));
    queue<pair<pair<int,int>,int>> q;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                q.push({{i,j},0});
                ++counter;
            }
        }
    }
    
    bfs(grid, q);

    cout << counter << '\n';
}
