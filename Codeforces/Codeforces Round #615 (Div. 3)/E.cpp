#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int
#define ull unsigned ll
#define pii pair<int, int>

const int N = 2e5 + 10;
int n, m, mat[N], ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++)
        cin >> mat[i], mat[i]--;

    for (int i = 0; i < m; i++)
    {
        // Find min score for each column;
        int min_ = n;
        unordered_map<int, int> disp;
        for (int j = 0; j < n; j++)
        {
            // cout << mat[j * m + i] << ' ';
            if (mat[j * m + i] % m != i || mat[j * m + i] / m >= n)
                continue;
            if (j >= mat[j * m + i] / m)
                disp[j - mat[j * m + i] / m]++;
            else
                disp[n - mat[j * m + i] / m + j]++;
        }
        // cout << '\n';
        for (auto x : disp)
        {
            // cout << x.first << ' ' << x.second << '\n';
            min_ = min(min_, x.first + (n - x.second));
        }
        ans += min_;
    }
    cout << ans << '\n';
    return 0;
}