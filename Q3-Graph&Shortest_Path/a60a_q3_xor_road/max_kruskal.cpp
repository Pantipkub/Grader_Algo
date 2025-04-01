#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> p, S;

int findset(int x){
    if(p[x] == -1) return x;
    //path compression
    p[x] = findset(p[x]);
    return p[x];
}

void unionIn(int x, int y){
    int s1 = findset(x);
    int s2 = findset(y);
    if(S[s1] > S[s2]){
        p[s2] = s1;
        S[s1] = S[s1] + S[s2];
    }
    else{
        p[s1] = s2;
        S[s2] = S[s1] + S[s2];
    }
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    p.resize(n, -1);
    S.resize(n, 1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<pair<int,pair<int,int>>> edges;
    // int count = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            edges.push_back({v[i]^v[j], make_pair(i,j)});
        }
    }

    unsigned long long ans = 0;
    sort(edges.rbegin(), edges.rend());
    for(auto x: edges){
        auto [f,s] = x.second;
        if(findset(f) != findset(s)){
            ans += x.first; //weight
            unionIn(f,s);
        }
    }
    cout << ans << endl;
}
