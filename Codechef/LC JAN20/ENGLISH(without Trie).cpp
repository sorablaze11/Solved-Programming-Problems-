#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int
#define pii pair<int, int>

const int N = 1e5 + 10;
int t, n;
ll ans;
string w[N];
unordered_map<string, int> stringCnt;
vector<string> singleCntWrd;
set<string> alreadyDone;
vector<pair<int, pii>> singleWords;

int checkBeauty(string a, string b)
{
    int i = 0, jA = a.length() - 1, jB = b.length() - 1, res = 0;
    while (i < min(a.length(), b.length()) && jA >= 0 && jB >= 0)
    {
        if (a[i] != b[i] || a[jA] != b[jB])
            break;
        res++;
        i++;
        jA--;
        jB--;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
            stringCnt[w[i]]++;
        }
        for (auto x : stringCnt)
        {
            ans += x.first.length() * x.first.length() * (x.second / 2);
            if (x.second % 2)
                singleCntWrd.push_back(x.first);
        }
        for (int i = 0; i < singleCntWrd.size(); i++)
        {
            for (int j = 0; j < singleCntWrd.size(); j++)
            {
                if (i != j)
                {
                    int temp = checkBeauty(singleCntWrd[i], singleCntWrd[j]);
                    // cout << singleCntWrd[i] << ' ' << singleCntWrd[j] << ' ' << temp << '\n';
                    if (temp)
                    {
                        singleWords.push_back({temp, {i, j}});
                    }
                }
            }
        }
        sort(singleWords.begin(), singleWords.end(), greater<pair<int, pii>>());
        for (int i = 0; i < singleWords.size(); i++)
        {
            if (alreadyDone.find(singleCntWrd[singleWords[i].second.first]) == alreadyDone.end() && alreadyDone.find(singleCntWrd[singleWords[i].second.second]) == alreadyDone.end())
            {
                ans += singleWords[i].first * singleWords[i].first;
                alreadyDone.insert(singleCntWrd[singleWords[i].second.first]);
                alreadyDone.insert(singleCntWrd[singleWords[i].second.second]);
            }
        }
        cout << ans << "\n";
        alreadyDone.clear();
        stringCnt.clear();
        singleCntWrd.clear();
        singleWords.clear();
        ans = 0;
    }
    return 0;
}