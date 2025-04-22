#include<iostream>
#include<vector>

using namespace std;

int k, top;

int mod(int a, int b, int x){
    return ((a%x)*(b%x))%x;
}

void sum_recur(int n, vector<int> &R, vector<int> &vC){
    int sum = 0;
    for(int i = 1; i <= k; i++){
        sum += (mod(vC[i-1], R[n-i], 32717));
        sum %= 32717;
    }
    R[n] = sum;
}

void recur(int n, vector<int> &R, vector<int> &vC){
    sum_recur(n, R, vC);
    if(n == top){
        cout << R[n];
        return;
    }
    recur(n+1, R, vC);
}

int main(){
    int n; cin >> k >> n;
    top = n;
    vector<int> vA(k);
    vector<int> vC(k);
    vector<int> R(max(k, n)+1); //for "n < k" testcase
    for(int i = 0; i < k; i++){
        cin >> vC[i];
    }
    for(int i = 0; i < k; i++){
        cin >> vA[i];
    }
    for(int i = 0; i < k; i++){
        R[i] = vA[i];
    }

    if(n < k){
        cout << R[n];
    }else{
        recur(k, R, vC);
    }
}