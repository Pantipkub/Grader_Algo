#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

int n,m,k;

void print_debugger(vector<vector<int>> &eachStudentDays){
    for(auto x: eachStudentDays){
        for(auto y: x){
            cout << y << ' ';
        }
        cout << endl;
    }
}

void sort_by_amount(vector<vector<int>>){

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

    set<int> dayChecker;
    for(int i = 1; i <= n; i++){
        dayChecker.insert(i);
    }

    // sort(eachStudentDays.begin(), eachStudentDays.end(), [](const vector<int> &a, const vector<int> &b){
    //     return a.size() > b.size();
    // });

    while(!dayChecker.empty()){

        int max_covered = 0;

        for(int i = 0; i < eachStudentDays.size(); i++){
            int covered = 0;
            for(int day: eachStudentDays[i]){
                if(dayChecker.count(day)){
                    covered++;
                }
            }

            max_covered = (covered > max_covered) ? covered: max_covered;
        }
    }



}