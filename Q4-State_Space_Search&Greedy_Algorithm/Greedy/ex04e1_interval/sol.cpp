#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, amt;
vector<pair<int,int>> times; // {stop, start}

int main(){
    cin >> N;
    times.resize(N);
    for(int i = 0 ; i < N ; i++){
        cin >> times[i].second;        
    }
    for(int i = 0 ; i < N ; i++){
        cin >> times[i].first;        
    }
    
    sort(times.begin(), times.end());

    int prevStop = -1;
    for(int i = 0; i < N; i++){
        auto [curStop, curStart] = times[i];
        if(curStart >= prevStop){
            prevStop = curStop;
            amt++;
        }
    }

    cout << amt << '\n';

    return 0;
}