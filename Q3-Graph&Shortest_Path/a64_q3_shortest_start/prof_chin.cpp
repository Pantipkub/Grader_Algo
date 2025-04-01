// ปกติ Bellman-Ford จะได้คำตอบ "ระยะทางที่ดีที่สุดจาก u->v"
// แต่โจทย์ข้อนี้ต้องการคำตอบที่ดีที่สุด ของการเดินทางจากจุด S->u ใดๆ
// ซึ่งก็ทำได้โดยการกลับด้านกราฟ และเริ่มต้นจากจุด S ไปยังปมต่างๆโดยใช้ Bellman-Ford

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    int v;
    cin >> v;

    vector<int> starts(k);
    for (int i = 0; i < k; ++i) cin >> starts[i];

    // สร้าง reverse graph
    vector<vector<pair<int, int>>> revG(n); // revG[b].push_back({a, w});
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        revG[b].push_back({a, w});
    }

    // ใช้ Bellman-Ford จากปลายทาง v ไปทุกจุด (บนกราฟที่กลับทิศแล้ว)
    vector<int> dist(n, INF);
    dist[v] = 0;

    for (int i = 0; i < n - 1; ++i) {
        bool updated = false;
        for (int u = 0; u < n; ++u) {
            if (dist[u] == INF) continue;
            for (auto [v2, w] : revG[u]) {
                if (dist[u] + w < dist[v2]) {
                    dist[v2] = dist[u] + w;
                    updated = true;
                }
            }
        }
        if (!updated) break;
    }

    // หา min จาก start ทั้งหมด
    int answer = INF;
    for (int s : starts) {
        answer = min(answer, dist[s]);
    }

    cout << answer << "\n";

    return 0;
}
