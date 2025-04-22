#include<iostream>
#include<vector>

using namespace std;

int N,M;

vector<int> own;

int main(){
    cin >> N >> M;
    own.resize(N);
    for(int i = 0; i < N; i++){
        cin >> own[i];
    }
    
}