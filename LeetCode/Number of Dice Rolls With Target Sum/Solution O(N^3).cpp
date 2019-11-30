class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        long dp[target + 1][d + 1];
        for(int i = 0; i <= target; i++) for(int j = 0; j <= d; j++) dp[i][j] = 0;
        for(int i = 1; i <= f; i++) if(i <= target) dp[i][1] = 1;
        for(int j = 2; j <= d; j++){
            for(int i = 1; i <= target; i++){
                for(int k = 1; k <= f; k++){
                    if(i - k < 0) break;
                    // cout << i << ' ' << j << ' ' << k << '\n';
                    dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % 1000000007;
                }
            }
        }
        // for(int j = 0; j <= d; j++){
        //     for(int i = 0; i <= target; i++){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        return dp[target][d];
    }
};