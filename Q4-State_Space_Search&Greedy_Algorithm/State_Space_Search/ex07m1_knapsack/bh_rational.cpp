#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;

double W;
int N;

vector<double> values, weights, ratio;
vector<int> index;
double maxAns = 0;

double bound(int step, int sumV, int sumW){
    for(int i = step; i < N; i++){
        int idx = index[i];
        if(sumW + weights[idx] <= W){
            sumV += values[idx];
            sumW += weights[idx];
        }else{
            double remain = W - sumW;
            sumV += values[idx] * (remain/weights[idx]);
            break;
        }
    }
    return sumV;
}

void dfs(int step, double sumV, double sumW){
    if(sumW > W) return; // Backtracking
    if(step == N){
        maxAns = max(maxAns, sumV);
        return;
    }else{
        double est = bound(step, sumV, sumW);
        if(est < maxAns) return;
        int idx = index[step];
        dfs(step+1, sumV + values[idx], sumW + weights[idx]);
        dfs(step+1, sumV, sumW);
    }
}

int main(){
    cin >> W >> N;

    values.resize(N);
    for(int i = 0; i < N; i++){
        cin >> values[i];
    }

    weights.resize(N);
    for(int i = 0; i < N; i++){
        cin >> weights[i];
    }
    
    ratio.resize(N);
    index.resize(N);
    for(int i = 0; i < N; i++){
        ratio[i] = values[i] / weights[i];
        index[i] = i;
    }
    
    sort(index.begin(), index.end(), [&](int a, int b){
        return ratio[a] > ratio[b];
    });

    dfs(0, 0, 0);

    cout << fixed << setprecision(4) << maxAns << endl;
}