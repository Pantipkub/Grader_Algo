#include<iostream>
#include<vector>
#include<map>

using namespace std;

int N, count; //Global var
vector<vector<char>> allSolutions;

// ทำไม 2 0 0 3 ถึงไม่พิมพ์ CC CC CC นะ, เพราะใช้ map มันเก็บค่า key เป็น char แค่ตัวเดียว แล้วเก็บจำนวนที่ใช้ได้เป็น value เลยจะไม่นับว่า C แต่ละตัวเป็นตัวต่างกัน

void permutation(int len, map<char, int> &eachAvailable, vector<char> &sol){
    if(len < N){
        for(auto it = eachAvailable.begin(); it != eachAvailable.end(); it++){
            if(it->second > 0){
                sol[len] = it->first;
                it->second -= 1;           
                permutation(len+1, eachAvailable, sol);
                it->second += 1;
            }
        }
    }else{
        ++count;
        allSolutions.push_back(sol);
    }
}

int main(){
    int i, j, k;
    cin >> N >> i >> j >> k;
    map<char, int> eachAvailable;
    vector<char> sol(N);
    if(i != 0) eachAvailable['A'] = i;
    if(j != 0) eachAvailable['B'] = j;
    if(k != 0) eachAvailable['C'] = k;
    permutation(0, eachAvailable, sol);
    cout << count << endl;
    for(auto s: allSolutions){
        for(auto c: s){
            cout << c;
        }
        cout << endl;
    }
}