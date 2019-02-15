#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

int t, n;
long long S;
int ans[MAX];
pair<int, int> a[MAX];
int seg[2*MAX];

void build() {
  fill(seg, seg + 2 * n, 0);
}

void update(int x, int y) {
  x -= 1;     //convert to 0-base indexing
  for(seg[x += n] = y; x > 1; x >>= 1) {
    seg[x >> 1] = max(seg[x], seg[x ^ 1]);
  }
}

int query(int l, int r) {
  l -= 1;     //convert to 0-base indexing
  int res = 0;
  for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      res = max(res, seg[l++]);
    }
    if (r & 1) {
      res = max(res, seg[--r]);
    }
  }
  return res;
}

bool solve(int k) {
  long long sum = 0;
  build();
  for(int i = 1; i <= n; ++i) {
    int j = i;
    while(j <= n && a[i].first == a[j].first) {
      j += 1;
    }
    vector<pair<int,int>> w; // {value, pos}
    for(int u = i; u < j; ++u) {
      int l = max(1, a[u].second - k);
      int r = min(n, a[u].second + k);
      w.push_back({query(l, r) + 1, a[u].second});
    }
    for(int u = 0; u < w.size(); ++u) {
      int v = u + 1;
      while(v < w.size() && w[v].second <= w[v-1].second+k) {
        v += 1;
      }
      int val = 0;
      for(int x = u; x < v; ++x) {
        val = max(val, w[x].first);
      }
      for(int x = u; x < v; ++x) {
        ans[w[x].second] = val;
        sum += val;
        update(w[x].second, val);
      }
      u = v - 1;
    }
    i = j - 1;
  }
  return (sum <= S);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> t;
  while(t--) {
    cin >> n >> S;
    for(int i = 1; i <= n; ++i) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    int low = 0, high = n, ans = -1;
    while(low <= high) {
      int mid = (low + high)/2;
      if (solve(mid)) {
        ans = mid;
        low = mid + 1;
      }
      else {
        high = mid - 1;
      }
    }
    cout << (ans + 1) << "\n";
  }
  return 0;
}
