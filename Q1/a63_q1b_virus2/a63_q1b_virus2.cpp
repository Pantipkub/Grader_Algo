#include<iostream>
#include<vector>

using namespace std;

bool check(vector<int> &vec, int start, int stop){
    //terminating condition
    if(start + 1 == stop) return true;

    int mid = (start+stop) >> 1;
    bool left = check(vec, start, mid);
    bool right = check(vec, mid+1, stop);
    
    int one = 0;
    for(int i = start; i <= mid; i++) one += vec[i]; //count 1's on the left
    for(int i = mid+1; i <= stop; i++) one -= vec[i]; //subtract 1's on the right
    // cout << one << endl; 
    if(one > 1 || one < -1) return false; //see if there are 2 or more different 1's count

    return left && right;
}

int main(){
    int n, k; cin >> n >> k;

    int length = 1 << k; //length is 2**k
    vector<int> vec(length);

    for(int i = 0; i < n; i++){
        //for each given DNA signature
        for(int j = 0; j < length; j++){
            cin >> vec[j];
        }
        if(check(vec, 0, length-1)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}