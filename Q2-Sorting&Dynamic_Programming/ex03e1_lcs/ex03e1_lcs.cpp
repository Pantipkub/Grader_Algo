#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> table;
string A, B;

int main(){
    cin >> A >> B;
    int n = A.length(), m = B.length();
    table.resize(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(A[i-1] == B[j-1]){
                table[i][j] = table[i-1][j-1] + 1;
            }else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    cout << table[n][m];
}

// int recur(int r, int c){
//     if(r >= B.length() || c >= A.length() || r == 0 || c == 0) return 0;
//     if(table[r][c] != 0) return table[r][c];
//     if(A[c-1] == B[r-1]){
//         table[r][c] = table[r-1][c-1] + 1;
//     }
//     if(A[c-1] != B[r-1]){
//         table[r][c] = max(recur(r+1, c), recur(r, c+1));
//     }
//     return table[r][c];
// }