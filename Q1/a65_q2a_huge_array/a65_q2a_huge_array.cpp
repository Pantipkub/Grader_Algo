#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int N,Q,X,C;
    cin >> N >> Q;
    vector<pair<int,int>> v(N);
    for(int i = 0; i < N; i++){
        cin >> X >> C;
        v[i] = {X,C};
        // cout << v[i].first << ' ' << v[i].second;
    }

    vector<int> prefixSum(N); //ตำแหน่งสะสม
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++){
        prefixSum[i] = v[i].second;
        if(i > 0) prefixSum[i] += prefixSum[i-1];
    }

    for(int i = 0; i < Q; i++){
        int num; cin >> num;
        int index = lower_bound(prefixSum.begin(), prefixSum.end(), num) - prefixSum.begin();
        cout << v[index].first << endl;
    }

}