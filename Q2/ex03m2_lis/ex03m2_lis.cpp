#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    vector<vector<int>> table(n+1, vector<int>(n+1));
    
    for(int i = 0; i < n; i++){
      cin >> nums[i];
    }
    
    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            if(nums[i-1] == sorted_nums[j-1]){
                table[i][j] = table[i-1][j-1] + 1;
            }else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    cout << table[n][n];
}
