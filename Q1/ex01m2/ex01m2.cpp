#include<iostream>
#include<vector>

using namespace std;

int mergeAndCount(vector<int>& v, int start, int mid, int stop) {
    int count = 0;
    
    // สร้างอาร์เรย์ย่อยซ้ายและขวา
    vector<int> left(v.begin() + start, v.begin() + mid + 1);
    vector<int> right(v.begin() + mid + 1, v.begin() + stop + 1);

    int i = 0, j = 0, k = start;

    // รวมอาร์เรย์ย่อยซ้ายและขวา พร้อมนับ inversion
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            v[k++] = left[i++];
        } else {
            v[k++] = right[j++];
            count += (left.size() - i);  // นับ inversion
        }
    }

    // คัดลอกส่วนที่เหลือจากอาร์เรย์ย่อย
    while (i < left.size()) v[k++] = left[i++];
    while (j < right.size()) v[k++] = right[j++];

    return count;
}

int recurAndCount(vector<int>& v, int start, int stop) {
    if (start >= stop) return 0; // อาร์เรย์ย่อยมีขนาด 1 หรือไม่มี
    int mid = (start + stop) / 2;

    // นับ inversion ในอาร์เรย์ซ้ายและขวา
    int leftCount = recurAndCount(v, start, mid);
    int rightCount = recurAndCount(v, mid + 1, stop);

    // นับ inversion ระหว่างซ้ายและขวา
    int mergeCount = mergeAndCount(v, start, mid, stop);

    // รวม inversion ทั้งหมด
    return leftCount + rightCount + mergeCount;
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
