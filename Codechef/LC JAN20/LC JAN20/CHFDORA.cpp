#include <bits/stdc++.h>
using namespace std;

int t, n, m;
long long ans;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int rad = 0;
                while (i + rad < n && j + rad < m && i - rad >= 0 && j - rad >= 0 && matrix[i - rad][j] == matrix[i + rad][j] && matrix[i][j - rad] == matrix[i][j + rad])
                {
                    ans++;
                    rad++;
                }
            }
        }
        cout << ans << '\n';
        ans = 0;
    }
    return 0;
}