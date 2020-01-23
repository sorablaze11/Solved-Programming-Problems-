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
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ans = INT_MAX;
        int no;
        for (int i = 0; i < n; i++)
        {
            cin >> no;
            ans = min(ans, no);
        }
        cout << ans << '\n';
    }
    return 0;
}