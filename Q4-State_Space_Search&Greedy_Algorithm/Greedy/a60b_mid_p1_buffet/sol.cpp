#include<iostream>
#include<vector>

using namespace std;

int main(){
    int f,w,n; cin >> f >> w >> n;
    int range = w+1+w; // ex. w = 2 -> 2 + 1 + 2
    vector<int> table(n);
    for(int i = 0; i < f; i++){
        int x; cin >> x; 
        x--;
        table[x] = 1;   // has food in this index
    }

    bool newfound = false;
    int count = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(table[i] == 1 && !newfound){
            newfound = true;
            count = 0;
            ans++;
        }

        if(count == range-1){
            newfound = false;
        }

        count++;
    }

    cout << ans << '\n';
}