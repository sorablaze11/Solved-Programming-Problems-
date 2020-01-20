#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int
#define pii pair<int, int>

const int N = 1e5 + 10;
int t, n, trie[N][676], wordCnt[N], node;
ll ans;
string words;

void insert(vector<int> arr)
{
    int tt = 0;
    for (int a : arr)
    {
        if (!trie[tt][a])
            trie[tt][a] = node++;
        tt = trie[tt][a];
    }
    wordCnt[tt]++;
}

ll dfs(int root = 0, ll prefLen = 0)
{
    // cout << root << '-';
    ll ans = 0;
    for (int i = 0; i < 676; i++)
    {
        if (trie[root][i])
        {
            ans += dfs(trie[root][i], prefLen + 1);
            wordCnt[root] += wordCnt[trie[root][i]];
        }
    }
    if (wordCnt[root] >= 2)
    {
        ans += prefLen * prefLen * (wordCnt[root] / 2);
        wordCnt[root] %= 2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        memset(trie, 0, node * sizeof(trie[0]));
        memset(wordCnt, 0, node * sizeof(wordCnt[0]));
        ans = 0;
        node = 1;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> words;
            vector<int> arr;
            for (int i = 0; i < words.size(); i++)
            {
                arr.push_back((words[i] - 'a') * 26 + (words[words.size() - 1 - i] - 'a'));
            }
            insert(arr);
        }
        ans += dfs();
        cout << ans << '\n';
    }
    return 0;
}