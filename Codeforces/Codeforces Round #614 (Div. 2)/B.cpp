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
    double n, ans = 0;
    cin >> n;
    while (n > 0)
    {
        ans += 1 / n;
        n--;
    }
    cout << ans << '\n';
    return 0;
}