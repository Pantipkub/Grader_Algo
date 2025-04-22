#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template <typename T> 
void insertion_sort(vector<T> A, int x) { 
    int count = 0;
    for (int pos = A.size()-2;pos >= 0;pos--) { 
        T tmp = A[pos]; 
        size_t i = pos+1; 
        while (i < A.size() && A[i] < tmp) { 
            A[i-1] = A[i];
            if(A[i] == x) count++;
            i++; 
        } 
        A[i-1] = tmp; 
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> v(n);
    vector<int> questions(m);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < m; i++)
        cin >> questions[i];
    
    for(auto q: questions){
        int count = 0, i = 0;
        while(v[i] != q){
            if(v[i] > q) count++;
            i++;
        }
        cout << count << endl;
    }
}