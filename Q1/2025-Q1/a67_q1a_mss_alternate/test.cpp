#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> positive(510000);
vector<int> negative(510000);

void sumPositive(vector<int> &v, vector<int> &sumVector){
    sumVector[0] = 0;
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            sumVector[i+1] = sumVector[i] + v[i];
        }else{
            sumVector[i+1] = sumVector[i] - v[i];
        } 
    }
}

void sumNegative(vector<int> &v, vector<int> &sumVector){
    sumVector[0] = 0;
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            sumVector[i+1] = sumVector[i] - v[i];
        }else{
            sumVector[i+1] = sumVector[i] + v[i];
        } 
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

    int maxMiddleByLeft = -1000000;
    for(int i = start; i < mid-1+1; i++){
        if(i%2 == 0){
            maxMiddleByLeft = max(maxMiddleByLeft, getSum(positive, i+1, mid+1));
        }else{
            maxMiddleByLeft = max(maxMiddleByLeft, getSum(negative, i+1, mid+1));
        }
    }

    int maxMiddleByRight = -1000000;
    for(int j = mid+2; j < stop+1; j++){
        if((mid+1)%2 == 0){
            maxMiddleByRight = max(maxMiddleByRight, getSum(positive, mid+1+1, j+1));
        }else{
            maxMiddleByRight = max(maxMiddleByRight, getSum(negative, mid+1+1, j+1));
        }
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
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sumPositive(v, positive);
    sumNegative(v, negative);
    cout << divide(v, 0, n-1, positive);


    // print_vector(negative);
    // cout << divide(v, 0, n+1);
    // cout << getSum(negative, 2, 4);

}