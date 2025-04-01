#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int R,C,K;
int count = 0;
int offset[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void bfs(pair<int,int> a, vector<vector<int>> &temp, vector<vector<int>> &real){
    queue<pair<int,int>> q;
    temp[a.first][a.second] = 2;
    q.push(a);
    count++;
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int newr = r + offset[i][0];
            int newc = c + offset[i][1];
            if(newr >= 0 && newr < R  && newc >= 0 && newc < C){
                if(temp[newr][newc] == 2) continue;
                if(real[newr][newc] == 0){
                    // cout << count << ' ' <<  newr << ' ' << newc << endl;
                    count++;
                    temp[newr][newc] = 2;
                    q.push({newr,newc});
                }
            }
        }
    }
}

int main(){
    cin >> R >> C >> K;
    vector<vector<int>> N(R, vector<int>(C)), S(R, vector<int>(C));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> N[i][j];
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> S[i][j];
        }
    }

    int bestAns = 1;
    for(int i = 0; i < K; i++){
        int f,s; cin >> f >> s;
        count = 0;
        vector<vector<int>> tempN(N);
        vector<vector<int>> tempS(S);
        bfs({0,0}, tempN, N);
        if(tempN[f-1][s-1] == 2 && tempS[f-1][s-1] == 0){
            bfs({f-1,s-1}, tempS, S);
        }
        bestAns = max(bestAns, count);
    }
    cout << bestAns;
}