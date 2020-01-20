#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int
#define pii pair<int, int>

ll dist(ll x_1, ll y_1, ll x_2, ll y_2)
{
    return abs(x_1 - x_2) + abs(y_1 - y_2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x, y, a_x, a_y, b_x, b_y;
    cin >> x >> y >> a_x >> a_y >> b_x >> b_y;
    ll x_s, y_s, t;
    cin >> x_s >> y_s >> t;
    ll prev_dist = 0;
    int ans = 0;
    vector<pair<ll, ll>> nodes;
    nodes.push_back({x, y});
    while (prev_dist <= 10000000000000000LL)
    {
        prev_dist = dist(x, y, x * a_x + b_x, y * a_y + b_y);
        x = x * a_x + b_x;
        y = y * a_y + b_y;
        nodes.push_back({x, y});
        // cout << x << ' ' << y << '\n';
    }
    for (int i = 0; i < nodes.size(); i++)
    {
        for (int j = i; j < nodes.size(); j++)
        {
            ll l = dist(x_s, y_s, nodes[i].first, nodes[i].second);
            ll r = dist(x_s, y_s, nodes[j].first, nodes[j].second);
            ll mainDist = dist(nodes[i].first, nodes[i].second, nodes[j].first, nodes[j].second);
            if (l + mainDist <= t || r + mainDist <= t)
                ans = max(ans, j - i + 1);
        }
    }
    cout << ans << '\n';
    return 0;
}