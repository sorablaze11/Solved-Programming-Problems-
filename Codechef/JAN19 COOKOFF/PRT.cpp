#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int
#define ull unsigned ll
#define pii pair<int, int>

const int N = 3e5 + 10;
int t, n, u, v, deg[N];
ll ans, mul[N], val[N], leafNodes;
vector<int> G[N];

ll dfs(int node, int parent)
{
    // cout << node << '\n';
    ll num = 0, sub = 0;
    for (int child : G[node])
    {
        if (parent == child)
            continue;
        ll temp = dfs(child, node);
        num += temp;
        sub += temp * temp;
    }
    if (deg[node] > 1)
    {
        sub += (leafNodes - num) * (leafNodes - num);
        mul[node] = (leafNodes * leafNodes - sub) / 2;
    }
    else
    {
        mul[node] = leafNodes - 1;
    }
    return num + (deg[node] == 1 ? 1LL : 0LL);
}

void solve()
{
    leafNodes = 0;
    ans = 0;
    for (int i = 0; i < n; i++)
        G[i].clear();
    memset(deg, 0, sizeof(deg[0]) * n);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    sort(val, val + n, greater<ll>());
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v, u--, v--;
        deg[u]++;
        deg[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 1)
            leafNodes++;
    }
    dfs(0, -1);
    sort(mul, mul + n, greater<ll>());
    for (int i = 0; i < n; i++)
    {
        // cout << mul[i] << ' ';
        mul[i] %= MOD;
        ans = (ans + (mul[i] * val[i]) % MOD) % MOD;
    }
    // cout << '\n';
    if (n == 1)
        cout << 0 << '\n';
    else
        cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}