#include<iostream>
#include<vector>

using namespace std;

int n,k;

bool isVirus(vector<int> &v, int start, int stop){
    if(start == stop-1) return v[start] == 0 && v[start+1] == 1;
    int mid = (start+stop)/2;

    vector<int> reverseLeft(mid-start+1);
    for(int i = start, j = mid; i < mid+1; i++, j--){
        reverseLeft[j-start] = v[i];
    }

    bool leftValid = isVirus(v, start, mid);    
    bool leftReversedValid = isVirus(reverseLeft, 0, mid-start);
    bool rightValid = isVirus(v, mid+1, stop);

    return rightValid && (leftValid || leftReversedValid);
}

int main(){
    cin >> n >> k;
    int m = 1 << k;
    for(int i = 0; i < n; i++){
        vector<int> v(m);
        for(int j = 0; j < m; j++) cin >> v[j];
        cout << (isVirus(v, 0, m-1) ? "yes" : "no") << endl;
    }
}