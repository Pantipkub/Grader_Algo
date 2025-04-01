/* 
    # Issues are
    1. Node start from no.1 => Subtracting out 1 for each node if we want to start at no.0
    2. !!Don't forget to copy the vector 'indeg' (as tmpIndeg) for using the original indeg in each loop's work
    3. Don't confuse i,j
*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,e; cin >> n >> e;
    vector<vector<int>> instr(n);
    vector<int> indeg(n);
    for(int i = 0; i < e; i++){
        int f,s; cin >> f >> s;
        f--, s--;   // Issue 1
        indeg[s]++;
        instr[f].push_back(s);
    }

    for(int i = 0; i < 5; i++){
        vector<int> sequence(n);
        for(int j = 0; j < n; j++){
            int x; cin >> x;
            x--;    // Issue 1
            sequence[j] = x;
        }

        vector<int> tmpIndeg(indeg); // Issue 2
        bool flag = true;
        for(int j = 0; j < n; j++){
            int curNode = sequence[j];  // Issue 3
            // cout << "curnode = " << curNode << " tmpIndeg = " << tmpIndeg[curNode] << endl;
            if(tmpIndeg[curNode] != 0){
                flag = false;
                break;
            }

            // if valid
            for(int frienD: instr[curNode]){
                tmpIndeg[frienD]--;
                // cout << frienD << ' ' << tmpIndeg[frienD] << endl;
            }
            
        }

        flag ? cout << "SUCCESS" : cout << "FAIL";
        cout << endl;
    }
}


/* Debugging

    Paste @ Line16
    ##Each node's indegree:
    for(int i = 0; i < n; i++){
        cout << indeg[i] << ' ';
    }
    cout << endl;

    ##Each node's friends. (For subtracting out each friend's indegree)
    for(int i = 0; i < n; i++){
        cout << "Current Node = " << i << " has friends: ";
        for(int j = 0; j < instr[i].size(); j++){
            cout << instr[i][j] << " ";
        }
        cout << endl;
    }

*/
