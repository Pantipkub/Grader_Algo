#include<iostream>
#include<vector>
#include<set>
#include<tuple>
#include<climits>

using namespace std;

int offset[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int main(){
    int R,C; cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
    dist[0][0] = 0;
    set<tuple<int, int, int>> s;
    s.insert({0,0,0});
    while(!s.empty()){
        auto [cost, x, y] = *(s.begin());
        s.erase(s.begin());
        if(cost > dist[y][x]) continue;

        for(int dir = 0; dir < 4; dir++){
            int newx = x + offset[dir][0]; 
            int newy = y + offset[dir][1];
            if((newx >= 0) && (newx < C) && (newy >= 0) && (newy < R)){
                int newCost = dist[y][x] + grid[newy][newx];
                if(newCost < dist[newy][newx]){
                    dist[newy][newx] = newCost;
                    s.insert({newCost, newx, newy});
                }
            }
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
          cout << dist[i][j] << " ";
        }
        cout << endl;
      }
      return 0;
    
}