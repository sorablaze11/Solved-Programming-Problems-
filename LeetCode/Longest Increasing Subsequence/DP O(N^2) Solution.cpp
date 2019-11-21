class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = 0;
        vector<int> dp(nums.size());
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        for(int x : dp) ans = max(ans, x);
        return ans + 1;
    }
};