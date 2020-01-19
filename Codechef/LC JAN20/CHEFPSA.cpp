#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int
#define pii pair<int, int>

const int N = 1e5 + 10;
int t, n, arr[2 * N], totalSum, flag;
ll ans = 1, fact[N], invFact[N];
vector<int> res;
pii prev_;

ll power(ll x, ll y)
{
    if (y == 0)
        return 1LL;
    ll p = power(x, y / 2) % MOD;
    p = (p * p) % MOD;
    if (y % 2 == 1)
        p = (p * x) % MOD;
    return p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0] = invFact[0] = 1LL;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
        invFact[i] = power(fact[i], MOD - 2);
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> arr[i];
        }
        arr[2 * n] = arr[2 * n + 1] = 0;
        sort(arr, arr + 2 * n + 2);
        totalSum = arr[0] + arr[2 * n + 1];
        int temp = 2;
        for (int i = 0; i < n + 1; i++)
        {
            if (arr[i] + arr[2 * n + 1 - i] != totalSum)
            {
                flag = 1;
                break;
            }
            if (arr[i] == 0 || arr[2 * n + 1 - i] == 0)
            {
                if (temp)
                {
                    temp--;
                    continue;
                }
            }
            if (arr[i] != arr[2 * n - i + 1])
                ans = (ans * 2) % MOD;
            if (res.size() == 0)
            {
                prev_ = {arr[i], arr[2 * n - i + 1]};
                res.push_back(1);
            }
            else if (prev_ == make_pair(arr[i], arr[2 * n - i + 1]))
            {
                res.back()++;
            }
            else
            {
                prev_ = {arr[i], arr[2 * n - i + 1]};
                res.push_back(1);
            }
        }
        if (flag || temp)
        {
            cout << "0\n";
            flag = totalSum = 0;
            ans = 1;
            res.clear();
            continue;
        }
        ans = (ans * fact[n - 1]) % MOD;
        for (auto x : res)
        {
            ans = (ans * invFact[x]) % MOD;
        }
        cout << ans << '\n';
        ans = 1;
        totalSum = 0;
        res.clear();
    }
    return 0;
}