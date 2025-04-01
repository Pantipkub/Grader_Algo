#include<iostream>
#include<vector>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    vector<int> v(n), A1(n), A2(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        if(i%2 != 0){
            A1[i] = v[i]*(-1);
        }else{
            A1[i] = v[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            A2[i] = v[i]*(-1);
        }else{
            A2[i] = v[i];
        }
    }

    int maxCurrent = A1[0];
    int maxGlobal1 = A1[0];
    int flag = -1;
    for(int i = 1; i < n; i++){
        int value = A1[i]*flag;
        if(A1[i] > maxCurrent+value){
            // maxCurrent = max(A1[i], maxCurrent + A1[i]);
            // maxGlobal1 = max(maxGlobal1, maxCurrent);
            // ?bla bla bla
            flag =-1;
        }else{
            
            flag*=-1;
        }
    }

    maxCurrent = A2[1];
    int maxGlobal2 = A2[1];
    for(int i = 2; i < n; i++){
        maxCurrent = max(A2[i], maxCurrent + A2[i]);
        maxGlobal2 = max(maxGlobal2, maxCurrent);
    }

    if(n == 1) cout << A1[0];
    else cout << max(maxGlobal1, maxGlobal2);

    // print_vector(negative);
    // cout << divide(v, 0, n+1);
    // cout << getSum(negative, 2, 4);
    
}