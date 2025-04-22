#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;

long double W;
int N;
vector<long double> values, weights;
vector<pair<long double,long double>> fractions;

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

    long double sumV = 0, sumW = 0;

    for(int i = 0; i < N; i++){
        if(weights[i] > 0){
            fractions.emplace_back(values[i]/weights[i], weights[i]);
        }else{
            sumV += values[i];
        }
    }

    sort(fractions.rbegin(), fractions.rend());

    int i = 0;
    while(sumW < W && i < fractions.size()){
        auto [curF, curW] = fractions[i];
        if(sumW + curW <= W){
            sumV += (curF * curW);  // full item
            sumW += curW;
        }else{
            sumV += (curF * (W - sumW));  // take fraction
            sumW = W;
        }
        i++;
    }

    cout << fixed << setprecision(4) << sumV << '\n';
}
