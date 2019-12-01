class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        for(int i = 0; i <= amount; i++) dp[i] = 9999999;
        dp[0] = 0;
        for(int i = 0; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] < 0) continue;
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] < 9999999 ? dp[amount] : -1;
    }
};