#include<iostream>
#include<vector>

using namespace std;

int N,M;

int bsearch(vector<int> &v, int data){
    int left = 0, right = N-1, best = -1;
    while(left <= right){
        int mid = (left+right) >> 1; //divide by 2
        if(data >= v[mid]){
            best = mid;
            left = mid+1;
        }
        else if(v[mid] > data) right = mid-1;
    }
    return best;
}

int main(){
    cin >> N >> M;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    for(int i = 0; i < M; i++){
        int data; cin >> data;
        cout << bsearch(v, data) << endl;
    }
}