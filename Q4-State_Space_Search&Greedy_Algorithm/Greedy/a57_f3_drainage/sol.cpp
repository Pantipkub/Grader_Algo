#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N,L; cin >> N >> L;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int end = 0, ans = 0;
    for(int i = 0; i < N; i++){
        if(v[i] > end){
            end = v[i] + L - 1;
            ans++;
        }
    }

    cout << ans << '\n';
}