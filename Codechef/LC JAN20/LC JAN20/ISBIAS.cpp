#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, q, arr[N], prefInc[N], prefDec[N], arrStateInc[N], arrStateDec[N], l, r, cont;

// Array states
// 0 - start
// 1 - mid
// 2 - end
// -1 - other
// For increasing array
// 1 2 3 5 4
// state array will be
// 0 1 1 2 -1

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Precalculation for incresing maximal part
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] < arr[i])
        {
            if (cont)
            {
                arrStateInc[i] = 1;
            }
            else
            {
                arrStateInc[i - 1] = 0;
                arrStateInc[i] = 1;
                cont = 1;
            }
        }
        else
        {
            if (cont)
            {
                arrStateInc[i - 1] = 2;
                arrStateInc[i] = -1;
                cont = 0;
            }
            else
            {
                arrStateInc[i - 1] = -1;
                arrStateInc[i] = -1;
            }
        }
    }
    if (arrStateInc[n - 1] == 1)
    {
        arrStateInc[n - 1] = 2;
    }
    for (int i = 0; i < n; i++)
    {
        if (arrStateInc[i] == 0)
        {
            if (i - 1 >= 0)
            {
                prefInc[i] = prefInc[i - 1];
            }
            prefInc[i] += 1;
        }
        else
        {
            prefInc[i] = prefInc[i - 1];
        }
    }

    // Precalculation for decreasing maximal part
    cont = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            if (cont)
            {
                arrStateDec[i] = 1;
            }
            else
            {
                arrStateDec[i - 1] = 0;
                arrStateDec[i] = 1;
                cont = 1;
            }
        }
        else
        {
            if (cont)
            {
                arrStateDec[i - 1] = 2;
                arrStateDec[i] = -1;
                cont = 0;
            }
            else
            {
                arrStateDec[i - 1] = -1;
                arrStateDec[i] = -1;
            }
        }
    }
    if (arrStateDec[n - 1] == 1)
    {
        arrStateDec[n - 1] = 2;
    }
    for (int i = 0; i < n; i++)
    {
        if (arrStateDec[i] == 0)
        {
            if (i - 1 >= 0)
            {
                prefDec[i] = prefDec[i - 1];
            }
            prefDec[i] += 1;
        }
        else
        {
            prefDec[i] = prefDec[i - 1];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         int u, v;
    //         v = (arrStateInc[j] == 0 ? prefInc[j] - 1 : prefInc[j]);
    //         u = (arrStateInc[i] == 0 ? (i ? prefInc[i - 1] : 0) : (arrStateInc[i] == 1 ? prefInc[i] - 1 : prefInc[i]));
    //         cout
    //             << i + 1 << ' ' << j + 1 << ' ' << v - u << '\n';
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         int u, v;
    //         v = (arrStateDec[j] == 0 ? prefDec[j] - 1 : prefDec[j]);
    //         u = (arrStateDec[i] == 0 ? (i ? prefDec[i - 1] : 0) : (arrStateDec[i] == 1 ? prefDec[i] - 1 : prefDec[i]));
    //         cout
    //             << i + 1 << ' ' << j + 1 << ' ' << v - u << '\n';
    //     }
    // }

    // for (int i = 0; i < n; i++)
    //     cout << arrStateInc[i] << ' ';

    // cout << '\n';

    // for (int i = 0; i < n; i++)
    //     cout << prefInc[i] << ' ';

    while (q--)
    {
        cin >> l >> r;
        l--, r--;
        int uInc, vInc;
        vInc = (arrStateInc[r] == 0 ? prefInc[r] - 1 : prefInc[r]);
        uInc = (arrStateInc[l] == 0 ? (l ? prefInc[l - 1] : 0) : (arrStateInc[l] == 1 ? prefInc[l] - 1 : prefInc[l]));
        int uDec, vDec;
        vDec = (arrStateDec[r] == 0 ? prefDec[r] - 1 : prefDec[r]);
        uDec = (arrStateDec[l] == 0 ? (l ? prefDec[l - 1] : 0) : (arrStateDec[l] == 1 ? prefDec[l] - 1 : prefDec[l]));
        if (vInc - uInc == vDec - uDec)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}