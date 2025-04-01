// Hard

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int R,C,K;
int offset[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void bfs(pair<int,int> a, vector<vector<int>> &map, int group, int &count){
    queue<pair<int,int>> q;
    map[a.first][a.second] = group;
    q.push(a);
    count++;
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int newr = r + offset[i][0];
            int newc = c + offset[i][1];
            if(newr >= 0 && newr < R  && newc >= 0 && newc < C && map[newr][newc] == 0){
                count++;
                map[newr][newc] = group;
                q.push({newr,newc});
                // cout << "  -> Expanding to: (" << newr << ", " << newc << ")" << endl;
            } else {
                // cout << "  -> Skip: (" << newr << ", " << newc << ")" << endl;
            }
        }
    }
}

int main(){
    cin >> R >> C >> K;
    
    vector<vector<int>> N(R, vector<int>(C));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> N[i][j];
        }
    }

    vector<vector<int>> S(R, vector<int>(C));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> S[i][j];
        }
    }

    vector<pair<int,int>> worm(K);
    for(int i = 0; i < K; i++){
        int f,s; cin >> f >> s;
        worm[i] = {f,s};
    }

    int NorthAmt = 0;
    bfs({0,0}, N, 2, NorthAmt);
    
    vector<int> eachGroupCount(2);  //เว้นที่ไว้ 2 ช่องแรก: กรณีตกช่อง S กลุ่ม 0 กับ 1 จะไม่นับ
    int group = 1;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(S[i][j] == 0){
                // cout << i << ' ' << j << endl;
                int SouthAmt = 0;
                ++group;
                bfs({i,j}, S, group, SouthAmt);
                eachGroupCount.push_back(SouthAmt);
            } 
        }
    }

    int maxAns = 0;
    for(auto p: worm){
        auto [r, c] = p;
        int thatGroupAmt;
        int group = S[r-1][c-1]; // r-1, c-1: โจทย์ 1...R, 1...C เลยต้องแปลงเป็น 0...R-1, 0...C-1 => ไม่งั้นโปรแกรมทำงานต่อไม่ได้ (Allocating non-reserved area)
        if(N[r-1][c-1] == 2){
            thatGroupAmt = eachGroupCount[group];
        }else{
            thatGroupAmt = 0;
        }

        maxAns = max(maxAns, thatGroupAmt);
    }
    cout << NorthAmt+maxAns << endl;
}

    // for(int i = 0; i < R; i++){
    //     for(int j = 0; j < C; j++){
    //         cout << N[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << NorthAmt;