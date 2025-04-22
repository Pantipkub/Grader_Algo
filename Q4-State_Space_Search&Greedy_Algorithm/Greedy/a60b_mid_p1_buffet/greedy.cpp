#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int f,w,n; cin >> f >> w >> n;
    int range = w+1+w; // ex. w = 2 -> 2 + 1 + 2
    vector<int> foods(f);
    for(int i = 0; i < f; i++){
        cin >> foods[i];
    }
    sort(foods.begin(),foods.end());
    
    int end = 0, ans = 0;
    for(int i = 0; i < f; i++){
        if(foods[i] > end){
            ans++;
            end = foods[i]+range-1;
        }
    }

    cout << ans << '\n';
}