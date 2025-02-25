#include<iostream>
#include<vector>

using namespace std;

int getSum(vector<vector<int>> &sumTable, int r1, int c1, int r2, int c2){
    if(r1 == 0 && c1 == 0){
        return sumTable[r2][c2];
    }else if(r1 == 0){
        return sumTable[r2][c2] - sumTable[r2][c1-1];
    }else if(c1 == 0){
        return sumTable[r2][c2] - sumTable[r1-1][c2];
    }
    return sumTable[r2][c2] - sumTable[r2][c1-1] - sumTable[r1-1][c2] + sumTable[r1-1][c1-1];
    
}

void prefixSum(vector<vector<int>> &sumTable, vector<vector<int>> &A, int N, int M){
    sumTable[0][0] = A[0][0];
    for(int col = 1; col < M; col++){
        sumTable[0][col] = sumTable[0][col-1] + A[0][col];
    }
    for(int row = 1; row < N; row++){
        sumTable[row][0] = sumTable[row-1][0] + A[row][0];
        for(int col = 1; col < M; col++){
            sumTable[row][col] = sumTable[row-1][col] + sumTable[row][col-1] - sumTable[row-1][col-1] + A[row][col];
        }
    }
}

int main(){
    int N, M, K; cin >> N >> M >> K;
    vector<vector<int>> A(N, vector<int>(M));
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
            // cout << A[i][j] << ' ';
        }
        // cout << endl;
    }
    vector<pair<pair<int,int>, pair<int,int>>> questions(K);
    for(int i = 0; i < K; i++){
        cin >> questions[i].first.first >> questions[i].first.second >> questions[i].second.first >> questions[i].second.second;
    }
    vector<vector<int>> sumTable(N, vector<int>(M));
    prefixSum(sumTable, A, N, M);
    for(auto q: questions){
        cout << getSum(sumTable, q.first.first, q.first.second, q.second.first, q.second.second);
        cout << endl;
    }
}