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
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        int diff = abs(a - b), ans = 0;
        for (int i = 1; i * i <= diff; i++)
        {
            if (diff % i == 0)
            {
                ans++;
                if (i * i != diff)
                    ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}