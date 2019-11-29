class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        vector<vector<int>> done(grid.size(), vector<int>(grid[0].size()));
        int componentCnt = 0;
        queue<pair<int, int> > q;
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
        for(int rowNo = 0; rowNo < grid.size(); rowNo++){
            for(int colNo = 0; colNo < grid[rowNo].size(); colNo++){
                if(grid[rowNo][colNo] == '0') continue;
                if(done[rowNo][colNo]) continue;
                componentCnt++;
                done[rowNo][colNo] = componentCnt;
                q.push({rowNo, colNo});
                while(!q.empty()){
                    auto node = q.front();
                    q.pop();
                    for(int i = 0; i < 4; i++){
                        int x = node.first + dx[i];
                        int y = node.second+ dy[i];
                        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || done[x][y] || grid[x][y] == '0') continue;
                        done[x][y] = componentCnt;
                        q.push({x, y});
                    }
                }
            }
        }        
        return componentCnt;
    }
};