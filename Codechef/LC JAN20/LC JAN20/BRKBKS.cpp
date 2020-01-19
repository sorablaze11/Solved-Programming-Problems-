#include <bits/stdc++.h>
using namespace std;

int t, S, W[3], minHits;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> S >> W[0] >> W[1] >> W[2];
        int tempWeight = 0;
        for (int i = 0; i < 3; i++)
        {
            if (tempWeight + W[i] > S)
            {
                tempWeight = 0;
                minHits++;
            }
            tempWeight += W[i];
        }
        if (tempWeight > 0)
            minHits++;
        cout << minHits << '\n';
        minHits = 0;
    }
    return 0;
}