#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int INF = 1e9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int main() {
  int R, C;
  cin >> R >>C;
  vector<vector<int>> fee(R, vector<int>(C));
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin>>fee[i][j];
    }
  }
  vector<vector<int>> dist(R, vector<int>(C, INF));
  dist[0][0] = 0;
  
  // min heap (cost, x, y)
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, 
                 greater<tuple<int, int, int>>> pq;
                 
  pq.push({0, 0, 0});
  while (!pq.empty()) {
    auto [cost, r, c] = pq.top(); 
    pq.pop();
    if (cost > dist[r][c]) continue; // r c, because r is vertical-acis which represents row and c is horizontal-acis which represents column
    
    for (int dir = 0; dir < 4; dir++) {
      int nc = c + dc[dir];
      int nr = r + dr[dir];
      if ((nc >= 0) && (nc < C) && (nr >= 0) && (nr < R)) {
        int newCost = dist[r][c] + fee[nr][nc];
        if (newCost < dist[nr][nc]) {
          dist[nr][nc] = newCost;
          pq.push({newCost, nc, nr});
        }
      }
    }
  }
  
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cout<<dist[i][j]<<" ";
    }
    cout<< endl;
  }
  return 0;
}
