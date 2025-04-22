#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N; cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    
    int lIdx = 0, rIdx = N-1;
    int lMax = v[lIdx], rMax = v[rIdx];
    while(lIdx < rIdx){
        
    }
}