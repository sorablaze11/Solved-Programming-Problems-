#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+10;
vector<long> G[N];
long n, m, u, v, ans, totalWeight, cnt, preorder[N], weights[N], lowlink[N];
map<long, vector<long> > cutvertexes;

pair<long, long> dfs(long node, long parent){
    if(preorder[node] != -1){
        lowlink[parent] = min(lowlink[parent], preorder[node]);
        return {lowlink[parent], 0};
    }
    preorder[node] = cnt++;
    // cout << node << ' ' << parent << '\n';
    lowlink[node] = preorder[node];
    long temp = weights[node];
    bool hasFwd = false;
    for(long edge : G[node]){
        if(edge == parent) continue;
        pair<long, long> res = dfs(edge, node);
        if(res.first < 0){
            temp += res.second;
            lowlink[node] = min(lowlink[node], lowlink[edge]);
            if(node != parent ? lowlink[edge] >= preorder[node] : hasFwd){
                // cout << node << ' ' << edge << ' ' << res.second << '\n';
                // ans = max(ans, res.second ^ (totalWeight - res.second - weights[node]));
                cutvertexes[node].push_back(res.second);
            }
            hasFwd = true;
        }
    }
    return {-1, temp};
}

int main(){
    ans = -1;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> weights[i];
        totalWeight += weights[i];
        preorder[i] = -1;
    }
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, 0);
    for(auto x : cutvertexes){
        long temp1 = 0, temp2 = 0;
        for(long y : x.second){
            temp1 ^= y;
            temp2 += y;

        }
        temp1 ^= (totalWeight - temp2 - weights[x.first]);
        ans = max(ans, temp1);
    }
    cout << ans << '\n';
    return 0;
}