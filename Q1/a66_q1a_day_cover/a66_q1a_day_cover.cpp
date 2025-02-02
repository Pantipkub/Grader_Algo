#include<iostream>
#include<vector>
#include<climits> //for using INT_MAX
#include<algorithm>

using namespace std;

int n,m,k, minGroupSelected = INT_MAX;
int eachDayCount[1003]; //grader testcases have max N at 1000

void print_debugger(vector<vector<int>> &eachStudentDays){
    for(auto x: eachStudentDays){
        for(auto y: x){
            cout << y << ' ';
        }
        cout << endl;
    }
}

void recur(int index, vector<vector<int>> &v, int nowGroupSelected, int dayFinishedAmount){
    if(dayFinishedAmount == n){
        minGroupSelected = min(nowGroupSelected, minGroupSelected);
        return;
    }
    if(index == m) return; // finished all iterate
    if(nowGroupSelected >= minGroupSelected) return; 

    //เลือก
    for(int day: v[index]){ //index means v's index
        if(eachDayCount[day] == 0){
            dayFinishedAmount++;
        }
        eachDayCount[day]++;
    }
    recur(index+1, v, nowGroupSelected+1, dayFinishedAmount);

    //คืนค่ากลับ
    for(int day: v[index]){
        eachDayCount[day]--;
        if(eachDayCount[day] == 0){
            dayFinishedAmount--;
        }
    }

    //ไม่เลือก
    recur(index+1, v, nowGroupSelected, dayFinishedAmount); //nowGroupSelected ไม่บวกเพิ่ม และการ Backtracking ก่อนหน้าคือการแสดงว่าไม่ได้เลือกตัวนี้
}

int main(){
    cin >> n >> m;
    vector<vector<int>> eachStudentDays(m);
    for(int i = 0; i < m; i++){
        cin >> k;
        vector<int> days(k);
        for(int j = 0; j < k; j++){
            cin >> days[j];
        }
        eachStudentDays[i] = days;
    }
    // print_debugger(eachStudentDays);
    recur(0, eachStudentDays, 0, 0);
    cout << minGroupSelected;
}