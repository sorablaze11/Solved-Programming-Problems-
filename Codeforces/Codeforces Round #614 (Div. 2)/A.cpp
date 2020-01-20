#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int
#define pii pair<int, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, k, s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s >> k;
        int ans, f;
        unordered_map<int, int> m;
        for (int i = 0; i < k; i++)
        {
            cin >> f;
            m[f]++;
        }
        int i = 0;
        while (true)
        {
            if (s - i >= 1 && m.find(s - i) == m.end())
            {
                ans = i;
                break;
            }
            if (s + i <= n && m.find(s + i) == m.end())
            {
                ans = i;
                break;
            }
            i++;
        }
        cout << ans << '\n';
    }
    return 0;
}