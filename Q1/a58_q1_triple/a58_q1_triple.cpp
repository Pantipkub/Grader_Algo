#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,M;

bool check(int query, vector<int> &v){
    //in order of: left, middle, right
    for(int left = 0; left < N-2; left++){   
        int middle = left+1;
        int right = N-1;
        while(middle < right){
            int sum = v[left] + v[middle] + v[right];
            if(sum == query) return true;
            else if(sum < query) middle++;
            else right--;
        }
    }
    return false;
}

int main(){
    cin >> N >> M;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }
    int query;
    for(int i = 0; i < M; i++){
        cin >> query;
        cout << (check(query, vec) ? "YES" : "NO") << endl;
    }
}