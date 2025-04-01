#include<iostream>
#include<vector>

using namespace std;

int N;

vector<int> pareto(vector<pair<int,int>> &points, int l, int r){
    if(l >= r) return v[l];
    int m = (l+r)/2;

    vector<int> left = pareto(points, l, m);
    vector<int> right = pareto(points, m+1, r);

    vector<int> ans;
    while(){
        
    }
}

int main(){
    cin >> N;
    vector<pair<int,int>> points(N); 
    for(int i = 0; i < N; i++){
        cin >> points[i].first >> points[i].second;
    }


}