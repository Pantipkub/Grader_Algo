#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int offset[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void bfs(pair<int,int> blank, pair<int,int> parent){
    
    auto [r,c] = blank;
    for(int i = 0; i < 4; i++){
        int newr = r + offset[i][0];
        int newc = c + offset[i][1];
        if(newr >= 0 && newr < 4 && newc >= 0 && newc < 4){ // Backtracking
            if(newr == parent.first && newc == parent.second) continue;
            
        }
    }

}

vector<vector<int>> grid;

int main(){
    grid.resize(4, vector<int>(4));
    pair<int,int> blank;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 0) blank = {i,j};
        }
    }


}