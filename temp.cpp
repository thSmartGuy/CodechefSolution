#include<bits/stdc++.h>
using namespace std;
#define sz 100100
#define MOD 1000000007
#define ll long long

inline ll add(ll a, ll b)
{
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return (a + b) % MOD;
}

inline ll mul(ll a, ll b)
{
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return (a * b) % MOD;
}

ll dp1[sz];
ll dp2[sz];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll t, n, m; scanf("%lld", &t);

    ll tmp1, tmp2;

    while (t--)
    {

        scanf("%lld", &n); scanf("%lld", &m);

        // dp2[i] i and i-1 are same
        // dp1[i] i and i-1 not same

        dp2[0] = 0;
        dp1[0] = m;

        for (ll i = 1; i < n; ++i)
        {
            tmp2 = dp2[i - 1];
            tmp1 = dp1[i - 1];
            dp2[i] = tmp1;
            dp1[i] = add(mul((m - 1), tmp2), mul((m - 1), tmp1));
        }

        cout << add(dp2[n - 1], dp1[n - 1]) << "\n";

    }


    return 0;
}