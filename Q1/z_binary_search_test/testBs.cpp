#include<iostream>
#include<vector>

using namespace std;

int binary_search_slow(vector<int> v, int n){
    if(v.size() == 1){
        if(v[0] != n){
            return -1;
        }
        return 0;
    }
    if(v[0] == n){
        return 0;
    }
    vector<int> newVec(v.begin()+1, v.end());
    int r = binary_search_slow(newVec, n);
    if(r == -1) return -1;
    return r+1;
}

int bsearch_wrong1(vector<int> &v, int k, int start, int stop){
    if(start == stop) return v[start] == k ? start : -1;
    int m = (start + stop) >> 1;
    if(v[m] == k) return m;
    if(v[m] <= k) bsearch_wrong1(v, k, m+1, stop);
    if(v[m] > k) bsearch_wrong1(v, k, start, m-1);
}

int main(){
    // vector<int> v = {1,5,3,2,6,8,4,6};
    // cout << binary_search_slow(v, 6);

    vector<int> v = {10,20,30,40,50,60};
    cout << bsearch_wrong1(v, 20, 1, 6);
}