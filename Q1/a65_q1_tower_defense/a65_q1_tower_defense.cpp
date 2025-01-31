#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m, k, w;

int main(){
    cin >> n >> m >> k >> w;
    vector<int> monsterPosition(m), monsterHealth(m), towerPosition(k);
    for(int i = 0; i < m; i++) cin >> monsterPosition[i];
    for(int i = 0; i < m; i++) cin >> monsterHealth[i];
    for(int i = 0; i < k; i++) cin >> towerPosition[i];

    for(int i = 0; i < towerPosition.size(); i++){
        int tower_pos = towerPosition[i];

        // vector<pair<int, int>> targets; //Store {Hp, index} of monsters at index j
        priority_queue<pair<int,int>> targets;
        for(int j = 0; j < monsterPosition.size(); j++){
            if(abs(tower_pos - monsterPosition[j]) <= w && monsterHealth[j]){
                // targets.emplace_back(make_pair(monsterHealth[j], monsterPosition[j]));
                targets.push(make_pair(monsterHealth[j], j));
            }
        }

        // sort(targets.rbegin(), targets.rend()); //Prioritizes the monster with the most Hp by sorting from reverse sorting, maybe we can use another data structure like priority_queue.
        
        if(!targets.empty()){
            int targetIndex = targets.top().second;
            monsterHealth[targetIndex] = max(0, monsterHealth[targetIndex] - 1);
        }
    }

    int totalHp = 0;
    for(int hp: monsterHealth){
        totalHp += hp;
    }

    cout << totalHp;
}