#include<iostream>
#include<vector>

using namespace std;

vector<int> vec;

int recur(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(vec[n] != -1) return vec[n];
    return vec[n] = recur(n-1) + recur(n-2);
}

int main(){
    int n; cin >> n;
    vec.resize(n+1, -1);
    cout << recur(n);
}
