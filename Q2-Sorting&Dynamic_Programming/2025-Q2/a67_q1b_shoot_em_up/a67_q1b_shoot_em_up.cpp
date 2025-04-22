#include<iostream>
#include<vector>

using namespace std;

int N, W, B; 

void recur(int level, int n, vector<string> &vec, vector<string> &ans){
    if(n < N){
        if(level - 1 != 0){
            ans[n] = "D";
            recur(level-1, n+1, vec, ans);
        }

        ans[n] = "S";
        recur(level, n+1, vec, ans);

        if(level + 1 != W+1){
            ans[n] = "U";
            recur(level+1, n+1, vec, ans);
        }
    }else{
        for(auto x: ans){
            cout << x;
        }
        cout << '\n';
    }
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    cin >> N >> W >> B;
    vector<string> vec = {"D", "S", "U"};
    vector<string> ans(N);
    recur(B, 0, vec, ans);
}