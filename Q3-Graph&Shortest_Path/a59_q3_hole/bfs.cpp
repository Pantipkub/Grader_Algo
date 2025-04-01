/*If N over 10,000 => Using too much memory*/

#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

int N,a,b;
vector<vector<int>> field(10000, vector<int>(10000));
vector<vector<int>> holeCount(10000, vector<int>(10000, INT_MAX));

int offset[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int minAns = INT_MAX;

void bfs(pair<pair<int,int>,int> home){
    queue<pair<pair<int,int>,int>> q;
    q.push(home);
    holeCount[home.first.first][home.first.second] = 0;
    while(!q.empty()){
        auto [pos, count] = q.front();
        auto [x,y] = pos;
        q.pop();
        for(int i = 0; i < 4; i++){
            int newx = x + offset[i][0];
            int newy = y + offset[i][1];
            if(newx >= 0 && newx < 10000 && newy >= 0 && newy < 10000){
                if(count < holeCount[newx][newy]){
                    if(field[newx][newy] == 1){
                        holeCount[newx][newy] = count+1;
                        q.push({{newx,newy}, count+1});
                    }else{
                        holeCount[newx][newy] = count;
                        q.push({{newx,newy}, count});
                    }
                }
            }
            else{ //Already reached border
                minAns = min(minAns, count);
            }
        }
    }
}

int main(){
    cin >> N >> a >> b;
    a--; b--;
    for(int i = 0; i < N; i++){
        int x,y; cin >> x >> y;
        x--; y--;
        field[x][y] = 1;
    }
    bfs({make_pair(a,b), 0});
    cout << minAns;

}   