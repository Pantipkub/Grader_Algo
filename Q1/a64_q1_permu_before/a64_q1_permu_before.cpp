#include<iostream>
#include<vector>

using namespace std;

int n, m;

void my_recur(int len, vector<int> &sol, vector<bool> &used, vector<pair<int, int>> constraints){
    if(len < n){
        for(auto constraint: constraints){
            if(used[constraint.second] && !used[constraint.first]) return;
        }
        for(int i = 0; i < n; i++){
            if(!used[i]){
                sol[len] = i;
                used[i] = true;
                my_recur(len+1, sol, used, constraints);
                used[i] = false;
            }
        }
    }else{
        for(auto x: sol){
            cout << x << ' ';
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    int a, b;
    vector<pair<int, int>> constraints(m);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        constraints[i] = {a, b};
    }

    vector<int> sol(n);
    vector<bool> used(n);
    my_recur(0, sol, used, constraints);
}