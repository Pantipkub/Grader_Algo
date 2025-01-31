#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

int main(){
    int N; cin >> N;
    vector<pair<int,int>> paints;
    for(int i = 0; i < N; i++){
        int A,B; cin >> A >> B;
        paints.emplace_back(make_pair(A,B));
        // paints[i].second++;
    }
    sort(paints.begin(), paints.end());
    int start = paints[0].first, end = paints[0].second;
    for(int i = 1; i < N; i++){
        if(end >= paints[i].first || end == paints[i].first-1){ //ลบเคสหลังได้ ถ้า umcomment บรรทัด 14 และ cout เป็น end-1 (กรณีนี้ไว้ครอบคลุมเคส {5,10} และ {11,15})
            // if(end < paints[i].second) end = paints[i].second;
            end = max(end, paints[i].second);
        }else{
            cout << start << ' ' << end << ' ';
            start = paints[i].first;
            end = paints[i].second;
        }
        // if(i == N-1) cout << start << ' ' << end << ' ';
    }
    cout << start << ' ' << end << ' ';
}

//น่าลองใช้ stack