#include<iostream>
#include<vector>

using namespace std;

int binary_search_near(vector<int> &sorted_candidates, int data){
    int left = 0, right = sorted_candidates.size() - 1, best = -1;

    while(left <= right){
        int mid = (left+right)/2;
        if(sorted_candidates[mid] <= data){
            best = sorted_candidates[mid];
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return best;
}

int main(){
    int N,M; cin >> N >> M;
    vector<int> sorted_candidates(N);
    for(int i = 0; i < N; i++){
        cin >> sorted_candidates[i];
    }
    for(int i = 0; i < M; i++){
        int data; cin >> data;
        cout << binary_search_near(sorted_candidates, data) << endl;
    }
}