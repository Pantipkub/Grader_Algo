#include<iostream>
#include<vector>

using namespace std;

void prefixSum(vector<int> &v, vector<int> &sumVector){
    sumVector[0] = 0;
    for(int i = 0; i < v.size(); i++){
        sumVector[i+1] = sumVector[i] + v[i];
    }
}

int getSum(vector<int> &sumVector, int a, int b){
    return sumVector[b] - sumVector[a-1];
}

int divide(vector<int> &v, int start, int stop, vector<int> &sumVector){
    if(start >= stop) return v[start];
    int mid = (start+stop) >> 1;

    int maxLeft = divide(v, start, mid, sumVector);
    int maxRight = divide(v, mid+1, stop, sumVector);

    int maxMiddleByLeft = getSum(sumVector, mid+1, mid+1); //(m)
    for(int i = start; i < mid-1+1; i++){   
        maxMiddleByLeft = max(maxMiddleByLeft, getSum(sumVector, i+1, mid+1));
    }

    int maxMiddleByRight = v[mid+1]; //(m+1)
    for(int j = mid+2; j < stop+1; j++){
        maxMiddleByRight = max(maxMiddleByRight, getSum(sumVector, mid+1+1, j+1));
    }

    int maxMiddle = maxMiddleByLeft + maxMiddleByRight;

    return max(max(maxLeft, maxRight), maxMiddle);
}

void print_vector(vector<int> &v){
    for(auto x: v){
        cout << x << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> sumVector(n+1);
    prefixSum(v, sumVector);
    cout << divide(v, 0, n-1, sumVector);


    // print_vector(sumVector);
    // cout << divide(v, 0, n+1);
    // cout << getSum(sumVector, 2, 3);

}