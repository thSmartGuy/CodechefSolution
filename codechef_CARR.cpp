#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define quick                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define time cerr << (0.1 * clock()) / CLOCKS_PER_SEC << endl;
#define mod 1000000007
typedef long long ll;
typedef pair<ll, ll> pl;
#define forn(n) for (ll i = 0; i < ll(n); i++)

void matMult(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    int n = a.size();
    vector<vector<ll>> c(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] = (c[i][j] + ((((a[i][k]) % mod) * ((b[k][j]) % mod)) % mod)) % mod;
            }
        }
    }
    a = c;
}

void exp(vector<vector<ll>>& a, ll n, vector<vector<ll>>& base) {
    if (n <= 0) {
        return;
    }
    exp(a, n / 2, base);
    matMult(a, a);
    if (n & 1) {
        matMult(a, base);
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    m = m % mod;
    vector<vector<ll>> base = {{(m - 1 + mod) % mod, (m - 1 + mod) % mod}, {1ll, 0ll}};
    vector<ll> v(2);
    v[0] = (m * ((m - 1 + mod) % mod)) % mod;
    v[1] = m;
    if (n <= 2) {
        if (n == 1) {
            cout << m << '\n';
        } else {
            cout << (m * m) % mod << '\n';
        }
        return;
    }
    vector<vector<ll>> gr(2, vector<ll>(2));
    forn(2) {
        gr[i][i] = 1ll;
    }
    exp(gr, n - 2, base);
    ll ans = (((gr[0][0] * v[0]) % mod + (gr[0][1] * v[1]) % mod) % mod + ((gr[1][0] * v[0]) % mod + (gr[1][1] * v[1]) % mod) % mod) % mod;
    cout << ans << '\n';
}

int main() {
    quick;
    // solve();
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}