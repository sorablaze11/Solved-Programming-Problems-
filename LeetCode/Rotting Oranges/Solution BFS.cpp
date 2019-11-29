class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int timeTaken = 0;
        int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
        queue<pair<int, int> > q;
        vector<vector<int> > done(grid.size(), vector<int>(grid[0].size(), -1));
        for(int rowNo = 0; rowNo < grid.size(); rowNo++){
            for(int colNo = 0; colNo < grid[rowNo].size(); colNo++){
                if(grid[rowNo][colNo] == 1 || grid[rowNo][colNo] == 0) continue;
                q.push({rowNo, colNo});
                done[rowNo][colNo] = 0;
                while(!q.empty()){
                    auto node = q.front();
                    // cout << node.first << ' ' << node.second << '\n';
                    q.pop();
                    for(int i = 0; i < 4; i++){
                        int x = node.first + dx[i];
                        int y = node.second + dy[i];
                        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size()) continue;
                        if(grid[x][y] == 2 || grid[x][y] == 0) continue;
                        if(done[x][y] != -1){
                            if(done[x][y] <= done[node.first][node.second] + 1) continue;
                        }
                        done[x][y] = done[node.first][node.second] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
        for(int rowNo = 0; rowNo < grid.size(); rowNo++){
            for(int colNo = 0; colNo < grid[rowNo].size(); colNo++){
                if(grid[rowNo][colNo] == 1 && done[rowNo][colNo] == -1) return -1;
                if(grid[rowNo][colNo] == 1) timeTaken = max(timeTaken, done[rowNo][colNo]);
            }
        }
        
        return timeTaken;
    }
};