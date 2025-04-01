#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int offset[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int r,c,T; 
int count = 0;

void bfs(pair<pair<int,int>,int> curA, vector<vector<int>> &map, vector<vector<int>> &visited){
    count++;
    queue<pair<pair<int,int>,int>> q;
    q.push(curA);
    while(!q.empty()){
        int x = q.front().first.first, y = q.front().first.second;
        int day = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int newx = x + offset[i][0];
            int newy = y + offset[i][1];
            if((newx >= 0) && (newx < r) && (newy >= 0) && (newy < c)){
                if(visited[newx][newy] > 0) continue;
                if(map[newx][newy] == 2) continue;
                if(day >= T) continue;
                visited[newx][newy] = 1;
                q.push({{newx, newy}, day+1});
                if(map[newx][newy] == 0){
                    // cout << x << ' ' << y << endl;
                    map[newx][newy] = 1;
                    ++count;
                }
            }
        }
    }
}



int main(){
    cin>>r>>c>>T;
    vector<vector<int>> map(r, vector<int>(c));
    vector<pair<int,int>> starter;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) starter.push_back({i,j});
        }
    }


    for(int i = 0; i < starter.size(); i++){
        vector<vector<int>> visited(r, vector<int>(c));
        bfs({starter[i], 0}, map, visited);
    }

    cout << count;

    return 0;
}