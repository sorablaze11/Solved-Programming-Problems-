class Solution {
public:
    vector<int> G[100010];
    int preorder[100010], lowlink[100010], cnt = 0;
    
    int dfs(int node, int parent, vector<vector<int> > &bridges){
        if(preorder[node] != -1){
            lowlink[parent] = min(lowlink[parent], preorder[node]);
            return lowlink[parent];
        }
        preorder[node] = cnt++;
        lowlink[node] = preorder[node];
        for(int edge : G[node]){
            if(edge == parent) continue;
            if(dfs(edge, node, bridges) < 0){
                lowlink[node] = min(lowlink[node], lowlink[edge]);
                if(lowlink[edge] == preorder[edge]){
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(edge);
                    bridges.push_back(temp);
                }
            }
        }
        return -1;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int> > bridges;
        for(int i = 0; i < 100010; i++) preorder[i] = -1;
        for(int i = 0; i < connections.size(); i++){
            G[connections[i][0]].push_back(connections[i][1]);
            G[connections[i][1]].push_back(connections[i][0]);
        }
        dfs(0, 0, bridges);
        return bridges;
    }
};