#include<iostream>
#include<vector>

using namespace std;

int binomial(int n, int k, vector<vector<int>> &table){
    // if(k == 0 || n == k) return 1;
    for(int i = 0; i < n; i++){
        table[i][0] = 1;
        table[i][i] = 1;
    }
    for(int row = 2; row <= n; row++){
        for(int col = 1; col < row; col++){
            table[row][col] = table[row-1][col-1] + table[row-1][col];
        }
    }
    return table[n][k];
}

int main(){
    int n, k; cin >> n >> k;
    vector<vector<int>> table(n+1, vector<int>(n+1));
    cout << binomial(n, k, table);
}