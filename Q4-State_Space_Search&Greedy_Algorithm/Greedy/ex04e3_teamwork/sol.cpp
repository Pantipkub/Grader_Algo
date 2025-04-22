#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<climits>

using namespace std;

int main(){
    cout << fixed << setprecision(3);
    int N,M; cin >> N >> M;
    
    vector<int> vec(M);
    for(int i = 0; i < M; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    double sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++){
        pq.push(vec[i]);
        sum += vec[i];
    }
    for(int i = N; i < M; i++){
        int newman = vec[i] + pq.top();
        pq.pop();
        pq.push(newman);
        sum += newman;
    }

    cout << sum/M << '\n';

    return 0;
}