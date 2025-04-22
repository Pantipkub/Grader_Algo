#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,w; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int maxCurrent = v[0], maxGlobal = v[0];
    for(int i = 1; i < n; i++){
        maxCurrent = max(v[i], maxCurrent+v[i]);
        maxGlobal = max(maxCurrent, maxGlobal);
    }
    cout << maxGlobal;
}