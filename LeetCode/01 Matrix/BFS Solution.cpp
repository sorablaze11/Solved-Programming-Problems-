class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int> > ret(n, vector<int>(m, -1));
        queue<pair<int, int> > q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0) ret[i][j] = 0, q.push({i, j});
            }
        }
        while(!q.empty()){
            pair<int, int> node = q.front();
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int dx = dir[i][0], dy = dir[i][1];
                if(node.first + dx < n && node.first + dx >= 0 && node.second + dy < m && node.second + dy >= 0 && ret[node.first + dx][node.second + dy] == -1)
                {
                    ret[node.first + dx][node.second + dy] = ret[node.first][node.second] + 1;
                    q.push({node.first + dx, node.second + dy});
                }
            }
        }
        return ret;
    }
};