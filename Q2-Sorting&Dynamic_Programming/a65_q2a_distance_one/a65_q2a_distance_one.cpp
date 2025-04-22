#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    int table[n+1];
    for(int i = 1; i <= k; i++){
        table[i] = i+1;
    }
    for(int i = k+1; i <= n; i++){
        table[i] = (table[i-1] + table[i-k])%100000007;
    }
    cout << table[n];
}