#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, d, ans, anss, anns, h[N];

int pos(int d) {
    deque<int> q, qq;
    int cnt = 0, l = 1, r = 1;
    for (;l <= n;) {
        for (;r <= n;) {
            for (;!q.empty() && h[q.back()] <= h[r];) q.pop_back();
            q.push_back(r);
            for (;!qq.empty() && h[qq.back()] >= h[r];) qq.pop_back();
            qq.push_back(r);
            if (h[q.front()] - h[qq.front()] > d) {
                break;
            }
            r++;
        }
        cnt++;
        for (;!q.empty() && q.front() < r;) q.pop_front();
        for (;!qq.empty() && qq.front() < r;) qq.pop_front();
        l = r;
    }
    return cnt;
}


void pos1() {
    int l = 0, r = 0, Min = h[1], Max = h[1];
    for (int i = 1; i <= n; i++) {
        Min = min(Min, h[i]), Max = max(Max, h[i]);
    }
    r = Max - Min;
    ans = r;
    for (;l <= r;) {
        int mid = (l + r) >> 1;
        if (pos(mid) <= k) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
}

int pos3(int d) {
    int cnt = 0, l = 1;
    for (;l <= n;) {
        int r = l;
        int Min = h[l], Max = h[l];
        for (;r <= n;) {
            Min = min(Min, h[r]), Max = max(Max, h[r]);
            if (Max - Min > d) break;
            r++;
        }
        cnt++, l = r;
    }
    return cnt;
}

signed main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) cin >> h[i];
    pos1();
    cout << ans << "\n" << pos(d) << "\n" << pos3(d);
    return 0;
}
