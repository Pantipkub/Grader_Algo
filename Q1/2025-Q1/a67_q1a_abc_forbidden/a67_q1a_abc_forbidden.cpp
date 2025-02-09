#include<iostream>
#include<vector>
#include<map>


using namespace std;

int n, a, b, c;
vector<vector<char>> ans;

void recur(int len, vector<char> &sol, map<char, int> m, vector<string> &constraints){
    if(len < n){
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second > 0){
                // cout << endl;
                bool flag = false;
                for(string cst: constraints){
                    // cout << cst << ' ';
                    if(sol[len-1] == cst[0] && it->first == cst[1]){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    sol[len] = it->first;
                    it->second -= 1;
                    recur(len+1, sol, m, constraints);
                    it->second += 1;
                }
                
            }
        }
    }else{
        
        ans.push_back(sol);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> a >> b >> c;
    int amt; cin >> amt;

    vector<string> constraints(amt);
    for(int i = 0; i < amt; i++){
       cin >> constraints[i];
    }

    vector<char> sol(n);
    map<char, int> m;
    if(a != 0) m['A'] = a;
    if(b != 0) m['B'] = b;
    if(c != 0) m['C'] = c;

    recur(0, sol, m, constraints);

    cout << ans.size() << '\n';
    for(auto sol: ans){
        for(auto x: sol){
            cout << x;
        }
        cout << '\n';
    }
    
}