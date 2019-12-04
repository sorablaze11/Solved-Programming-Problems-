class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        r = len(obstacleGrid)
        c = len(obstacleGrid[0])
        if r == 0:
            return 0
        if obstacleGrid[0][0] == 1:
            return 0
        dp = [[0 for i in range(c)] for j in range(r)] 
        dp[0][0] = 1
        for i in range(1, r):
            if obstacleGrid[i][0] == 0:
                dp[i][0] = dp[i - 1][0]
        for i in range(1, c):
            if obstacleGrid[0][i] == 0:
                dp[0][i] = dp[0][i - 1]
        for i in range(1, r):
            for j in range(1, c):
                if obstacleGrid[i][j] == 0:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        return dp[r - 1][c - 1]