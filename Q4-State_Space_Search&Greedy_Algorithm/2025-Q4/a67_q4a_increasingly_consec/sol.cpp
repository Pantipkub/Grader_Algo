#include<bits/stdc++.h>

using namespace std;

int main(){
    int N; cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());

    long long old = -999, cur = -999;
    long long count = 0, sum = 0;
    for(int i = 0; i < N; i++){
        cur = v[i];
        if(cur != old){
            old = cur;
            if(count > 1){
                sum += (count*count);
            }
            count = 1;
        }else{
            count++;
        }
    }

    if(count > 1) sum += (count*count);

    cout << sum;
}