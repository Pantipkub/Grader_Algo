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
    auto [cost, x, y] = pq.top(); 
    pq.pop();
    if (cost > dist[y][x]) continue; // y x, because y is vertical-axis which represents row and x is horizontal-axis which represents column
    
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if ((nx >= 0) && (nx < C) && (ny >= 0) && (ny < R)) {
        int newCost = dist[y][x] + fee[ny][nx];
        if (newCost < dist[ny][nx]) {
          dist[ny][nx] = newCost;
          pq.push({newCost, nx, ny});
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
