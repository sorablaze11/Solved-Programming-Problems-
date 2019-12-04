class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0; 
        int r = grid.size(), c = grid[0].size();
        int dp[r][c] = {0};
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                dp[i][j] = grid[i][j];
                if(i && j) dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
                else if(i) dp[i][j] += dp[i - 1][j];
                else if(j) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[r - 1][c - 1];
    }
};