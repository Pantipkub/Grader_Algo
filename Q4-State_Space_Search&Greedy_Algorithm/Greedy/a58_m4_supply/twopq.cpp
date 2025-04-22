#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>

using namespace std;

int N,M,K;

int main(){
    cin >> N >> M >> K; // N = plant, N = store
    vector<tuple<int,int,int>> vec(K);
    for(int i = 0; i < K; i++){
        cin >> get<0>(vec[i]) >> get<1>(vec[i]) >> get<2>(vec[i]);
    }

    sort(vec.begin(), vec.end());

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> prods; // {day, plant}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> stores; // {day, stores}

    int ans = 0;
    for(int i = 0; i < K; i++){
        auto [day, type, num] = vec[i];
        // cout << day << ' ' << type << ' ' << num;
        if(type == 0){
            prods.push({day, num});
            if(stores.empty()){
                ans = 0;
            }else{
                auto [dayReq, storeReq] = stores.top();
                ans = storeReq;
                prods.pop();
                stores.pop();
            }
        }else if(type == 1){
            stores.push({day, num}); 
            if(prods.empty()){
                ans = 0;
            }else{
                auto [dayProd, plant] = prods.top();
                ans = plant;
                prods.pop();
                stores.pop();
            }
        }
        cout << ans << '\n';
    }
}
// for(int i = 0; i < K; i++){
//     cout << get<0>(vec[i]) << get<1>(vec[i]) << get<2>(vec[i]);
// }