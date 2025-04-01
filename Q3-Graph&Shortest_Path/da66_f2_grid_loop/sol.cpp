#include<iostream>
#include<vector>

using namespace std;

int maxCCsize = 0, CCamount = 0;

// Possible moves based on cell type
int moves[6][2][2] = {
    {{0, -1}, {0, 1}},  // Type 1: Left-Right
    {{-1, 0}, {1, 0}},  // Type 2: Up-Down
    {{-1, 0}, {0, 1}},  // Type 3: Up-Right
    {{0, 1}, {1, 0}},   // Type 4: Right-Down
    {{1, 0}, {0, -1}},  // Type 5: Down-Left
    {{0, -1}, {-1, 0}}  // Type 6: Left-Up
};

void dfs(pair<int,int> curP, vector<vector<vector<pair<int,int>>>> &adjList2D, vector<vector<int>> &visited, int counter, pair<int,int> parent){
    int r = curP.first, c = curP.second;
    // cout << "Visiting: (" << r << "," << c << ") at step " << counter << endl; // Debug
    visited[r][c] = counter;
    
    for(auto adjP: adjList2D[r][c]){
        if(adjP == parent) continue;

        // For checking if the friend node has the path connect back to the current node 
        bool flag = false;
        for(auto x: adjList2D[adjP.first][adjP.second]){
            if(x == make_pair(r,c)){ 
                flag = true;
                break;
            }
        }

        if(flag){ // Does it connected back to the current one?
            if(visited[adjP.first][adjP.second] == 0){
                dfs(adjP, adjList2D, visited, counter+1, curP); 
            } 
            else if(visited[adjP.first][adjP.second] < counter){  // Is it a real ancestor
                int endPoint = visited[adjP.first][adjP.second];
                maxCCsize = max(maxCCsize, abs(counter - endPoint) + 1);
                CCamount++;
                // cout << "Cycle detected at: (" << adjP.first << "," << adjP.second << ")" << endl;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int R,C; cin >> R >> C;
    vector<vector<vector<pair<int,int>>>> adjList2D(R, vector<vector<pair<int,int>>>(C));
    
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            int type; cin >> type;
            // each type can connect with 2 different ways
            for(int i = 0; i < 2; i++){
                int nr = r + moves[type-1][i][0];
                int nc = c + moves[type-1][i][1];
                if((nr >= 0) && (nr < R) && (nc >= 0) && (nc < C)){
                    adjList2D[r][c].push_back({nr, nc});
                }
            }
        }
    }
    
    vector<vector<int>> visited(R, vector<int>(C, 0));

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(visited[i][j] == 0){
                int counter = 1;
                dfs({i, j}, adjList2D, visited, counter, {-1,-1});
            }
        }
    }
    
    cout << CCamount << ' ' << maxCCsize << '\n';
    
    return 0;
}