#include<iostream>
#include<vector>

using namespace std;

int R, C;
vector<char> sol; 

void permutation(vector<vector<int>> &map, int len, int r, int c){
    if(r == R-1 && c == C-1){
        for(auto x: sol){
            cout << x;
        }
        cout << endl;
        return;
    }

    map[r][c] = 2;
    if(c < C-1 && map[r][c+1] == 0){
        sol.push_back('A');
        permutation(map, len+1, r, c+1);
        map[r][c+1] = 0;
        sol.pop_back();
    }
    if(r < R-1 && map[r+1][c] == 0){
        sol.push_back('B');
        permutation(map, len+1, r+1, c);
        map[r+1][c] = 0;
        sol.pop_back();
    }
    if(r > 0 && map[r-1][c] == 0){
        sol.push_back('C');
        permutation(map, len+1, r-1, c);
        map[r-1][c] = 0;
        sol.pop_back();
    }
}

int main(){
    int value;
    cin >> R >> C;
    vector<vector<int>> map(R, vector<int>(C, 0));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
        }
    }
    int len = 0;
    permutation(map, len, 0, 0);
    cout << "DONE";
}