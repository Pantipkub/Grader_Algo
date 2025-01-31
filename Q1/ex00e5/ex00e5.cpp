#include<iostream>
#include<vector>

using namespace std;

int n, k;

void compute(int len, int consecutiveOnes, vector<char> &sol){
    if(len < n){
        if(consecutiveOnes >= k){
            sol[len] = '0';
            compute(len+1, consecutiveOnes, sol);
        }else{
            sol[len] = '0';
            compute(len+1, 0, sol);
        }
        sol[len] = '1';
        compute(len+1, consecutiveOnes+1, sol);
    }else{
        if(consecutiveOnes >= k){
            for(char x: sol){
                cout << x;
            }
            cout << endl;
        }
    }
}

int main(){
    cin >> n >> k;
    vector<char> sol(n);
    compute(0, 0, sol);
}