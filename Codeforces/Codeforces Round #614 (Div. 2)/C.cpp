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
    int n, q, r, c, vertitalBlock = 0, diagonalBlock = 0;
    cin >> n >> q;
    int grid[2][n];
    memset(grid, 0, 2 * n * sizeof(grid[0][0]));
    for (int i = 0; i < q; i++)
    {
        cin >> r >> c;
        r--, c--;
        if (grid[r][c])
        {
            grid[r][c] = 0;
            // Vertical blocks
            if (r - 1 >= 0 && grid[r - 1][c] == 1)
            {
                vertitalBlock--;
            }
            if (r + 1 < 2 && grid[r + 1][c] == 1)
            {
                vertitalBlock--;
            }

            // Diagonal Blocks
            if (c - 1 >= 0 && r - 1 >= 0 && grid[r - 1][c - 1] == 1)
            {
                diagonalBlock--;
            }
            if (c - 1 >= 0 && r + 1 < 2 && grid[r + 1][c - 1] == 1)
            {
                diagonalBlock--;
            }
            if (c + 1 < n && r - 1 >= 0 && grid[r - 1][c + 1] == 1)
            {
                diagonalBlock--;
            }
            if (c + 1 < n && r + 1 < 2 && grid[r + 1][c + 1] == 1)
            {
                diagonalBlock--;
            }
        }
        else
        {
            grid[r][c] = 1;
            // Vertical blocks
            if (r - 1 >= 0 && grid[r - 1][c] == 1)
            {
                vertitalBlock++;
            }
            if (r + 1 < 2 && grid[r + 1][c] == 1)
            {
                vertitalBlock++;
            }

            // Diagonal Blocks
            if (c - 1 >= 0 && r - 1 >= 0 && grid[r - 1][c - 1] == 1)
            {
                diagonalBlock++;
            }
            if (c - 1 >= 0 && r + 1 < 2 && grid[r + 1][c - 1] == 1)
            {
                diagonalBlock++;
            }
            if (c + 1 < n && r - 1 >= 0 && grid[r - 1][c + 1] == 1)
            {
                diagonalBlock++;
            }
            if (c + 1 < n && r + 1 < 2 && grid[r + 1][c + 1] == 1)
            {
                diagonalBlock++;
            }
        }
        if (vertitalBlock || diagonalBlock)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}