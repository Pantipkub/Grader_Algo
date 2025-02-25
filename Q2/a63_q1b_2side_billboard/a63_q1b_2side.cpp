// #include<iostream>
// #include<vector>

// using namespace std;

// int n,w,k;
// vector<int> l;
// vector<int> r;

// // int recur(int index){
// //     if(index < 0) return 0;
    
// // }

// int main(){
//     cin >> n >> w >> k;
//     l.resize(n);
//     r.resize(n);
//     vector<int> dpL(n);
//     vector<int> dpR(n);
//     for(int i = 0; i < n; i++){
//         cin >> l[i];
//     }
//     for(int i = 0; i < n; i++){
//         cin >> r[i];
//     }
//     dpL[0] = l[0];
//     dpR[0] = r[0];
//     for(int i = 1; i <= w; i++){
//         dpL[i] = max(l[i-1], l[i]);
//         dpR[i] = max(l[i-1], r[i]);
//     }
    
//     for(int i = w; i < n; i++){
//         int maxLnow = dpL[i-w-1] + l[i];
//         int maxRnow = dpR[i-w-1] + r[i];
//         for(int j = 0; j < w; j++){
//             maxLnow = max(maxLnow, dpL[i-w+j + 1]);
//             maxRnow = max(maxRnow, dpR[i-w+j + 1]);
//         }
//         dpL[i] = maxLnow;
//         dpR[i] = maxRnow;
//     }
//     cout << max(dpL[n-1], dpR[n-1]);
// }