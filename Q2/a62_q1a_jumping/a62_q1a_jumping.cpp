#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int arr[100000];
vector<int> sol_B(100000, INT_MIN);

int B(int i){
    if(sol_B[i] != INT_MIN){
        return sol_B[i];
    }else{
        sol_B[i] = max(max(B(i-1), B(i-2)), B(i-3)) + arr[i];
        return sol_B[i];
    }
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sol_B[0] = arr[0];
    sol_B[1] = max(sol_B[0], sol_B[0]+arr[1]);
    sol_B[2] = max(sol_B[1], sol_B[1]+arr[2]);
    cout << B(n-1);
}