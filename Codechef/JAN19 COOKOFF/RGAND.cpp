#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int
#define ull unsigned ll
#define pii pair<int, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    ll l, r;
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        ll diff = r - l + 1, val, req = 0, act = 0, ans = 0;
        for (int i = 0; i < 60; i++)
        {
            val = min(diff, req - act + 1);
            val %= MOD;
            if (l & (1LL << i))
            {
                ans += (val * ((1LL << i) % MOD)) % MOD;
                ans %= MOD;
                act += (1LL << i);
            }
            req += (1LL << i);
        }

        cout << ans << '\n';
    }
    return 0;
}