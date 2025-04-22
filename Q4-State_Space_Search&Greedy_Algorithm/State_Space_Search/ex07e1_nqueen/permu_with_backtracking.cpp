// Computing diagonol logic on each recur to avoid timeout from looping check everytime

#include<iostream>
#include<vector>

using namespace std;

int N, ans = 0;
vector<int> qPos;
vector<bool> used;

void recur(int step){
    if(step < N){
        for(int col = 0; col < N; col++){
            if(!used[col]){   //Hasn't placed queen in this col, (Can we place a queen in this row (step) with this col?)
                bool conflict = false;
                for(int row = 0; row < step; row++){    
                    if(abs(row - step) == abs(qPos[row] - col)){    // Step = Current row, Is there any (r,c) that is diagonal with (step, col)
                        conflict = true;
                        break;
                    }
                }
                if(conflict) continue;

                used[col] = true;
                qPos[step] = col; 
                recur(step+1);
                used[col] = false;
            }
        }
    }else{
        ans++;
    }
}

int main(){
    cin >> N;
    qPos.resize(N);
    used.resize(N);
    recur(0);
    cout << ans << endl;
    return 0;
}