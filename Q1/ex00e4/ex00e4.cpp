#include<iostream>
#include<vector>

using namespace std;

int A, B;

void combination(int len, int chosen, vector<char> &sol){
    if(len < B){
        if(len - chosen < B - A){
            sol[len] = '0';
            combination(len+1, chosen, sol);
        }
        if(chosen < A){
            sol[len] = '1';
            combination(len+1, chosen+1, sol);
        }
    }else{
        for(auto x: sol){
            cout << x;
        }
        cout << endl;
    }
}

int main(){
    cin >> A >> B;
    vector<char> sol(B);
    combination(0, 0, sol);
}