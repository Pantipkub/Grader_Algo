#include<iostream>
#include<vector>

using namespace std;

int mergeAndCount(vector<int> &v, int start, int mid, int stop){
    int count = 0;

    //create vector on the left and right
    vector<int> left(v.begin() + start, v.begin() + mid + 1);
    vector<int> right(v.begin() + mid + 1, v.begin() + stop + 1);

    //merge B | C
    int i = 0, j = 0;   // B index (left start), C index (right start)
    int k = start;
    while(i < left.size() && j < right.size()){
        if(left[i] <= right[j]){
            v[k++] = left[i++];
        }else{
            v[k++] = right[j++];
            count += (left.size()-i);
        }
    }

    while(i < left.size()){
        v[k++] = left[i++];
    }
    while(j < right.size()){
        v[k++] = right[j++];
    }

    return count;
}

int recurAndCount(vector<int> &v, int start, int stop){
    if(start >= stop) return 0;

    int mid = (start+stop)/2;

    int left = recurAndCount(v, start, mid);
    int right = recurAndCount(v, mid + 1, stop);
    int mergeCount = mergeAndCount(v, start, mid, stop);

    return left + right + mergeCount;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    cout << recurAndCount(v, 0, N - 1) << endl;

    return 0;
}