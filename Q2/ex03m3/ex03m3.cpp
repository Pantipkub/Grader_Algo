#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<int> cost;
vector<int> sum;

int recur(int n, int k){
    if(n < 0) return 0;
    if(sum[n] != INT_MAX) return sum[n];
    int bestChild = cost[n];
    for(int i = 0; i < k; i++){
        bestChild = min(bestChild, recur(n-(i+1), k));
    }
    cout << bestChild << endl;
    return sum[n] = bestChild;
}

int main(){
    int n, k; cin >> n >> k;
    cost.resize(n);
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    sum.resize(n, INT_MAX);
    for(int i = 0; i < k+1; i++){
        sum[i] = cost[i];
    }
    cout << recur(n-1, k);
}