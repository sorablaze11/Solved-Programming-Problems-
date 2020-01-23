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
    int t, n;
    ll arr[200010], ans, temp;
    unordered_map<ll, vector<int>> m;
    cin >> t;
    while (t--)
    {
        ans = 0;
        m.clear();
        temp = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            temp += arr[i];
            m[temp].push_back(i);
        }
        for (int i = 0; i < n; i++)
        {
            if ((temp - arr[i]) % 2)
                continue;
            ll findNo = (temp - arr[i]) / 2;
            if (i && m.find(findNo) != m.end())
            {
                int pos1 = upper_bound(m[findNo].begin(), m[findNo].end(), i - 1) - m[findNo].begin();
                ans += (ll)pos1;
            }
            findNo += arr[i];
            if (m.find(findNo) != m.end())
            {
                int pos2 = lower_bound(m[findNo].begin(), m[findNo].end(), i) - m[findNo].begin();
                ans += (ll)(m[findNo].size() - pos2);
                if (pos2 < m[findNo].size() && m[findNo].back() == n - 1)
                    ans--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}