#include<iostream>
#include<vector>

using namespace std;

int N;
double W, maxi;

vector<double> values, weights, tails;

void revPrefixSum(){
    tails[N-1] = values[N-1];
    for (int i = N-2; i >= 0; i--) tails[i] = tails[i+1] + values[i];
}

void knapsack(int step, double sumV, double sumW){
    if (sumW > W) return;
    if (tails[step] + sumV < maxi) return ;
    if (step < N) { 

        knapsack(step + 1, sumV + values[step], sumW + weights[step]);

        knapsack(step + 1, sumV, sumW);    
    } else {
        if (sumV > maxi && sumW <= W) { maxi = sumV; }
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

    tails.resize(N);
    revPrefixSum();

    knapsack(0, 0, 0);

    cout << maxi << endl;
}