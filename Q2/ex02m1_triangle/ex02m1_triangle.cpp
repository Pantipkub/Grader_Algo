#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> vec;
vector<vector<int>> table;
int n; 

int recur(int level, int k){
    if(level >= n || k >= n) return 0;
    if(table[level][k] != -1) return table[level][k];
    int left = recur(level+1, k);
    int right = recur(level+1, k+1);
    table[level][k] = max(left, right) + vec[level][k];
    return table[level][k];
}

int main(){
    cin >> n;
    vec.resize(n, vector<int>(n));
    table.resize(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            cin >> vec[i][j];
        }
    }
    cout << recur(0, 0);
}