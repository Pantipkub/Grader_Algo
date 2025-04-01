#include<iostream>
#include<vector>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n; cin >> n;
    int maxAmt = 0;
    vector<int> countVec(n);
    for(int i = 0; i < n; i++){
        int amt = 0;
        for(int j = 0; j < n; j++){
            int num; cin >> num; amt += num;
        }
        countVec[amt]++;
        maxAmt = max(amt, maxAmt);
    }
    for(int i = 0; i <= maxAmt; i++){
        cout << countVec[i] << ' ';
    }

}