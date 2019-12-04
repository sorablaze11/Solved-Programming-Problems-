class Solution {
public:
    long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0) return 0;
        int r = obstacleGrid.size(), c = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        long dp[r][c];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i < r; i++) if(obstacleGrid[i][0] == 0) dp[i][0] = dp[i - 1][0];
        for (int i = 1; i < c; i++) if(obstacleGrid[0][i] == 0) dp[0][i] = dp[0][i - 1];
        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                if(obstacleGrid[i][j] == 0) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[r - 1][c - 1];
    }
};