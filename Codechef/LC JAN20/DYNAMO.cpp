#include <bits/stdc++.h>
using namespace std;

unsigned long long int t, a, b, c, d, e, s, n, res;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> a;
        s = pow(10, n);
        s *= 2;
        s += a;
        cout << s << '\n'
             << flush;
        cin >> b;
        c = pow(10, n);
        c -= b;
        cout << c << '\n'
             << flush;
        cin >> d;
        e = pow(10, n);
        e -= d;
        cout << e << '\n'
             << flush;
        cin >> res;
        if (res == -1)
        {
            break;
        }
    }
    return 0;
}