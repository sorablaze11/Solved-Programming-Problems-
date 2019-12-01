class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        sort(coins.begin(), coins.end());
        int dp[amount + 1] = {0};
        for(int i = 0; i < coins.size(); i++){
            if(coins[i] <= amount) dp[coins[i]] += 1;
            for(int j = 0; j <= amount; j++){
                if(j - coins[i] < 0) continue;
                dp[j] += dp[j - coins[i]];
            }
            // for(int i = 0; i <= amount; i++) cout << dp[i] << ' ';
            // cout << '\n';
        }
        return dp[amount];
    }
};