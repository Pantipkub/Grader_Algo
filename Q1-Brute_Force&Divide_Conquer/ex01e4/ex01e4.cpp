#include<iostream>
#include<cmath>

using namespace std;

int X,N,K;

int modulo(int n){
    if(n <= 1) return X%K;
    if(n%2 == 0){
        int child = modulo(n/2);
        return (child*child)%K;
    }
    else{
        int child = modulo(n/2);
        child = (child*child)%K;
        return (child*(X%K))%K;
    }
}

int main(){
    cin >> X >> N >> K;
    cout << modulo(N);
}
