 #include <bits/stdc++.h>
 using namespace std;

const int N = 3e5+10;
vector<int> G[N], cutvertexes;
int n, m, preorder[N], lowlink[N], cnt, u, v;
vector<pair<int, int> > bridges;

int dfs(int node, int parent){
    if(preorder[node] != -1){ // Backedge condition
        lowlink[parent] = min(lowlink[parent], preorder[node]);
        return lowlink[parent];
    }
    preorder[node] = cnt++; // Assigning a unique preorder no.
    lowlink[node] = preorder[node];
    bool hasFwd = false;

    for(int edge : G[node]){
        if(edge == parent) continue;
        if(dfs(edge, node) < 0){ // Is a forward Edge
            lowlink[node] = min(lowlink[node], lowlink[edge]);
            if(lowlink[edge] == preorder[edge]){ // Bridge checking condition
                bridges.push_back({node, edge});
            }
            if(node != parent ? lowlink[edge] >= preorder[node] : hasFwd){  // Is not root ? Is articulation point : Has multiple children
                cutvertexes.push_back(node);
            }
            hasFwd = true;
        }
    }
    return -1;
}

int main(){
    for(int i = 0; i < N; i++) preorder[i] = -1;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, 0);
    cout << "Bridges:\n";
    for(auto edge : bridges) cout << edge.first + 1 << ' ' << edge.second + 1 << '\n';
    cout << "\nAtriculation Points:\n";
    for(auto vertex : cutvertexes) cout << vertex + 1 << ' ';
    return 0;
}