#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int r,c; cin >> r >> c;
    vector<vector<int>> m(r, vector<int>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char x; cin >> x;
            if(x == '.') m[i][j] = 0;
            else if(x == '#') m[i][j] = 1;
        }
    }
    vector<vector<int>> d(r, vector<int>(c, -1));   //-1 == hasn't been visited
    int offset[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    d[0][0] = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        pair<int,int> a = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            pair<int,int> b(a.first+offset[i][0], a.second+offset[i][1]);   //every steps, include N,E,S,W
            if((b.first < 0) || (b.first >= r) || (b.second < 0) || (b.second >= c)) continue;  //border
            if(d[b.first][b.second] != -1) continue;    //this block has been visited, skip
            if(m[b.first][b.second] == 1) continue;     //this block has an obstacle, skip
            d[b.first][b.second] = d[a.first][a.second] + 1;    //adding path length by 1
            q.push(b);
        }
    }
    cout << d[r-1][c-1] << '\n';
}